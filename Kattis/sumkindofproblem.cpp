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

  int N;

  cin >> N;

  while (N--) {
    int x;
    cin >> x;
    cout << x << " ";
    cin >> x;
    int t1, t2, t3;
    t1 = x * (1 + x);
    t1 /= 2;
    t2 = x * x;
    t3 = t2 + x;
    cout << t1 << " " << t2 << " " << t3 << endl;
  }

  return 0;
}