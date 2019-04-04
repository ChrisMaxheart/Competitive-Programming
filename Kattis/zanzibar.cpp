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

  int T, N, x, final, current;

  cin >> T;

  while(T--) {
    final = 0;
    current = 1;
    while (true) {
      cin >> x;
      if (x == 0) break;
      // cout << x << "DAN" << current << endl;
      if (x > current*2) {
        final += (x - (2*current));
        // cout << "TEST" << x << endl;
      } 
      current = x;
    }
    cout << final << endl;
  }

  return 0;
}