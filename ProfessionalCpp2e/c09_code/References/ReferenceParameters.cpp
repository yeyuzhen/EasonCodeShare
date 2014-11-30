void swap(int& first, int& second)
{
  int temp = first;
  first = second;
  second = temp;
}

int main()
{
  int x = 5, y = 6;
  swap(x, y);

  //  swap(3, 4); // DOES NOT COMPILE

  int *xp = &x, *yp = &y;
  swap(*xp, *yp);

  return 0;
}
