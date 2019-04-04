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

  map<string, string> mine;

  stringstream check;

  string x, y, z, dummy;

  while(getline(cin, x)) {
    if (x == "") break;
    check << x;
    check >> y >> z;
    check.clear();
    // cout << y << " "<<z;
    mine[z] = y;
  }

  while(cin >> x) {
    dummy = mine[x];
    if (dummy != "")
      cout << dummy << endl;
    else
      cout << "eh" << endl;
  }

  return 0;
}