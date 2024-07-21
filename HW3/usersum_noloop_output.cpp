#include <iostream>

using namespace std;

int main()
{
  int n;
  int total = 0;

  cout << "Enter a number to sum to.\n"; 
  cin >> n; 

  for(int i=1; i<=n; i++)
  {
     total = total + i;
     
  };

     cout << "The value used was " << n << " and the total is " << total << ".\n";
     return 0;
}
