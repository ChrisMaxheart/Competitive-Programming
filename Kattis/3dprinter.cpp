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

  int x;

  cin >> x;

  int printer = 1;
  int count = 0;

  while (printer < x) {
    printer *= 2;
    count++;
  }

  cout << count+1 << endl;

  return 0;
}