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

  int n1, n2;

  cin >> n1 >> n2;

  int cara1, cara2;

  if (n2 < n1) {
    cara1 = n2+360-n1;
  } else {
    cara1 = n2-n1;
  }

  if (n1 < n2) {
    cara2 = n1+360-n2;
  } else {
    cara2 = n1 - n2;
  }

  if (abs(cara1) <= abs(cara2)) {
    cout << cara1 << endl;
  } else {
    cout << cara2*-1 << endl;
  }

  return 0;
}