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

  double R, C, cheese;

  cin >> R >> C;


  cout  <<  setprecision(15) << 100.00* (((R-C)*(R-C))/(R*R)) << endl;

  return 0;
}