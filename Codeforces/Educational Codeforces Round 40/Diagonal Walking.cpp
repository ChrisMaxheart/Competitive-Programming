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

  int N, final;
  string x;

  cin >> N >> x;

  int i = 0;

  final = 0;

  while (i < N) {
    if (i < N-1 && x[i] != x[i+1]) {
      i += 2;
    } else {
      i += 1;
    }
    final++;
  }

  cout << final << endl;

  return 0;
}