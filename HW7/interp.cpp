// This is where our functions 'interpolate' and 'lookup' are defined. They are compiled and included in a headerfile interp.h so that interptest.cpp and testlookup.cpp can access and use them.

#include <iostream>
#include <cmath>

using namespace std; 

float interpolate (float x2, float y2, float x1, float y1, float xmid){
  if (x2==x1 && y2==y1){
    cout << "Points cannot be the same.\n";
    return 0;
    }
  if (y2==y1){
    cout << "Slope is 0.\n";
    return 0;
    }
  if (x2==x1){
    cout << "These points describe a vertical line.\n";
    return 0;
    }
  
  return (((y2-y1)/(x2-x1))*xmid) + (y2 - (((y2-y1)/(x2-x1))*x2));
}


float lookup (float x_array[], float y_array[], float xmid, float endpoint, int n){
 
  int i;
  float y;

  if (xmid<0 or xmid>endpoint){
     cout << "xmid must be within bounds of array.\n";
     return 0;
     }
  for (i=0;i<n-2;i++){
     if (x_array[i]<=xmid && xmid<=x_array[i+1]){
     cout << xmid << " is between " << x_array[i] << " and " << x_array[i+1] << " .\n";
     break;
     }
    }

  return y = interpolate (x_array[i+1], y_array[i+1], x_array[i], y_array[i], xmid);
    cout << y << endl << endl;
  }

   

  
   
