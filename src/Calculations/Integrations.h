#ifndef INTEGRATIONS_H
#define INTEGRATIONS_H
#include <iostream>
#include <cmath>

double cquad(double my_f(double, void *), double a , double b, double relerr, double epsabs);

double qags(double my_f(double, void *), double a , double b, double relerr, double epsabs);

double qagiu(double my_f(double, void *), double a , double relerr, double epsabs);

#endif //INTEGRATIONS_H
