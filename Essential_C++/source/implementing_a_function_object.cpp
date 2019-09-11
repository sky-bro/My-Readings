class LessThan
{
private:
  int _val;
public:
  LessThan( int val ) : _val(val) { }
  int comp_val() const {return _val;}
  void comp_val(int nval) {_val = nval;}

  bool operator() (int _value) const {return _value < _val;}
  void f(){ 
    // cout<<"ok\n";
  };
};

int main(int argc, char const *argv[])
{
  void (LessThan::*ff)() = &LessThan::f;
  LessThan lt(2);
  LessThan *plt = &lt;
  (plt->*ff)();
  (lt.*ff)();
  return 0;
}
