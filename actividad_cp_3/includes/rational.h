
class rational
{
private:
  int p;
  int q;
  bool simp;
public:
  rational();
  rational(int, int);
  rational(int, int, bool);
  rational(const rational &);
  void setP(int);
  void setQ(int);
  void setSimp(bool);
  int getP();
  int getQ();
  bool getSimp();
  void imprime();
  bool isReduc();
  rational reduc();
  bool simplify();
  rational sum(rational &);
  rational sub(rational &);
  rational div(rational &);
  rational mult(rational &);
  rational exp(int);
  double reAprox();
};
