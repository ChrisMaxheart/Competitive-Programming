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

  int x = 0;
  int y = 0;
  int N;
  string z;

  int counter = 0;

  cin >> N >> z;

  for (int i = 0; i < N; i++) {
    if (z[i] == 'R')
      x++;
    else
      y++;
    if ((x == y) && (i != N-1)) {
      if (z[i] == z[i+1])
        counter++;
    }

  }

  cout << counter << endl;

  return 0;
}