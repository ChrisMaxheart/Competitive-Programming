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

  int T, N, M;

  cin >> T;

  while (T--) {
    cin >> N >> M;
    int dum, dum2;

    while(M--) {
      cin >> dum >> dum2;
    }
    cout << N-1 << endl;
  }

  return 0;
}