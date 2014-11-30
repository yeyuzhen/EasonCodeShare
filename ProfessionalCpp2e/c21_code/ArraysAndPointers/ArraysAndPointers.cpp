void doubleInts(int* theArray, size_t inSize)
{
	for (size_t i = 0; i < inSize; i++) {
		theArray[i] *= 2;
	}
}

/*
void doubleInts(int theArray[], size_t inSize)
{
	for (size_t i = 0; i < inSize; i++) {
		theArray[i] *= 2;
	}
}
*/
int main()
{
	size_t arrSize = 4;
	int* heapArray = new int[arrSize];
	heapArray[0] = 1;
	heapArray[1] = 5;
	heapArray[2] = 3;
	heapArray[3] = 4;
	doubleInts(heapArray, arrSize);
	delete [] heapArray;
	heapArray = nullptr;

	int stackArray[] = {5, 7, 9, 11};
	arrSize = sizeof(stackArray) / sizeof(stackArray[0]);
	doubleInts(stackArray, arrSize);
	doubleInts(&stackArray[0], arrSize);

	return 0;
}
