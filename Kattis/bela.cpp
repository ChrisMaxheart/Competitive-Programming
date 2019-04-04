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

  map<char,int> dom, nondom;

  dom['A'] = 11;
  dom['K'] = 4;
  dom['Q'] = 3;
  dom['J'] = 20;
  dom['T'] = 10;
  dom['9'] = 14;

  nondom['A'] = 11;
  nondom['K'] = 4;
  nondom['Q'] = 3;
  nondom['J'] = 2;
  nondom['T'] = 10;
  nondom['9'] = 0;

  int N, final;
  string x;
  char trump;

  cin >> N >> trump;

  final = 0;

  for (int i = 0; i < 4*N; i++) {
    cin >> x;
    if (x[1] == trump) {
      final += dom[x[0]];
      // cout << x[1];
    }
    else
      final += nondom[x[0]];    
  }

  cout << final << endl;

  return 0;
}