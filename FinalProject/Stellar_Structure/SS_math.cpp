#include <cmath>

double central_pressure_function (double Mstar, double Rstar, double G, double K){
 return G*pow(Mstar,2.)/(8.*M_PI*K*pow(Rstar,4.));
}

double central_density_function (double central_pressure, float n){
 return pow(central_pressure,n/(n+1.));
}

// For 4th order Runge Kutta
double theta_second_derivative_function (float theta_derivative, float theta, float Xi, float n){
 return (-2./Xi)*theta_derivative - pow(theta,n); 
}

// For Euler method
double theta_function (float theta_derivative, float theta, double dXi){
 return theta + dXi*theta_derivative;
}

double density_function (float theta, float n){
 return pow(theta,n);
}

double unitless_mass_differential (float theta, float Xi, float n){
 return pow(theta,n)*pow(Xi,2.);
}

double pressure_function (float K, float density, float n){
 return K*pow(density,(1./n)+1.);
}


