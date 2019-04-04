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

  int N, T, counter, x;

  counter = 0;
  cin >> N >> T;

  while(N--) {
    cin >> x;
    T -= x;
    if (T >= 0) counter++;
    else break;
  }

  cout << counter << endl;

  return 0;
}