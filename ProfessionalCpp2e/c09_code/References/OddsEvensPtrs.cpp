#include <iostream>
using namespace std;

void printIntArr(const int arr[], int size)
{
  for (int i = 0; i < size; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
} 

void separateOddsAndEvens(const int arr[], int size, int** odds, int* numOdds,
          int** evens, int* numEvens)
{
  // Count the number of odds and evens
  *numOdds = *numEvens = 0;
  for (int i = 0; i < size; i++) {
    if (arr[i] % 2 == 1) {
      (*numOdds)++;
    } else {
      (*numEvens)++;
    }
  }

  // Allocate two new arrays of the appropriate size
  *odds = new int[*numOdds];
  *evens = new int[*numEvens];

  // Copy the odds and evens to the new arrays
  int oddsPos = 0, evensPos = 0;
  for (int i = 0; i < size; i++) {
    if (arr[i] % 2 == 1) {
      (*odds)[oddsPos++] = arr[i];
    } else {
      (*evens)[evensPos++] = arr[i];
    }
  }
}  

int main()
{
  int unSplit[10] = {1, 2, 3, 4, 5, 6, 6, 8, 9, 10};
  int *oddNums, *evenNums;
  int numOdds, numEvens;

  separateOddsAndEvens(unSplit, 10, &oddNums, &numOdds, &evenNums, &numEvens);
  printIntArr(oddNums, numOdds);
  printIntArr(evenNums, numEvens);

  return 0;
}
