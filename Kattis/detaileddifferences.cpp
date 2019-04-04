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

  string a, b, final;
  int N;

  cin >> N;
  while (N--) {
    final = "";
    cin >> a >> b;

    for (int i = 0; i < a.length(); i++) {
      if (a[i] == b[i])
        final += ".";
      else
        final += "*";
    }
    cout << a << endl << b << endl << final << endl << endl;
  }
    
  return 0;
}