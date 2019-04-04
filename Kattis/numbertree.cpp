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

  ll N;
  string command;

  cin >> N >> command;
  N = pow(2, N+1);
  ll x = 1;
  for (auto i : command) {
    if (i == 'L')
      x = x *2;
    else
      x = x*2 + 1;
  }
  cout << N-x << endl;
  return 0;
}