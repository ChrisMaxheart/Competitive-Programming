#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool reversecompare(int a, int b)
{
  return a > b;
}

int main ()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, x, y;
  ll lef, u, righ, dow, delta;

  cin >> n;
  if (n == 1)
    cout << 0 << " " << 0 << endl;
  else
  {
    lef = n-2;
    u = n-3;
    righ = n-4;
    dow = n-5;

    if (lef%4 == 0)
    {
      delta = lef/4 +1;
      cout << -delta << " " << 0 << endl;
    } 
    else if (righ%4 == 0)
    {
      delta = righ/4 +1;
      cout << delta << " " << 0 << endl;
    } 
    else if (u%4 == 0)
    {
      delta = u/4 +1;
      cout << 0 << " " << delta << endl;
    } 
    else if (dow%4 == 0)
    {
      delta = dow/4 +1;
      cout << 0 << " " << -delta << endl;
    } 
  }


  return 0;
}