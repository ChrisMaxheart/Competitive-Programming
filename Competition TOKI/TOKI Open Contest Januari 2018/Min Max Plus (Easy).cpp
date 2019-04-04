#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool reversecompare(int a, int b)
{
  return a > b;
}

int main ()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll N, Q, K, x, r, l, v, final;

  final = 0;

  cin >> N >> Q >> K;
  for (int i = 0; i < Q; i++)
  {
    cin >> x >> l >> r >> v;
    if (x == 1)
        if ((K >= l) && (K <= r))
            final += v;
    if (x == 2)
        if ((K >= l) && (K <= r))
            final = max(v, final);
    if (x == 3)
        if ((K >= l) && (K <= r))
            final = min(v, final);

  }
  cout << final << endl;

  return 0;
}