constexpr int getArraySize() { return 32; }

int main()
{
    int myArray[getArraySize()];    // OK with C++11
    return 0;
}
