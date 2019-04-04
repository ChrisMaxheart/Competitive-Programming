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

  ll N, x, maxi, mini;
  cin >> N;

  maxi = 0;

  while (N--){
    cin >> x;
    mini = min(abs(1-x), abs(1000000-x));
    maxi = max(maxi, mini);
  }

  cout << maxi << endl;

  return 0;
}