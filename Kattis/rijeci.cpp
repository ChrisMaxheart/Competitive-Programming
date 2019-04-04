#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

bool reversecompare(int a, int b)
{
  return a > b;
}

struct combi{
  int a, b;
};

int main ()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  combi press[50];

  for (int i = 0; i < 48; i++) {
    press[i].a = 0;
    press[i].b = 0;
  }

  int k;

  cin >> k;

  press[0].a = 1;

  for (int i = 1; i <= k; i++) {
    press[i].a = press[i-1].b;
    press[i].b = press[i-1].a + press[i].a;
  }

  cout << press[k].a << ' ' << press[k].b << endl;

  return 0;
}