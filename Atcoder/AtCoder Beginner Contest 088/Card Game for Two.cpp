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
  int a[150];

  cin >> N;
  for (int i = 0; i < N; i++)
    cin >> a[i];
  sort(a, a+N, reversecompare);

  int p1, p2;

  p1 = 0;
  p2 = 0;

  for (int i =0;i < N; i++) {
    if (i%2)
      p2 += a[i];
    else
      p1 += a[i];
  }

  cout << p1-p2 << endl;

  return 0;
}