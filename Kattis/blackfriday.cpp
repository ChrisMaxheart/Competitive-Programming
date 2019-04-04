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

  int N, x;
  int arr[8];
  int parti[110];
  int unique = 0;

  for (int i = 0; i < 7; i++)
    arr[i] = 0;

  cin >> N;
  int dummy = N;
  while (N--) {
    cin >> x;
    arr[x]++;
    parti[dummy-N-1] = x;
  }

  for (int i = 1; i < 7; i++) {
    if (arr[i] == 1) {
      unique = i;
    }
  }

  if (unique) {
    for (int i = 0; i < dummy; i++)
      if (parti[i] == unique)
        cout << i+1 << endl;
  }
  else cout << "none" << endl;

  return 0;
}