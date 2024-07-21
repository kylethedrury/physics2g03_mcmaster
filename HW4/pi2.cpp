#include <iostream>
#include <iomanip>
using namespace std;

int main() 
{
// Program to estimate Pi to a given accuracy
// Filename pi.cpp Src: JWW 2022

  int n;
  float term, cutoff, sum, pi;

  n = 1;
  term = 1;
  sum = term;
  
  cout << "Welcome to the pi estimator program.\n";

  cout << "What is the value of the smallest term you would like to estimate to?\n";
  cin >> cutoff;

  if (cutoff<=0) {
    cout << "Input must be a positive, real number.\n";
    return 1;
    }

  for (int i=1;;i++) {
    n++;
    term = term*(n-1)/((2*n)-1); 
    sum = sum + term;
    if (term <= cutoff) break;
  }

  pi = 2*sum;

  cout << std::setprecision(20) << "Our pi estimate is " << pi << ".\n";
  cout << "This is less than pi by " << (-1)*(pi-3.141592653589793238462643383279502884197169399375105820974944e0) << ".\n";
  cout << "The smallest term included was " << term << ".\n"; 
  cout << "The number of terms summed was " << n << ".\n";
}
