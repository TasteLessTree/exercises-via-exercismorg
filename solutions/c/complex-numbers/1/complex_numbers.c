#include <math.h>

#include "complex_numbers.h"

#define E exp(1)

complex_t c_add(complex_t a, complex_t b)
{
   complex_t result;

    result.real = a.real + b.real;
    result.imag = a.imag + b.imag;
    
    return result;
}

complex_t c_sub(complex_t a, complex_t b)
{
   complex_t result;

    result.real = a.real - b.real;
    result.imag = a.imag - b.imag;
    
    return result;
}

complex_t c_mul(complex_t a, complex_t b)
{
   complex_t result;

    result.real = (a.real * b.real - a.imag * b.imag);
    result.imag = (a.imag * b.real + a.real * b.imag);
    
    return result;
}

complex_t c_div(complex_t a, complex_t b)
{
    complex_t result;

    result.real = (a.real * b.real + a.imag * b.imag) / (pow(b.real, 2.0) + pow(b.imag, 2.0));
    result.imag = (a.imag * b.real - a.real * b.imag) / (pow(b.real, 2.0) + pow(b.imag, 2.0));
    
    return result;
}

double c_abs(complex_t x)
{
   return sqrt(pow(x.real, 2.0) + pow(x.imag, 2.0));
}

complex_t c_conjugate(complex_t x)
{
      complex_t result;

    result.real = x.real;
    result.imag = x.imag * (-1.0);
    
    return result;
}

double c_real(complex_t x)
{
   return x.real;
}

double c_imag(complex_t x)
{
   return x.imag;
}

complex_t c_exp(complex_t x)
{
    complex_t result;

    result.real = pow(E, x.real) * cos(x.imag);
    result.imag = pow(E, x.real) * sin(x.imag);
    
    return result;
}