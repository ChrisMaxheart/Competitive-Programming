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

  int T;

  cin >> T;

  while (T--) {
    ll N;
    cin >> N;

    ll dummy;

    ll total = 0;

    for (ll i = 0; i < N; i++) {
      cin >> dummy;
      dummy = dummy % N;
      total += dummy;
      total %= N;
    }

    if (total == 0)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;

  }

  return 0;
}