#include <cmath>
#include "cpgplot.h"

int main()
{
  //-----------------------------------------------------------------------
  // This program uses pgplot to plot y = cos(x)
  //-----------------------------------------------------------------------
  const int nintervals = 40;
  float x[nintervals+1], y[nintervals+1];
  float pi, dx;
  int i;

  // Open a plot window
  if (!cpgopen("/XWINDOW")) return 1;

  // Set-up plot axes
  // M_PI is defined in cmath
  cpgenv(0.,2*M_PI,-1.,1.,0,1);
  // Label axes
  cpglab("x", "y", "y=cos(x)");

  dx = 2*M_PI/nintervals;

  // Change plot colour to colour 4 (BLUE)
  cpgsci(4);

  // Compute the function at the points
  for (i=0;i<=nintervals;i++) {
    x[i] = dx*i;
    y[i] = cos(x[i]);
  }

  // Plot the curve  
  cpgline(nintervals+1,x,y);

  // Pause and then close plot window
  cpgclos();
}
