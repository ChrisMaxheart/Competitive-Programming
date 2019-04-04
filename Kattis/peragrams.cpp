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

  int arr[150];
  for (int i =0 ; i < 130; i++)
    arr[i] = 0;

  for (int i = 0; i < x.length(); i++)
    arr[int(x[i])]++;

  int apus = 0;

  for (int i = 0; i < 130; i++)
    if (arr[i]%2)
      apus++;

    cout << max(0, apus-1) << endl;

  return 0;
}