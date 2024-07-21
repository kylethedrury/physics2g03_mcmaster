#include <cmath>
#include <iostream> 
#include "cpgplot.h"
using namespace std; 

//Declare dydt 

double dydt(double y, double a) {
  return a*(1-y);
 } 

int main()
{
cout << dydt(0.5,0.04); 
cout << endl;
cout << dydt(0.2,0.4);
cout << endl;

return 0;
}


