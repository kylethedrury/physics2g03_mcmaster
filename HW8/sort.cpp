#include <iostream>
#include "sort.h"

using namespace std;

 void InsertionSort (float A[], int n){
 cout << "Running Insertion Sort\n";

 float key;
 int i, j; 
   for (i=1;i<n;i++){
     key = A[i];
     j = i-1; 
     
     while (j >= 0 && A[j] > key){
       A[j+1] = A[j];
       j = j-1;
       }
      
     A[j+1] = key;	 
   }

 }

 int partition (float A[], int n){
 float a;

 float x = A[n-1];
 int i, j;

   for (j=0, i=0; j<=n-2; j++){
   
     if (A[j]<=x){
       a = A[j];
       A[j] = A[i];
       A[i] = a;

       i = i+1;

     }

   }

   a = A[i];
   A[i] = A[n-1];
   A[n-1] = a;
 
   return i;

 }

 void QuickSort (float A[], int n){
    
   int q;

   if (n>1){
     q = partition (A, n);
     QuickSort (A, q);
     QuickSort (A+q+1,n-1-q);
   }

 }
     
     




