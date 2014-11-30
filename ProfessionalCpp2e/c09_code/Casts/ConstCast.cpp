extern void ThirdPartyLibraryMethod(char* str);

void f(const char* str)
{
    ThirdPartyLibraryMethod(const_cast<char*>(str));
}

int main()
{
  char str[100];
  f(str);

  return 0;
}
