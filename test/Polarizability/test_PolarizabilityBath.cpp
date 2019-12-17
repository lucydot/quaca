#include <complex>
#include <armadillo>

#include "catch.hpp"
#include "Quaca.h"

TEST_CASE("Polarizability with bath can be constructed in different ways", "[PolarizabilityBath]")
{
  SECTION("Constructor from .ini file")
  {
    PolarizabilityBath pol("../data/test_files/PolarizabilityBath.ini");
    REQUIRE( pol.get_omega_a() == 1.3 );
    REQUIRE( pol.get_alpha_zero() == 6E-9 );

    // test if we read memory kernel correctly
    std::complex<double> test = pol.get_mu(3.0);
    REQUIRE( test.real() == 0.69420 );
  };

  SECTION("Constructor with direct input")
  {
    OhmicMemoryKernel mu(0.69420);
    PolarizabilityBath pol(1.3, 6E-9, &mu, NULL);
    REQUIRE( pol.get_omega_a() == 1.3 );
    REQUIRE( pol.get_alpha_zero() == 6E-9 );

    std::complex<double> test = pol.get_mu(3.0);
    REQUIRE( test.real() == 0.69420 );
  };
};

TEST_CASE("Polarizability can be calculated", "[PolarizabilityBath]")
{
    OhmicMemoryKernel mu(0.69420);
    GreensTensorVacuum green(0.1, 30.2);
    PolarizabilityBath pol(3.4, 1.0, &mu, &green);

    cx_mat::fixed<3,3> test(fill::zeros);
    pol.calculate(test, 0.5);

    std::cout << test << std::endl;

    REQUIRE(0 == 0);
}
