#include <iostream> 
#include <cmath>
#include <cpgplot.h>
using namespace std;

int main()

{
  //-----------------------------------------------------------------------
  // This program uses pgplot to plot y = 1-2x+(3x^2)-(x^3)
  //-----------------------------------------------------------------------

  //-----------------------------------------------------------------------
  // The exact derivative dy/dx = -2+6x-3x^2
  // The integral = x - x^2 + x^3 - (0.25*x^4)
  // Function is green, approx derivative is red, exact derivative is blue, exact integral is pink, approx integral is orange
  //-----------------------------------------------------------------------

  // Initial Set-up:
  int nintervals; 
  int i;

  cout << "Pick N number of intervals.\n";
  cin >> nintervals;
  cout << endl;
  
  float dx = 1./nintervals;
  float x[nintervals+1], y[nintervals+1], dydx_approx[nintervals+1], dydx_exact[nintervals+1], integral_approx[nintervals+1], integral_exact[nintervals+1];

  cout << "The interval size is " << dx << " .\n";;
  cout << endl;

  // Open a plot window
  if (!cpgopen("/XWINDOW")) return 1;

  // Set-up plot axes
  cpgenv(0.,1.,-1.,1.,0,1);

  // Label axes
  cpglab("x", "y", "y=1+2x+(3x^2)-(x^3)");

 
  // Compute the function, its derivative, approximate derivative, approximate integral, and exact integral at the points and graph the curves. These equations are given.
  for (i=0;i<=nintervals;i++) {
    x[i] = dx*i;
    y[i] = 1. - (2.*x[i]) + (3.*pow(x[i],2.)) - pow(x[i],3.);
    dydx_exact[i] = -2. + 6.*x[i] - 3.*pow(x[i],2);
    integral_exact[i] = x[i] - pow(x[i],2.) + pow(x[i],3.) - 0.25*pow(x[i],4.);
  }

 // Compute the approximate derivative for the graph with the given code and setting the end boundary to 1
  dydx_approx[nintervals]=1;
  for (i=0;i<=nintervals-1;i++) {
    dydx_approx[i] = (y[i+1]-y[i])/dx;
  }

  // Error calculations for approximate derivative; ersq is the error squared
  float errorD, error_sumD, error_maxD, ersqD;

  error_sumD = error_maxD = 0;

   for (i=0;i<=nintervals-1;i++) {
    errorD = abs(dydx_approx[i]-dydx_exact[i]);
    ersqD = pow(errorD,2);
    error_sumD = error_sumD + ersqD;
    if (errorD > error_maxD)
     {error_maxD = errorD;}
  }

   cout << "The rms error on the approximate derivative is " << sqrt(error_sumD/nintervals) << " .\n";
   cout << "The max error on the approximate derivative is " << error_maxD << " .\n";
   cout << endl;

  // Compute the approximate integral by taking midpoints from 0 to 1; we do this by introducing a new variable a to represent each midpoint x to calculate its output
     float a;
     integral_approx[0]=0;

     for (i=1;i<=nintervals;i++) {
      a = (dx*(i-0.5));
      integral_approx[i] = (1 - (2*a) + (3*pow(a,2)) - pow(a,3))*dx + integral_approx[i-1];
  }

  // Error calculations for approximate integral; ersq is the error squared
     float errorI, error_sumI, error_maxI, ersqI;

     error_sumI = 0; error_maxI = 0;

     for (i=0;i<=nintervals-1;i++) {
      errorI = abs(integral_exact[i]-integral_approx[i]);
      ersqI = pow(errorI,2);
      error_sumI = error_sumI + ersqI;
      if (errorI > error_maxI)
       {error_maxI = errorI;}

  }

   cout << "The rms error on the approximate integral is " << sqrt(error_sumI/nintervals) << " .\n";
   cout << "The max error on the approximate integral is " << error_maxI << " .\n";
   cout << endl;

  // Plot the curves on graph
  cpgsci(3); cpgline(nintervals+1,x,y);
  cpgsci(2); cpgline(nintervals+1,x,dydx_approx);
  cpgsci(4); cpgline(nintervals+1,x,dydx_exact);
  cpgsci(8); cpgline(nintervals+1,x,integral_exact);
  cpgsci(1); cpgline(nintervals+1,x,integral_approx);

  cout << "Function is green, approx derivative is red, exact derivative is blue, exact integral is pink, approx integral is orange.\n"; 
  
  // Pause and then close plot window
  cpgclos();
}
