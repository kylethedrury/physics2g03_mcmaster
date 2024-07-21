#include <iostream>
#include <cstdlib>     
#include "sort.h"

using namespace std; 

int main() {
// A Program for testing sorting algorithms
// Filename: testsort.cpp Src: JWW 11/2022
 
  const int n = 100;
  int i, isort;
  float A[n];

  for (i=0;i<n;i++) {
   A[i] = float(rand())/RAND_MAX;  // generate a random real number between 0 and 1
   // A[i] = i; // generate a list of already ordered numbers
   // A[i] = n-i+1; //generate a list of numbers ordered backward
  }
  for (i=0;i<n;i++) {
  cout << A[i] << " ";
  }
  cout << " unsorted\n";

  cout << "Enter 1 for insertion sort, 2 for partition test, 3 for quick sort\n";
  cin >> isort;

  switch (isort) {
  case 1:
      InsertionSort (A, n);
    break;
  case 2:
      partition (A, n);
    break;
  case 3:
      QuickSort (A,n);
    break;
  default:
    cout << isort << " is not an allowed choice\n";
  }

  for (i=0;i<n;i++) {
    cout << A[i] << " ";
    }
    cout << " sorted\n"; 
}


