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

  double R, x1, x2, y1, y2;

  cin >> R >> x2 >> y2 >> x1 >> y1;

  double dist;

  dist = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));

  double newx, newy, radi;

  radi = 0.5 * (dist+R);
  if (dist == 0) {
    newx = x1;
    newy = y1 + radi;
    // cout << y1 << endl;
    // cout << radi << endl;
  }

  else if (dist >= R) {
    newx = x2;
    newy = y2;
    radi = R;
  }
  else {
    newx = (radi*(x2-x1)/dist) +x1;
    newy = (radi*(y2-y1)/dist) +y1;
  }

  cout << setprecision(15) << newx << " " << newy << " " << radi << endl;

  return 0;
}