////////////////////////////////////////////////////////////////////////////////
// This program is designed to calculate nonequilibrium quantum friction
// as well as the angular momentum and moment of inertia of a dipole hovering
// at a constant distance and velocity above a macroscopic surface described by
// a local dielectric function.
// For the calculation of the quantum friction we use the form:
//
// F_fric = \int_{0}^\infty dw (
//         -2Tr[S(w) \int d^2k/(2pi)^2 kx G_I(k,kx v + w)]
//         +2 hbar/pi Tr[alpI(w)\int d^2k/(2pi)^2 kx G_I(k,kx v + w)]]
//          *H(kx v + w) )
/******************************************************************************/
// The header.h contains all functions and subroutines needed for those
// calculations, as well as all needed parameters. Here a brief overview over
// the functions and subroutines contained:
//
// Finite integration      : integ(f,a,b,relerr)
// Matrix multiplication   : multiply(mat1,mat2,res)
// Trace of a matrix       : tr(mat)
// Complex-transposed      : dagger(mat,dagmat)
// 1/(2i)(A - A^+)         : fancyI(mat, matI)
// Reflection coefficient  : rR(w,k) and rI(w,k)
// Integrated Green tensor : Gint(Gten,w,RorI,T,kx)
// Polarizability          : alpha(alp,w)
#include "header.h"
/******************************************************************************/
 

/******************************************************************************/
// Main program
int main () {

/* Plot parameters */
int maxi=1000;                        // plot points
double sta = 1E-6 ;                 // start value of the calculation,
double sto = 7E0 ;                 // final value of the calculation
double spac = (sto-sta)/maxi;      // and the respective spacing
double w;
double anginer[2];
FILE *fp;                           // output file
int l;                              // dummy index

/* System parameters (input routine is not implemented yet) */
v    = 1E-3;                   // velocity in c
za   = 10E-9/(1.9732705e-7);   // height of the dipole in 1/eV
eps0 = 1./(4*PI);             // vacuum permittivity
hbar = 1.;                    // reduced Planck's constant
c    = 1.;                    // speed of light
a0   = 6e-9;                  // static polarizability
wa   = 1.3e0;                 // dipole resonance frequency in eV
einf = 3.7;                   // background permittivity
wp1  = 9.;               // plasma frequency in eV
wsp1 = wp1/sqrt(1.+einf);     // plasma frequency in eV
g1   = 0.1;                   // damping of the material in eV
kcut = 100.;                   // Integration cut-off of the k-integration
relerr = 1e-8;                // aimed relative error of the integration
recerr = 1e-2;                // increase of relerr per layer of integration
beta   = 1./((1e-6)/1.16e4);       // temperature in eV

/* open the file */
fp = fopen("../output/resultsOm.dat", "w");
if (fp == NULL) {
   printf("I couldn't open results.dat for writing.\n");
   exit(0);
}


/* Starting calculations */
for (l=0; l<=maxi; ++l){
   printf("progress %3.2f\n",l*100./maxi );
   /* Point of evaluation */
   w = sta+spac*l;
   AngIner(w, anginer);
     printf("%.5e, %.5e\n",anginer[0],anginer[1] );
   /* Print result to the screen */
   printf("w= %.5e\n", w);
   /* write to the file */
   fprintf(fp, "%.10e, %.10e, %.10e\n", w,anginer[0],anginer[1]);
   /* buffer data for interative writing process */
   fflush(fp);
   printf ("%s \n", " ");
 }

return 0;
}
////////////////////////////////////////////////////////////////////////////////
