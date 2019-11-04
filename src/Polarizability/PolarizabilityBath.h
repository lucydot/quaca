#ifndef POLARIZABILITYBATH_H
#define POLARIZABILITYBATH_H

#include <complex>
#include <cmath>

#include "MemoryKernel.h"
#include "Polarizability.h"

class PolarizabilityBath : public Polarizability
{
private:
    // memory kernel and greens tensor needed to calculate alpha
    MemoryKernel *memorykernel;

public:

    PolarizabilityBath(std::string input_file);
    std::complex<double> get_mu(double omega);

    cx_mat::fixed<3,3> calculate(double omega);

};


#endif //POLARIZABILITYBATH_H
