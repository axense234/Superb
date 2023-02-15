#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

ifstream intrare("superb.in");
ofstream iesire("superb.out");

unsigned short int calcNrCifre(unsigned long long int n)
{
  unsigned short int nrCif = 0;
  while (n)
  {
    nrCif++;
    n /= 10;
  }
  return nrCif;
}

int main()
{
  unsigned long long int n, impartitor;
  unsigned short int nrImpartiri, nrCif, nrFinal = 0;
  intrare >> n;
  if (n % 2023 != 0)
  {
    iesire << "NU";
  }
  else
  {
    nrImpartiri = n / 2023;
    nrCif = calcNrCifre(nrImpartiri);
    impartitor = pow(10, nrCif - 1);

    if (nrImpartiri < 100)
    {
      iesire << nrImpartiri / 10 + nrImpartiri % 10;
    }
    else
    {
      unsigned short int i = 1;
      while (i <= nrCif)
      {
        nrFinal += nrImpartiri / impartitor % 10;
        impartitor /= 10;
        i++;
      }
      iesire << nrFinal;
    }
  }
  return 0;
}
