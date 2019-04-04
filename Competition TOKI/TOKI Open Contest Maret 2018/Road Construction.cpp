#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

bool reversecompare(int a, int b)
{
  return a > b;
}

ll dptable[100010][3];
ll priceA[100010];
ll priceB[100010];
ll priceC[100010];
ll pricecon[100010];


int main ()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;

  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> priceA[i];
  }

  for (int i = 0; i < N; i++) {
    cin >> priceB[i];
  }

  for (int i = 0; i < N; i++) {
    cin >> priceC[i];
  }

  for (int i = 1; i < N; i++) {
    cin >> pricecon[i];
  }

  ll kalauA, kalauB, kalauC;

  dptable[0][0] = priceA[0];
  dptable[0][1] = priceB[0];
  dptable[0][2] = priceC[0];
  

  for (int i = 1; i < N; i++) {
    dptable[i][0] = min(dptable[i-1][0], min(dptable[i-1][1], dptable[i-1][2]) + pricecon[i])+priceA[i];
    dptable[i][1] = min(dptable[i-1][1], min(dptable[i-1][0], dptable[i-1][2]) + pricecon[i])+priceB[i];
    dptable[i][2] = min(dptable[i-1][2], min(dptable[i-1][1], dptable[i-1][0]) + pricecon[i])+priceC[i];
  }

  cout << min(min(dptable[N-1][2], dptable[N-1][0]), dptable[N-1][1]) << endl;

  // for (int i = 0; i < N; i++) {
  //   cout << dptable[i][0] << " " << dptable[i][1] << " " << dptable[i][2] << endl;
  // }

  return 0;
}