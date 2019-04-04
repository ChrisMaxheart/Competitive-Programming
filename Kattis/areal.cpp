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

  double N, x;

  cin >> N;

  x = sqrt(N);
  cout << setprecision(15) << 4*x << endl;

  return 0;
}