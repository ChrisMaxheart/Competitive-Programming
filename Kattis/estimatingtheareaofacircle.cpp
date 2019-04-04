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

  double r, m, c;

  while(true) {
    cin >> r >> m >> c;
    if (!(r && m && c))
      break;
    double real = 3.141592653 * r * r;
    double area = 4*r*r;
    double estimate = (c * area) / m;
    cout << setprecision(9) << real << " " << estimate << endl;
  }

  return 0;
}