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

  int n1, n2, f1, f2;

  cin >> n1 >> n2;

  f1 = 0;
  f2 = 0;

  while(n1 > 0) {
    f1 = f1*10 + n1%10;
    n1 /= 10;
  }

  while(n2 > 0) {
    f2 = f2*10 + n2%10;
    n2 /= 10;
  }

  cout << max(f1, f2) << endl;

  return 0;
}