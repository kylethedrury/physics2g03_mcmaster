#include <iostream>
#include <cmath> 
#include <cpgplot.h>
#include <iomanip>
#include "SS_math.h"

using namespace std;

int main(){

  // Declare important paramters, constants, and variables

  const double G = 6.6743e-11;
  double Mstar, Rstar, central_pressure, central_density, K;
  int i, a, c, d;
  float n;
  
  cout << "Please specify Mstar, Rstar, polytropic index n, and proportionality constant K.\n";
  cin >> Mstar >> Rstar >> n >> K;
  cout << endl;

  // Calculate central pressure and density with functions in SS_math.h

  central_pressure = central_pressure_function (Mstar, Rstar, G, K);
  central_density = central_density_function (central_pressure, n);

  cout << "Central pressure is " << central_pressure << " and central density is " << central_density << ".\n";
  cout << endl;

  // Prepare to solve LE Eqn
 
  float dXi, XiStar;
  int nintervals;

  cout << "Please specify the number of steps and XiStar (recommended is 15.0).\n";
  cin >> nintervals >> XiStar;

  dXi = XiStar/nintervals;

  cout << "XiStar is " << XiStar << " and dXi is " << dXi << " .\n";
  cout << endl;

  // Use a loop to solve the Lane Emden Equation. We must declare some arrays and initial starting conditions
  // The value of the first derivative is calculated with the 4th order Runge Kutta method 
  // The result of this approximation is used along with the initial value of theta to Euler approximate theta.

  float Xi_array[nintervals+1], theta_array[nintervals+1], theta_derivative_array[nintervals+1];

  Xi_array[0] = 0.0001; // 0 will produce a math error
  theta_array[0] = 1.; // LE Eqn definitionally starts at 1
  theta_derivative_array[0] = 0; 

  for(i=0;i<=nintervals;i++){
    double k1, k2, k3, k4;

    k1 = dXi*theta_second_derivative_function (theta_derivative_array[i], theta_array[i], Xi_array[i], n);
    k2 = dXi*theta_second_derivative_function (theta_derivative_array[i]+0.5*k1, theta_array[i], Xi_array[i]+0.5*dXi, n);
    k3 = dXi*theta_second_derivative_function (theta_derivative_array[i]+0.5*k2, theta_array[i], Xi_array[i]+0.5*dXi, n);
    k4 = dXi*theta_second_derivative_function (theta_derivative_array[i]+k3, theta_array[i], Xi_array[i]+dXi, n);

    theta_derivative_array[i+1] = theta_derivative_array[i] + (k1+2*k2+2*k3+k4)/6;
    theta_array[i+1] = theta_function (theta_derivative_array[i+1], theta_array[i], dXi);
    Xi_array[i+1] = Xi_array[i] + dXi;
    c = i; // Counter
    if (n==1 || n==2 || n==3 || n==4 || n==5){
      if (theta_array[i+1] <= -100.) break; // Avoid floating errors by placing a lower limit on the values we calculate (for n=2)
      }  
    else {if (theta_array[i+1] <= 0.004) break;} // LE behaves differently for non-integer values of n, so we define a different cutoff condition for such cases.
    }

  // We can now solve the density function because we have theta. We have normalized this function s.t. central density = 1 so we can plot on the same plane.

  float density_array[c+1]; // Same number of points as LE
  density_array[0] = 1.;
 
  for(i=1;i<=c;i++){
    density_array[i] = density_function (theta_array[i],n);
    if (density_array[i] <= 0.0001){ // If density gets too small, floating errors will occur
      d = i;
      break; 
      }
    }

  // We have the density function, so we can now relate to this pressure and graph pressure as a function dimensionless radius (scaled s.t. CP = 1)

  float pressure_array[c+1];
  
  for (i=0;i<=c;i++){
    pressure_array[i] = pressure_function (K, density_array[i], n);
    a = i; // To avoid plotting nonexistent values in pgplot (will produce problems)
    if (pressure_array[i]<=1e-3) break;
    }     
 
  // Solve for mass enclosed by using the Runge Kutta so solve the unitless mass differential equation

  float phi_array[a+1];
  phi_array[0] = 0;
  float b = 0;

  for(i=1;i<=a;i++){
    double k1, k2, k3, k4;
  
    k1 = dXi*unitless_mass_differential (theta_array[i], Xi_array[i], n);
    k2 = dXi*unitless_mass_differential (theta_array[i], Xi_array[i]+0.5*dXi, n);
    k3 = dXi*unitless_mass_differential (theta_array[i], Xi_array[i]+0.5*dXi, n);
    k4 = dXi*unitless_mass_differential (theta_array[i], Xi_array[i]+dXi, n);
    
    phi_array[i] = phi_array[i-1] + (k1+2.*k2+3.*k3+k4)/6.;

    if (b <= phi_array[i]){ 
      b = phi_array[i]; // We are getting the max value and putting it into variable b. We will divide every value in the array by b to normalize it.
      }
    }

  // Normalize dimensionless mass by dividing every array value by b

  for (i=0;i<=a;i++){
    phi_array[i] = phi_array[i]/b;
    }

  // Open a plot window
  if (!cpgopen("/XWINDOW")) return 1;

  // Set-up plot axes
  cpgenv(0.,XiStar,-0.5,2,0,1);

  // Label axes
  cpglab("Xi", "Theta", "Theta, Theta's First Derivative, Density, Mass Enclosed, & Pressure.");

  // Plot the curves on graph
  cpgsci(3); cpgline(c+1,Xi_array,theta_array);
  cpgsci(5); cpgline(a,Xi_array,phi_array); 
  cpgsci(6); cpgline(a,Xi_array,pressure_array); 
  cpgsci(7); cpgline(c+1,Xi_array,theta_derivative_array);

  if (n==1 || n==2 || n==3 || n==4 || n==5){
  cpgsci(2); cpgline(d+1,Xi_array,density_array);
  }
  else {cpgsci(2); cpgline(c+1,Xi_array,density_array);
  }

  cout << "Lane Emden solution is green, first derivative is yellow, density is red, mass enclosed is blue, pressure is pink.\n";

  // Pause and then close plot window
  cpgclos();

  //---------------------------------------------------------------------------------------------------------

 
}
  

  
