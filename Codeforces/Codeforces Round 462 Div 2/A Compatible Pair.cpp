#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

bool reversecompare(ll a, ll b)
{
  return a > b;
}

ll products1[2550];
ll products2[2550];

int main ()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll T, B;
  ll Tarr[70];
  ll Barr[70];

  cin >> T >> B;
  for (int i = 0; i <T; i++) cin >> Tarr[i];
  for (int i = 0; i <B; i++) cin >> Barr[i];
  
  sort(Tarr, Tarr+T, reversecompare);
  sort(Barr, Barr+B, reversecompare);

  int counter = 0;
  for (int i = 0; i < T-1; i++)
    for (int j = 0; j < B; j++) {
      products1[counter] = Tarr[i]*Barr[j];
      counter++;
    }

  counter = 0;
  for (int i = 1; i < T; i++)
    for (int j = 0; j < B; j++) {
      products2[counter] = Tarr[i]*Barr[j];
      counter++;
    }



  sort(products1, products1+counter, reversecompare);
  sort(products2, products2+counter, reversecompare);

  cout << min(products1[0], products2[0]) << endl;
  return 0;
}