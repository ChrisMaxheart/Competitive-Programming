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
  char current;

  int count1, count2, count3;

  count1 = 0;
  count2 = 0;
  count3 = 0;

  cin >> x;
  for (int i = 0; i < x.length(); i++) {
    if (i == 0) {
      current = x[0];
      continue;
    }
    if (i == 1) {
      if (x[1] != current) {
        count1++;
        count2++;
        count3++;
      }
      if (x[1] == 'U') count2++;
      if (x[1] == 'D') count1++;
      current = x[1];
      continue;
    }
    if (x[i] == 'U') count2 += 2;
    if (x[i] == 'D') count1 += 2;
    if (x[i] != current) count3++;
    current = x[i];
  }

  cout << count1 << endl << count2 << endl << count3 << endl;

  return 0;
}