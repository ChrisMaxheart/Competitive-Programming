
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

  int savex, savey;

  int N;

  cin >> N;

  int x, y;


  bool can = true;

  if (N%2 == 1) {
    can = false;
  }

  for (int i = 0; i < N; i++) {
    if (i == 0) {
      cin >> savex >> savey;
    } else {
      cin >> x >> y;
      if (x!= savex && y!= savey) {
        can = false;
      }
      savex = x;
      savey = y;
    }
  }
  

  if (can) {
    cout << "YA" << endl;
  } else {
    cout << "TIDAK" << endl;
  }

  return 0;
}