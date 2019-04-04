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

  ll k;

  cin >> k;
  if (k > 36) cout << -1 << endl;
  else {
    while (true) {
      if (k == 0) {
        cout << endl;
        break;
      }
      else if (k == 1) {
        cout << 6 << endl;
        break;
      }
      else {
        cout << 8;
        k -= 2;
      }
    }
  }
  return 0;
}