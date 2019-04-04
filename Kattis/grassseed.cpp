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
  double price, total, width, length;

  total = 0;
  cin >> price >> N;
  for (int i = 0; i < N; i++) {
    cin >> width >> length;
    total += width*length;
  }

  cout << fixed << setprecision(7) << total*price << endl;
  return 0;
}