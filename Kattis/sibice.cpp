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

  double limit;
  int N, W, H, x;

  cin >> N >> W >> H;
  limit = sqrt(pow(W, 2) + pow(H,2));

  while (N--) {
    cin >> x;
    if (x <= limit) cout << "DA" << endl;
    else cout << "NE" << endl;
  }
  return 0;
}