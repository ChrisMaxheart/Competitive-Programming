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

  unordered_map<string, int> mymap;

  string x;
  bool benar = true;

  while(cin >> x) {
    if (mymap[x] > 0) {
      benar = false;
    } else {
      mymap[x] = 1;
    }
  }

  if (benar)
    cout << "yes" << endl;
  else
    cout << "no" << endl;

  return 0;
}