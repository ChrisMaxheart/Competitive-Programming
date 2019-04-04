#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

bool reversecompare(int a, int b)
{
  return a > b;
}

bool isperfect(ll z) {
  double x;
  ll y;

  x = sqrt(z);
  y = sqrt(z);

  if (x == y) return true;
  else return false;
}

int main ()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  ll m, n, x, limit, dummy;
  bool found;

  limit = 100000;

  cin >> t;

  while(t--) {
    cin >> x;
    found = false;
    for (ll i = sqrt(x)+1; i < limit; i++) {
      m = pow(i, 2) ;
      dummy = m-x;
      if (isperfect(dummy)) {
        dummy = sqrt(dummy);
        for (ll j = 1; j <= i; j++) {
          if (i/j == dummy) {
            found = true;
            n = j;
            m = i;
            break;
          }
        }
      }
      if (found) break;
    }
    if (found) cout << m << ' ' << n << endl;
    else cout << -1 << endl;
  }

  return 0;
}