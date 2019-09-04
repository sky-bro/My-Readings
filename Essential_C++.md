## 第1章 C++编程基础

* 文件读写fstream
* Array和Vector

## 第2章 面向过程的编程风格

* 函数：
  * 指针与引用，按值和按地址传递，
  * 动态内存管理
  * 默认参数，
  * 局部静态对象，local static object
  * inline函数：定义直接放在声明中（头文件中）
  * 函数重载
  * 函数模板
  * 函数指针int (*f)()
  * 函数指针数组int (*f[])()
  * extern

## 第3章 泛型编程风格

* STL主要由两种组件构成
  * 一是容器，包括vector、list、set、map等类
  * 二是用以操作容器的泛型算法generic algorithm。包括find()、sort()、replace()、merge()等
  
* 容器
  * 顺序性容器sequential container，主要进行迭代iterate操作
    * vector
    * list
    * deque（读作deck），和vector类似都以连续内存存储元素，但对于最前端的插入删除效率也高，标准库中的queue便是以deque实现
    * 定义顺序性容器对象有5种方式
    * push_back(), push_front(), pop_back(), pop_front(), front(), back()
    * xxxfront只对list和deque
    * push_back和push_front都属于特殊化的insert插入操作
    * insert操作有4种变形
    * pop_back和pop_front都属于特殊化的erase删除操作
    * erase操作有2种变形，返回被删除之最后一个元素的下一位置
  * 关联容器associative container
    * map，key/value
    * set，仅含key
  * 所有容器（以及string类）共通操作
    * ==, !=, =
    * empty()
    * size()
    * clear()
    * begin(), end()
    * insert()
    * erase()
  
* 泛型算法
  * 通过function template达到与操作**对象的类型**相互独立
  
  * 而通过不直接在容器身上操作而借由如iterate进行迭代，达到与**容器**无关
  
  * 总共有超过60个泛型算法（几近75个）
    * 搜索算法
    * 排序及次序整理算法
    * 复制、删除、替换算法
    * 关系算法
    * 生成与质变算法
    * 数值算法
    * 集合算法
    
  * 使用泛型算法
    
    * 首先包含algorithm头文件
    
  * 如何设计一个泛型算法
  
  * Function Object
  
    * 标准库预先定义好了许多function object，是某种class的实例对象，这类class对function call运算符做了重载操作，如此一来可使function object被当成一般函数来使用。
  
    * 这样做我们可以使call运算符成为inline，从而消除“通过函数指针来调用函数”时需付出的额外代价
  
    * 3大类
  
      * 6个算术运算arithmetic
        * plus\<type\>, minus\<type\>, negate\<type\>, multiplies\<type\>, divides\<type\>, modules\<type\>
      * 6个关系运算relational
        * less\<type\>, less_equal\<type\>, greater\<type\>, greater_equal\<type\>, equal_to\<type\>, not_equal_to\<type\>
      * 3个逻辑运算logical
        * logical_and\<type\>, logical_or\<type\>, logical_not\<type\>
  
    * 使用
  
      * 首先包含头文件: `#include <functional>`
  
      * ```c++
        sort(vec.begin(), vec.end(), greater<int>());
        // greater<int>()会产生一个未命名的class template object
        ```
  
  * Function Object Adapter
  
    * **binder adapter**（绑定适配器）会将function object的参数绑定至某特定值，使binary二元function object转化为unary一元function object
  
    * 标准库提供两个binder adapter
  
      * **bind1st** 将指定值绑定至第一操作数
      * **bind2st** 将指定值绑定至第二操作数

    * ```c++
      int a[3] = {2, 3, 4};
      cout<<*find_if(a, a+3, bind2nd(less<int>(), 3))<<endl; // 2
      ```
      
    * 另一种adapter是所谓的**negator**，它会对function object的真伪值取反。
  
      * **not1**可对unary function object的真伪值取反，
      * **not2**可对binary function object的真伪值取反
  
    * ```c++
      int a[3] = {2, 3, 4};
      cout<<*find_if(a, a+3, not1(bind2nd(less<int>(), 3)))<<endl; // 3
      ```
  
    * 
  
  * find()、find_if()
  
* iterator泛型指针
  * 嵌套类型与iterator class
  * 函数指针与function object
  
* 使用Map

  * map被定义为一对数值，key, value pair
  * 使用
    * 包含头文件：`#include <map>`
    * 下标访问一个原不存在的key会自动添加该key，并配以默认value
    * 可以通过find判断key是否存在，返回iterator，指向该pair或者end
    * 也可通过count返回特定项在map中的个数，任何key在map中当然只能有一份，但在multimap中可以有多份

* 使用Set

  * 由一群key组成，任何key值，set只能存储一份，multiset可以多份，同样可以用count判断key是否存在
  * 默认情形下，set元素皆以所属类型默认的less-than运算符进行排列
  * 泛型算法有不少和set相关的算法
    * set_intersection()
    * set_union()
    * set_difference()
    * set_symmetric_difference()

* 如何使用Iterator Inserter

  * **insertion adapter**可以让我们避免使用容器的assignment运算符，这样在我们copy元素时就不用纠结目的容器的大小
    * back_inserter -- push_back()
    * inserter -- insert()
    * front_inserter -- push_front()

* 使用iostream Iterator

  * 包含头文件 `#include <iterator>`

  * ```c++
    int a[4];
    istream_iterator<int> is(cin);
    istream_iterator<int> eof;
    ostream_iterator<int> os(cout, " ");
    // copy(is, eof, os);
    copy(is, eof, a);
    copy(a, a+sizeof(a)/sizeof(int), os);
    ```

## 第4章 基于对象的编程风格

<<<<<<< HEAD
* class名称被视为一个类型名称，Class Object的初始化方式有很多种

  * ```c++
    #include <string>
    #include <vector>
    string pooh[4] = {"winnie", "robin", "eeyore", "piglet"};
    string dummy("dummy");
    vector<string> svec1(4);
    vector<string> svec2(4, dummy);
    vector<string> svec3(pooh, pooh+4);
    ```

* 每个class都会提供一组操作函数

  * 具名函数
  * 重载运算符：如equality和assignment运算符

* 一般class由两部分组成：public和private

  * private member只能在member function或是class **friend**内被访问

* class用户通常不关心实现细节，身为一个用户，只利用其公开接口来进行编程

* 实现一个string stack class

  * ```c++
    // Stack Class的起始定义
    class Stack {
      public:
        bool push(const string&);
        bool pop(string &elem);
        bool peek(string &elem);
        
        bool empty();
        bool full();
        
        int size() { return _stack.size(); }
        
      private:
        vector<string> _stack;
    };
    ```

  * 如果函数在class主体内定义，这个member function会自动地被视为inline函数

  * ```c++
    // 使用Stack Class Object
    void fill_stack(Stack &stack, istream &is = cin)
    {
        string str;
        while (is >> str && ! stack.full())
            stack.push(str);
        
        cout << "Read in " << stack.size() << " elements\n";
    }
    ```

  * ```c++
    // class主体外定义inline member function，和上面的class定义同放在Stack.h文件
    inline bool
    Stack::empty()
    {
        return _stack.empty();
    }
    
    inline bool Stack::full()
    {
        return _stack.size() == _stack.max_size();
    }
    ```

  * ```c++
    // Stack member function的定义，放在Stack.cpp文件
    bool
    Stack::pop(string &elem)
    {
        if (empty())
            return false;
        
        elem = _stack.back();
        _stack.pop_back();
        return true;
    }
    
    bool Stack::peek(string &elem)
    {
        if (empty())
            return false;
        
        elem = _stack.back();
        return true;
    }
    
    bool Stack::push(const string &elem)
    {
        if (full())
            return false;
        
        _stack.push_back(elem);
        return true;
    }
    ```

  * 对于inline函数而言，定义于class主体内或主体外，并没有什么分别， 然而就像non-member inline function一样，它也应该被放在头文件中。

  * non-inline (member) function 应该在程序代码文件中定义，该文件通常和class同名

* 添加构造函数Constructor和析构函数Destructor

  * 

## 第5章 面对对象编程风格

## 第6章 以template进行编程

* 被参数化的类型

## 第7章 异常处理
