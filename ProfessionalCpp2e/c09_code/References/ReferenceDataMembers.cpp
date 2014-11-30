class MyClass
{
    public:
        MyClass(int& ref) : mRef(ref) {}
    protected:
        int& mRef;
};

int main()
{
    int i = 123;
    MyClass m(i);
    return 0;
}
