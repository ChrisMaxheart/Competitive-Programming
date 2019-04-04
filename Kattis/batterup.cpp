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

  double x;
  double total;
  int N, slug;

  cin >> N;
  slug = 0;
  total = 0;
  while (N--) {
    cin >> x;
    if (x >= 0) {
      slug++;
      total += x;
    }
  }

  cout << setprecision(15) << total/slug << endl;

  return 0;
}