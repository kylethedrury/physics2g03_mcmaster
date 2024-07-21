// This program uses interpolate to take any two points, and a point in between them, and determines the y value of that middle x based on interpolation. 

#include <iostream>
#include <cmath>
#include <cpgplot.h>
#include "interp.h"

using namespace std;

 int main()
 {
 float x2, y2, x1, y1, xmid, y=0.;

 cout << "Please specify (x2,y2) and (x1,y1) in the preceding order.\n";
 cin >> x2 >> y2 >> x1 >> y1;
 cout << "The first point is given by x and y (" << x2 << "," << y2 << ") and the second point is given by (" << x1 << "," << y1 << ").\n";
 cout << "What is the intermediate x value?\n";
 cin >> xmid;

 y = interpolate (x2, y2, x1, y1, xmid);

 cout << y;
 cout << endl;

 return 0;
 }

