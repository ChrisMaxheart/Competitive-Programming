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

  int p, a, b, c, d, n;

  cin >> p >> a >> b >> c >> d >> n;

  double maxi, delta;
  maxi = -100000;
  delta = 0;


  for (int i = 1; i <= n; i++) {
    double price = p * (sin(a*i + b) + cos(c*i + d) + 2);
    maxi = max(maxi, price);
    delta = max(delta, maxi-price);
  }

  cout << setprecision(10) << delta << endl;

  return 0;
}