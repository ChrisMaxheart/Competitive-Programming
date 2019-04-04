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

  double R, area1, area2;

  cin >> R;

  area1 = 3.1415926535897932384626 * R * R;
  area2 = 2 * R * R;

  cout << fixed << setprecision(10) << area1 << endl << area2 << endl;

  return 0;
}