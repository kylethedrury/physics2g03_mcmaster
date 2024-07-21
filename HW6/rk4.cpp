#include <cmath>
#include <iostream> 
#include "cpgplot.h"
using namespace std; 

 // Declare ODE
 double dydt(double y, double a) {
   return a*(1-y);
  } 

 // Declare analytical solution to ODE
 double sol(double t, double a) {
   return 1. - exp(-1.*a*t);
   }

 int main()
 {
 // Open a plot window
 if (!cpgopen("/XWINDOW")) return 1;

 // Declare variables
 double dt, t, a, y, yexact, t_start, t_end, k1, k2, k3, k4;
 int i, n;

 // Initial conditions and parameters
 t_start = 0.;
 t_end = 10.;
 a = 0.4;
 n = 100;

 // cout << "Please input n.\n";
 // cin >> n;
 cout << "Using n=100:\n";

 dt = (t_end-t_start)/n;

 // Declare float arrays for the exact analytical solution and the approximate solution of dydt
 float yexactp[n+1], yp[n+1], tp[n+1];

 // Set-up plot axes
 cpgenv(t_start,t_end,0.,1.,0,1);

 // Label axes
 cpglab("t", "y", "Solution to dydt = a*(1-y)");

 // Declare initial conditions for arrays
 yexactp[0] = sol(t_start,a);
 yp[0] = 0; 
 tp[0] = 0;

 // Loop for calculating each point and corresponding arrays
  for (t=t_start,y=0,yexact=0,i=1;i<=n;i++){
    t = t + dt;
    k1 = dydt(y,a)*dt;
    k2 = dydt(y+0.5*k1,a)*dt;
    k3 = dydt(y+0.5*k2,a)*dt;
    k4 = dydt(y+k3,a)*dt;
    y = y + (k1 + 2.*k2 + 2.*k3 + k4)/6.;
    yp[i] = y;
    yexact = sol(t,a);
    yexactp[i] = yexact;
    tp[i] = t;
    }

 // Output important data
 cout << n << ", " << dt << ", " << yexact << ", " << abs(yexact-y) << ", " << abs(yexact-y)/pow(dt,4) << "\n"; 

 // Plot the curves on graph
 cpgsci(3); cpgline(n+1, tp, yexactp);
 cpgsci(2); cpgline(n+1, tp, yp);
  
 cout << "Exact is green, approximate is red.\n"; 

 //Close window
 cpgclos();

}


  

