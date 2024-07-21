#include <iostream>

using namespace std;

int main()
{
  float a,b,c,d,m,e; 

  cout << "Please input x1 and y1.\n";
  cin >> b >> d;

  cout << "Please input x2 and y2.\n";
  cin >> a >> c;

  m = ((c-d)/(a-b));
  e = (d-(m*b));

  cout << "The slope m is " << m << " and the y-intercept is " << e << " .\n";
  return 0;
}

