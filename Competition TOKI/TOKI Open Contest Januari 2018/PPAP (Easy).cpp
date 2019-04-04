#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define z 1000000007

bool reversecompare(int a, int b)
{
  return a > b;
}

ll pdpan[107050];
ll pbelakang[107050];

int main ()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  unsigned long long dum3;
  ll N, final, totalp, dummy, dum2, a, b;
  string kata;

  final = 0;
  cin >> N >> kata;
  // cout << kata << endl;
  if (kata[0] == 'P')
  {
      pdpan[0] = 1;
      totalp= 1;
  }
    else
      pdpan[0] = 0;
  for (ll i = 1; i < N; i++)
  {
    if (kata[i] == 'P')
    {
      pdpan[i] = pdpan[i-1] + 1;
      totalp++;
    }
    else
      pdpan[i] = pdpan[i-1];
  }
  for (ll i = 0; i < N; i++)
    pbelakang[i] = totalp - pdpan[i];
  for (ll i = 0; i < N; i++)
    if ((kata[i] == 'A') && ((pdpan[i] > 1) && (pbelakang[i] > 0)))
    {
      a = pdpan[i];
      b = pdpan[i]-1;
      dum3 = a*b;
      dum3 /=2;
      // cout << dum3 << endl;
      // cout << pdpan[i] << " "<< pdpan[i]-1 << endl;
      // dum3 = ((pdpan[i]) * pdpan[i]-1);
      // dum3 /= 2;
      // if (pdpan[i]%2)
      //   dummy = ((pdpan[i] * ((pdpan[i]-1)/2)));
      // else
      //   dummy = ((pdpan[i]/2) * pdpan[i]-1);
      // cout << dummy << endl;
      dummy = dum3%z;
      // cout << dummy << endl;
      dummy *= pbelakang[i];
      // cout << dummy << endl;
      dummy = dummy%z;
      // cout << dummy << endl;
      // cout << final << endl;
      final += dummy;
      final = final%z;
    }
  cout << final << endl;
  // a = 106874;
  // b = 106873;
  // dum2 = a*b;
  // cout << dum2 << endl;
  // dum2 = dum2%z;
  // cout << dum2 << endl;
  // cout << 106874*106873 << endl;
  // cout << (106874*106873)%z << endl;


  return 0;
}