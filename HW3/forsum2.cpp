#include <iostream>

using namespace std;

int main()
{
  int total = 0;

  for(int i=1; i<=10; i++)
  {
     total = total + i;
     cout << "i =" << i << endl;
     cout << "total = " << total << endl; 
  }

     cout << total << endl;
     return 0;
}
