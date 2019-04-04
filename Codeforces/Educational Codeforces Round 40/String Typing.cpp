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
  string x;

  cin >> N >> x;

  int i = 0;
  string final = "";

  int ans = N;
  int memo = 0;
  string dummy, dum2;



  for(int i = 0; i < N/2; i++) {
    dummy = "";
    dum2 = "";
    for (int j = 0; j < i+1; j++)
      dummy += x[j];
    for (int j = 0; j < 2*(i+1); j++)
      dum2 += x[j];
    dummy += dummy;
    if (dummy == dum2) {
      memo = i;
    }
  }
  cout << ans-memo << endl;  

  return 0;
}