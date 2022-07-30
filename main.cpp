#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;
ifstream fin("file.in");
ofstream fout("file.out");

int main(){
  int len = 13, cnp[len+1]={0}, verif[len]={2, 7, 9, 1, 4, 6, 3, 5, 8, 2, 7, 9}, i;
  int S, A, L, Z, J, N, C, poz['Z'+1];    //S  A  A  L  L  Z  Z  J  J  N  N  N

  poz['S'] = 0; poz['A'] = 1; poz['L'] = 3; poz['Z'] = 5; poz['J'] = 7; poz['N'] = 9; poz['C'] = 12;

//  S	AA	LL	ZZ	JJ	NNN	C
//  https://ro.wikipedia.org/wiki/Cod_numeric_personal_(Rom%C3%A2nia)

  for (N = 1; N <= 3; N++) {
    for (A = 2; A <= 4; A++) {
      for (L = 1; L <= 12; L++) {
        for (Z = 1; Z <= 31; Z++) {
          for (S = 5; S <= 6; S++) {
            for (J = 1; J <= 52; J++) {
              cnp[poz['S']] = S;
              cnp[poz['A']] = A/10;
              cnp[poz['A']+1] = A%10;
              cnp[poz['L']] = L/10;
              cnp[poz['L']+1] = L%10;
              cnp[poz['Z']] = Z/10;
              cnp[poz['Z']+1] = Z%10;
              cnp[poz['J']] = J/10;
              cnp[poz['J']+1] = J%10;
              cnp[poz['N']] = N/100;
              cnp[poz['N']+1] = N/10%10;
              cnp[poz['N']+2] = N%10;


              C = 0;
              for (i = 0; i < len; i++)
                C += cnp[i] * verif[i];
              C %= 11;
              if (C == 10)
                C = 1;

              cnp[poz['C']] = C;

              for (i = 0; i < len; i++)
                fout << cnp[i];
              fout << endl;
            }
          }
        }
      }
    }
  }

}
