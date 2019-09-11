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

  * Constructor可以被重载，Destructor不可
  
  * Destructor没有返回值，没有参数
  
  * ```c++
    class Triangular {
      public:
        // 一组重载的constructor
        Triangular(); // default constructor
        Triangular(int len);
        Triangular(int len, int beg_pos);
        
        // ...
    };
    ```
  
  * ```c++
    Triangular t; // 调用default constructor
    Triangular t2(10, 3);
    Triangular t3 = 8; // 注意，这里究竟是调用Constructor还是assignment operator呢，答案是（单一参数的）Constructor
    Triangular t4(); // 这里将t4定义为一个函数，正确声明方式应该和上面的t一样 Triangular t4;
    ```
  
  * default Constructor不需要任何参数，有两种情况
  
    1. 不接受任何参数
    2. 更常见的，为每个参数提供了默认值`Triangular(int len = 1, int bp = 1);`
  
  * Member Initialization List （成员初始化列表）
  
    * 主要用于将参数传给member class object的constructor
  
  * 合适需要定义Destructor而何时不需要
  
* copy Constructor

  * 默认情形下，当我们以某个class object作为另一个object的初值，class data member会被依次复制
  * 如果需要改变这种成员逐一初始化的形式，我们应该提供copy Constructor， 而且也还应该提供copy assignment operator

* 何谓mutable和const

  * 在member function身上标注const，以此告诉编译器，这个member function不会改变class object的内容
  * 将某个成员变量标记为mutable，那么对其改变将不会影响object的constness

* this指针

* static class member

  * 对于class而言，static data member只有唯一一份实体，因此我们必须在程序代码文件中提供其清楚的定义
  * 在class member function中访问static data member，其方式犹如访问一般non-static数据成员
  * 对于const static member，可以在其声明时为其明确指定初值（class内给初值或者程序代码文件中给初值，只能一处给）
  * member function 只有在不访问任何non-static member的情况下才可以被声明为static
  * class内部声明static，程序代码文件中无须再加static关键字

* 打造一个Iterator Class

  * 必须提供以下操作方式
  
    * ```c++
      Triangular trian(1, 8);
      Triangular::iterator it = trian.begin(),
      end_it = trian.end();
      while (it != end_it) {
          cout << *it << ' ';
          ++it;
      }  
      ```
  
  * 即必须为此iterator class定义!=、*、++等运算符
  
    * ```c++
      class Triangular_iterator {
          public:
          Triangular_iterator(int index): _index(index-1){}
          bool operator==(const Triangular_iterator&) const;
          bool operator!=(const Triangular_iterator&) const;
          int operator*() const;
          Triangular_iterator& operator++(); // 前置(prefix)版
          Triangular_iterator operator++(int); // 后置(postfix)版
          private:
          void check_integrity() const;
          int _index;
      }
      ```
  
    * Triangular_iterator维护一个索引值，用以索引Triangular中用来存储数列元素那个static data member，也就是_elems。要达到这个目的，Triangular必须赋予Triangular_iterator的member function特殊的访问权限（friend机制）
  
    * 任何运算符如果和另一个运算符性质相反，我们通常会以后者实现出前者，例如
  
      * ```c++
        inline bool Triangular_iterator::operator!=(const Triangular_iterator &rhs) const {
          return !(*this == rhs);
        }
        ```
  
  * 运算符重载规则
  
    * 不可以引入新的运算符。除了`. * :: ?:`四个运算符，其它的运算符皆可被重载
    * 运算符的操作数个数不可改变
    * 运算符的优先级不可改变
    * 运算符的参数列表中，必须至少有一个参数为class类型，也即我们无法为non-class类型重新定义其原已存在的运算符
  
  * 定义运算符的两种风格/方式
  
    * ```c++
      // 运算符的定义方式可以像member function一样
      inline int Triangular_iterator::operator*() const {
        check_integrity();
        return Triangular::_elems[_index];
      }
      ```
  
    * ```c++
      // 运算符的定义方式也可以像non-member function一样
      inline int operator*(const Triangular_iterator &rhs) {
        // 注意，如果这是个non-member function，就不具备访问non-public member的权利
        // 所以这里访问的rhs成员都需要是public的或者该function是该class的friend
        rhs.check_integrity();
        return Triangular::_elems[rhs._index];
      }
      ```
  
  * `check_integrity()` member function可以确保`_index`不大于`_max_elems`，并确保`_elems`存储了必要的元素
  
    * ```c++
      inline void Triangular_iterator::check_integrity() const {
        if (_index >= Triangular::max_elems)
          throw iterator_overflow();
        // 必要时扩展vector的容量
        if (_index >= Triangular::_elems.size())
          Triangular::gen_elements(_index+1);
      }
      ```
  
  * 下面提供递增运算符`++`的前置和后置两个版本
  
    * ```c++
      // 前置版本
      inline Triangular_iterator& Triangular_iterator::operator++() {
        ++_index;
        check_integrity();
        return *this;
      }
      ```
  
    * ```c++
      // 后置版本
      inline Triangular_iterator Triangular_iterator::operator++(int) {
        Triangular_iterator tmp = *this;
        ++_index;
        check_integrity();
        return tmp;
      }
      ```
  
    * **编译器会自动为后置版产生一个int参数（其值必为0）**
  
  * 接下来为Triangular提供一组`begin()/end()` member function，需要用到嵌套类型nested type
  
    * ```c++
      class Triangular {
        public:
          typedef Triangular_iterator iterator;
          
          Triangular_iterator begin() const {
            return iterator(_beg_pos);
          }
      
          Triangular_iterator end() const {
            return iterator(_beg_pos+_length);
          }
          // ...
      
        private:
          int _beg_pos;
          int _length;
          // ...
      };
      ```
  
    * 如果将iterator嵌套放在每个提供iterator抽象概念的class内，我们就可以提供有着相同名称的多个定义，但是这样的声明语法有些复杂**？有啥复杂**
  
      * ```c++
        Fibonacci::iterator fit = fib.begin();
        Pell::iterator pit = pel.begin();
        ```
  
* 合作关系必须建立在友谊的基础上

  * friend function
  * friend class
  
* 实现一个copy assignment operator

  * copy constructor 和 copy assignment operator都要实现

* 实现一个function object

  * 提供有function call运算符的class
  
  * function call 运算符可以接受任意个数的参数
  
  * ```c++
    class LessThan
    {
    private:
      int _val;
    public:
      LessThan( int val ) : _val(val) { }
      int comp_val() const {return _val;}
      void comp_val(int nval) {_val = nval;}
    
      bool operator() (int _value) const {return _value < _val;}
    };
    ```
  
* 重载iostream运算符

  * ```c++
    ostream& operator<<(ostream &os, const Triangular &rhs)
    {
    	os << "( " << rhs.beg_pos() << ", " << rhs.length() << " )";
        rhs.display(rhs.length(), rhs.beg_pos(), os);
        return os;
    }
    ```

  * 不能把output运算符设计为member function

* 指针，指向Class Member Function

  * ```c++
    int main(int argc, char const *argv[])
    {
      void (LessThan::*ff)() = &LessThan::f;
      LessThan lt(2);
      LessThan *plt = &lt;
      (plt->*ff)();
      (lt.*ff)();
      return 0;
    }
    
    ```

* 

## 第5章 面对对象编程风格



## 第6章 以template进行编程

* 被参数化的类型

## 第7章 异常处理