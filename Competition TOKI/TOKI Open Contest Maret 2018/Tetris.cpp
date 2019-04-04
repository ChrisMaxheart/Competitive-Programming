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

  int M, R, S, a, b, c, d;

  cin >> M >> S >> R;

  bool nemu = false;

  for (int i = 0; i <= M; i++) {
    if ((3*M - R - S - i) >= 0) {
      nemu = true;
      a = i;
      b = 3*M - R - S - a;
      c = R + b - a - M;
      d = M - a - b - c;

      if(a < 0 || b < 0 || c <0 || d <0) {
        nemu = false;
        continue;
      } else {
        break;
      }

    }
  }

  // cout << a << endl << b << endl << c << endl << d << endl;

  if (nemu) {
    while(a--)
      cout << "RR";
    while(b--)
      cout << "SS";
    while(c--) 
      cout << "RSR";
    while(d--)
      cout << "SRS";
    cout << endl;
  } else {
    cout << "TIDAK MUNGKIN" << endl;
  }

  return 0;
}