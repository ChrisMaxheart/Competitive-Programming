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
    if (x == 16)
      cout << "4 + 4 + 4 + 4 = " << x;
    else if (x == 8)
      cout << "4 + 4 + 4 - 4 = " << x;
    else if (x == 24)
      cout << "4 + 4 + 4 * 4 = " << x;
    else if (x == 9)
      cout << "4 + 4 + 4 / 4 = " << x;
    else if (x == 0)
      cout << "4 + 4 - 4 - 4 = " << x;
    else if (x == -8)
      cout << "4 + 4 - 4 * 4 = " << x;
    else if (x == 7)
      cout << "4 + 4 - 4 / 4 = " << x;
    else if (x == 68)
      cout << "4 + 4 * 4 * 4 = " << x;
    else if (x == 1)
      cout << "4 + 4 / 4 - 4 = " << x;
    else if (x == 4)
      cout << "4 + 4 / 4 / 4 = " << x;
    else if (x == -16)
      cout << "4 - 4 - 4 * 4 = " << x;
    else if (x == -1)
      cout << "4 - 4 - 4 / 4 = " << x;
    else if (x == -60)
      cout << "4 - 4 * 4 * 4 = " << x;
    else if (x == 32)
      cout << "4 * 4 + 4 * 4 = " << x;
    else if (x == 17)
      cout << "4 * 4 + 4 / 4 = " << x;
    else if (x == 15)
      cout << "4 * 4 - 4 / 4 = " << x;
    else if (x == 60)
      cout << "4 * 4 * 4 - 4 = " << x;
    else if (x == 256)
      cout << "4 * 4 * 4 * 4 = " << x;
    else if (x == 2)
      cout << "4 / 4 + 4 / 4 = " << x;
    else if (x == -7)
      cout << "4 / 4 - 4 - 4 = " << x;
    else if (x == -15)
      cout << "4 / 4 - 4 * 4 = " << x;
    else if (x == -4)
      cout << "4 / 4 / 4 - 4 = " << x;
    else
      cout << "no solution";

    cout << endl;
  }

  return 0;
}