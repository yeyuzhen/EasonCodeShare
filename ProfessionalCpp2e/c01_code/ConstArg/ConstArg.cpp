void mysteryFunction(const char* myString);

int main()
{
    char* myString = new char[2];
    myString[0] = 'a';
    myString[1] = '\0';
    mysteryFunction(myString);
    return 0;
}

void mysteryFunction(const char* myString)
{
    myString[0] = 'b';  // Will not compile.
}
