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

  string x;

  cin >> x;

  bool hiss = false;

  for (int i = 0; i < x.length()-1; i++) {
    if ((x[i] == 's') && (x[i+1] == 's'))
      hiss = true;
  }

  if (hiss)
    cout << "hiss" << endl;
  else
    cout << "no hiss" << endl;

  return 0;
}