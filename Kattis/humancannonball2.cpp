#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define g 9.81
#define PI 3.141592653

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
    double v, theta, x, h1, h2;
    cin >> v >> theta >> x >> h1 >> h2;

    h2--;
    h1++;

    theta = (theta * PI)/180;

    double t = x/(v*cos(theta));

    double y = v * t * sin(theta) - 0.5 * g * t * t;

    // cout << t << endl;

    if (y <= h2 && y >= h1) {
      cout << "Safe" << endl;
    } else {
      cout << "Not Safe" << endl;
    }
  }

  return 0;
}