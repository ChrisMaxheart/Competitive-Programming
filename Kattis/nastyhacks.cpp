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

  ll r, e, c, N;

  cin >> N;
  while (N--) {
    cin >> r >> e >> c;
    if (r+c > e) {
      cout << "do not advertise" << endl;
    }
    else if (r+c == e) {
      cout << "does not matter" << endl;
    }
    else {
      cout << "advertise" << endl;
    }    
  }

  return 0;
}