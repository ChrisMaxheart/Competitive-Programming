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

  int N, A;

  cin >> N >> A;

  if (N%500 > A) cout << "No";
  else cout << "Yes";
  cout << endl;

  return 0;
}