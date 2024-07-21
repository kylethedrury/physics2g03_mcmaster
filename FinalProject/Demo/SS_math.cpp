#include <cmath>

double central_pressure_function (double Mstar, double Rstar, double G){
 return G*pow(Mstar,2.)/(8.*M_PI*pow(Rstar,4.));
}

double central_density_function (double central_pressure, float n){
 return pow(central_pressure,n/(n+1.));
}

double theta_derivative_function (float theta_derivative, float theta, float Xi, double dXi, float n){
 return theta_derivative + dXi*((-2./Xi)*theta_derivative - pow(theta,n)); 
}

double theta_function (float theta_derivative, float theta, double dXi){
 return theta + dXi*theta_derivative;
}

double density_function (float theta, float n){
 return pow(theta,n);
}

double dmdxi_function (double Xi, double density, double alpha){
 return 4*M_PI*pow(Xi,2)*pow(alpha,3)*density;
}


