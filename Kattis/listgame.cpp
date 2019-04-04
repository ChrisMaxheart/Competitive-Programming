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

  int x, counter;

  counter = 0;

  cin >> x;

  int dummy = x;

  int i = 2;

  while (i <= x && i <= sqrt(dummy)) {
    if (x%i == 0) {
      x /= i;
      counter++;
    } else {
      i += 1;
    }
  }

  if (x > sqrt(dummy))
    counter++;

  cout << counter << endl;

  return 0;
}