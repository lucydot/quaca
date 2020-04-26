#ifndef OHMICMEMORYKERNEL_H
#define OHMICMEMORYKERNEL_H

#include "MemoryKernel.h"
#include <cmath>
#include <complex>

//! An ohmic memory kernel
class OhmicMemoryKernel : public MemoryKernel {
private:
  double gamma; // damping coefficient

public:
  // constructors
  explicit OhmicMemoryKernel(double gamma);
  OhmicMemoryKernel(const std::string &input_file, const std::string &section);
  explicit OhmicMemoryKernel(const std::string &input_file);

  // calculate function
  std::complex<double> calculate(double omega) override;

  // getter functions
  double get_gamma() const { return this->gamma; };
};

#endif // OHMICMEMORYKERNEL_H
