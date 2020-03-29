#include "../includes/Complex.h"
#include <iostream>
#include <math.h>

Complex::Complex()
{
  im = 0;
  re = 0;
}

Complex::Complex(const Complex &i) = default;

Complex::Complex(double re, double im)
{
  this->re = re;
  this->im = im;
}

void Complex::imprime()
{
  if(re != 0)
    std::cout << re;
  if(re != 0 && im > 0)
    std::cout << "+";
  if(im == 1)
    std::cout << "i";
  else if(im == -1)
    std::cout << "-i";
  else if(im != 0)
    std::cout << im << "i";
  if(re == 0 && im == 0)
    std::cout << 0;
}

void Complex::setRe(double re)
{ this->re = re; }

void Complex::setIm(double im)
{ this->im = im; }

double Complex::getRe() const
{ return re; }

double Complex::getIm() const
{ return im; }

Complex Complex::Add(const Complex &r) const
{
  Complex z;
  z = Complex (re + r.getRe(), im + r.getIm());
  return z;

}

Complex Complex::Sub(const Complex &r) const
{
  return Complex(re - r.getRe(), im - r.getIm());
}

Complex Complex::Div(const Complex &d) const
{
  double divisor     = (d.re * d.re) + (d.im * d.im);
  double dividendoRe = (re * d.re) + (im * d.im);
  double dividendoIm = (re * d.im) + (im * d.re);
  double Re          = dividendoRe/divisor;
  double Im          = dividendoIm/divisor;
  return Complex(Re, Im);
}

Complex Complex::Mult(const Complex &r) const
{
  return Complex(re * r.re - im * r.im, re * r.im + r.re * im);
}

double Complex::norm()
{
  return sqrt(re*re + im*im);
}

double Complex::arg()
{
  return ((double)180/PI)*atan((double)im/re);
}

Complex Complex::exp(int n)
{
  double c = cos(n * (PI/180) * (arg()));
  double s = sin(n * (PI/180) * (arg()));
  double r = pow(norm(), n);
  return Complex(r*c, r*s);
}
