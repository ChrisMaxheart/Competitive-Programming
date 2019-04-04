#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

bool reversecompare(int a, int b)
{
  return a > b;
}

int main ()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int R, C, zr, zc;

  cin >> R >> C >> zr >> zc;

  char myarr[55][55];

  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      cin >> myarr[i][j];
    }
  }

  for (int i = 0; i < R; i++) {
    for (int Ri = 0; Ri < zr; Ri++) {
      for (int j = 0; j < C; j++) {
        for (int Rj = 0; Rj < zc; Rj++) {
          cout << myarr[i][j];
        }
      }
      cout << endl;
    }
  }

  return 0;
}