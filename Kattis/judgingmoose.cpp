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

  int left, right;

  cin >> left >>  right;

  if (left == 0 && right == 0)
    cout << "Not a moose" << endl;
  else if (left == right)
    cout << "Even " << left+right << endl;
  else
    cout << "Odd " << 2* max(left, right) << endl;

  return 0;
}