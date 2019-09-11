#include <iostream>
#include <vector>

using namespace std;

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
    static int _index;
};

inline void Triangular_iterator::check_integrity() const {
  if (_index >= Triangular::_max_elems)
    throw iterator_overflow();

  if (_index >= Triangular::_elems.size())
    Triangular::gen_elements(_index+1);
}

// 运算符的定义方式可以像member function一样
inline int Triangular_iterator::operator*() const {
  check_integrity();
  return Triangular::_elems[_index];
}

/*
// 运算符的定义方式也可以像non-member function一样
inline int operator*(const Triangular_iterator &rhs) {
  // 注意，如果这是个non-member function，就不具备访问non-public member的权利
  // 所以这里访问的rhs成员都需要是public的或者该function是该class的friend
  rhs.check_integrity();
  return Triangular::_elems[rhs._index];
}
*/

inline bool Triangular_iterator::operator==(const Triangular_iterator &rhs) const {
  return _index == rhs._index;
}

inline bool Triangular_iterator::operator!=(const Triangular_iterator &rhs) const {
  return !(*this == rhs);
}

// 前置版本
inline Triangular_iterator& Triangular_iterator::operator++() {
  ++_index;
  check_integrity();
  return *this;
}

// 后置版本
inline Triangular_iterator Triangular_iterator::operator++(int) {
  Triangular_iterator tmp = *this;
  ++_index;
  check_integrity();
  return tmp;
}

class Triangular {
  public:
    typedef Triangular_iterator iterator;
    friend class Triangular_iterator;
    
    Triangular_iterator begin() const {
      return iterator(_beg_pos);
    }

    Triangular_iterator end() const {
      return iterator(_beg_pos+_length);
    }

    Triangular(int a, int b=8);

    Triangular(const Triangular &rhs);

    int length() const;

    Triangular& operator=(const Triangular &rhs);

  private:
    int _beg_pos;
    int _length;
    static const int _max_elems = 1024;
    static vector<int> _elems;
};

int main(int argc, char const *argv[])
{
  Triangular trian(1, 8);
  Triangular::iterator it = trian.begin(),
                       end_it = trian.end();
  while (it != end_it) {
    cout << *it << ' ';
    ++it;
  }  
  return 0;
}
