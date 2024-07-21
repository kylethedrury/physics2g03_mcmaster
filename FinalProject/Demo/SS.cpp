#include <iostream>
#include <cmath> 
#include <cpgplot.h>
#include <iomanip>
#include "SS_math.h"

using namespace std;

int main(){

  // Declare important paramters, constants, and variables

  const double G = 6.6743e-11;
  double Mstar = 2e30; 
  double Rstar = 696400000;
  float n = 3;
  double central_pressure, central_density;
  int i;
  
  cout << "This demo program calculates the central pressure and density of our Sun, and plots the solution of the Lane Emden equation for a polytropic index of 3.\n";

  // Calculate central pressure and density with functions in SS_math.h

  central_pressure = central_pressure_function (Mstar, Rstar, G);
  central_density = central_density_function (central_pressure, n);

  cout << "Central pressure is " << central_pressure << " and central density is " << central_density << ".\n";
  cout << endl;

  // Prepare to solve LE Eqn
 
  float XiStar = 15;
  int nintervals = 1500;
  float dXi; 

  cout << "This demo uses a step size of 0.01 and plots the LEE up to dimensionless radius xi = 15.\n";

  dXi = XiStar/nintervals;

  cout << "XiStar is " << XiStar << " and dXi is " << dXi << " .\n";
  cout << endl;

  // Use a loop to solve the Lane Emden Equation. We must declare some arrays and initial starting conditions

  float Xi_array[nintervals+1], theta_array[nintervals+1], theta_derivative_array[nintervals+1];

  Xi_array[0] = 0.0001; // 0 will produce a math error
  theta_array[0] = 1.; // LE Eqn definitionally starts at 1
  theta_derivative_array[0] = 0; 

  for(i=0;i<=nintervals;i++){
    theta_derivative_array[i+1] = theta_derivative_function (theta_derivative_array[i], theta_array[i], Xi_array[i], dXi, n);
    theta_array[i+1] = theta_function (theta_derivative_array[i], theta_array[i], dXi);
    Xi_array[i+1] = Xi_array[i] + dXi;
    }

  // We can now solve the density function because we have theta. We have normalized this function s.t. central density = 1 so we can plot on the same plane.

  float density_array[nintervals+1];
  density_array[0] = 1.;
 
  for(i=1;i<=nintervals;i++){
    density_array[i] = density_function (theta_array[i],n);
    }

  // Solve for mass enclosed by summing the density function times differential dXi, normalize by dividing by . 

  float m_enclosed_array[nintervals+1];
  m_enclosed_array[0] = 0;

  for(i=1;i<nintervals;i++){
    m_enclosed_array[i] = m_enclosed_array[i-1] + dXi*density_array[i];
    }

  // Open a plot window
  if (!cpgopen("/XWINDOW")) return 1;

  // Set-up plot axes
  cpgenv(0.,XiStar,-0.5,2,0,1);

  // Label axes
  cpglab("Xi", "Theta", "Solution of LE, Density, M Enc.");

  // Plot the curves on graph
  cpgsci(3); cpgline(nintervals+1,Xi_array,theta_array);
  cpgsci(2); cpgline(nintervals+1,Xi_array,density_array);
  cpgsci(5); cpgline(nintervals+1,Xi_array,m_enclosed_array);  

  cout << "Lane Emden solution is green, density is red, mass enclosed is blue.\n";

  // Pause and then close plot window
  cpgclos();

  //---------------------------------------------------------------------------------------------------------

 
 
}
  

  
