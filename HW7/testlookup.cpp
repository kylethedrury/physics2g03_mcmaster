// This is the program that uses look up to locate a point and determine which two points it is between (these points are described by x_array and y_array). 

#include <iostream>
#include <fstream>
#include "interp.h"

using namespace std;

int main() {

  int i, n;

  float y, xmid, endpoint;

  /*
  float x_array[] = {0.,1.,2.,3.,4.};
  float y_array[] = {9.,9.37,10.48,12.33,14.92};

  float endpoint = x_array[4];
  */

  ifstream inputfile;
  inputfile.open("input.dat");
  inputfile >> n;
  float x_array[n], y_array[n];

  for(i=0;i<=n-1;i++){
    inputfile >> x_array[i];
    inputfile >> y_array[i];
   }

  endpoint = x_array[n-1];

  cout << "Specify xmid.\n";
  cin >> xmid; 
  cout << endl;

  y = lookup (x_array, y_array, xmid, endpoint, n);
  cout << y << endl;

  return 0;
} 
