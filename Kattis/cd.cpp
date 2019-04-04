#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

bool reversecompare(int a, int b)
{
  return a > b;
}

ll jack[1000100];

int main ()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll N, M;
  ll x;
  ll counter = 0;

  while (true) {
    for (ll i; i < 1000001; i++) {
        jack[i] = 0;
      }
    counter = 0;
    cin >> N >> M;

    if ((N == 0) && (M == 0)) break;

    for (ll i = 0; i < N; i++) {
      cin >> jack[i];
      // assert(jack[i] != 0);
    }
    for (ll i = 0; i < M; i++) {
      cin >> x;
      if (binary_search(jack, jack+N, x)) counter++;
      // assert(jill[i] != 0);
    }

    cout << counter << endl;
  }
  return 0;
}