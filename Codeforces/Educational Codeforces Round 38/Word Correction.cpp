#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

bool reversecompare(int a, int b)
{
  return a > b;
}

bool isvowel(char x) {
  return ((x == 'a') || (x == 'e') || (x == 'i') || (x == 'o') || (x =='u') || (x == 'y'));
}

int main ()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  char x, y;

  y = 'x';
  cin >> N;

  while(N--) {
    cin >> x;
    if (isvowel(x) && isvowel(y))
      continue;
    else {
      cout << x;
      y = x;
    }
  }
  cout << endl;

  return 0;
}