class rational
{
  int p;
  int q;
    
public:
  rational();
  rational(int, int);
  rational(const rational &);
  int getP();
  int getQ();
  void setP(int);
  void setQ(int);
  void imprime();
  rational reduce();
};
