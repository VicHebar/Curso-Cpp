#define PI 3.1416
class Complex
{
private:
  double re;
  double im;
public:
  Complex();
  Complex(const Complex &);
  Complex(double, double);
  void setRe(double);
  void setIm(double);
  double getRe() const;
  double getIm() const;
  void imprime();
  Complex Add(const Complex &) const;
  Complex Sub(const Complex &) const;
  Complex Div(const Complex &) const;
  Complex Mult(const Complex &) const;
  double norm();
  double arg();
  Complex exp(int);
};
