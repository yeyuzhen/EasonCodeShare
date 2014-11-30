class X {};
class Y {};

int main()
{
  X x;
  Y y;

  X* xp = &x;
  Y* yp = &y;

  // Need reinterpret cast to perform pointer conversion from unrelated classes
  // static_cast doesn't work
  xp = reinterpret_cast<X*>(yp);
  
  // Need reinterpret cast to perform pointer conversion from unrelated pointers
  void* p = reinterpret_cast<void*>(xp);
  xp = reinterpret_cast<X*>(p);

  // Need reinterpret cast to perform reference conversion from unrelated
  // classes --  static_cast doesn't work
  X& xr = x;
  Y& yr = reinterpret_cast<Y&>(x);

  return 0;
}
