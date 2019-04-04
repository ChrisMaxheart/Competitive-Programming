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

  int T, N, x;
  int largest = -1;
  int smallest = -1;

  cin >> T;
  while (T--) {
    cin >> N;
    while(N--) {
      cin >> x;
      if (largest == -1)
        largest = x;
      else
        largest = max(largest, x);
      if (smallest == -1)
        smallest = x;
      else
        smallest = min(smallest, x);
    }
    cout << 2*(largest-smallest) << endl;
    largest = -1;
    smallest = -1;
  }

  return 0;
}