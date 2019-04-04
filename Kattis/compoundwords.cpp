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

  unordered_set<string> masukan;
  set<string> keluaran;
  string s;

  while(cin >> s) {
    masukan.insert(s);
  } 

  for (auto &s1 : masukan) {
    for (auto &s2 : masukan) {
      if (s1 != s2) {
        keluaran.insert(s1+s2);
      }
    }
  }

  for (auto &s1 : keluaran) {
    cout << s1 << endl;
  }

  return 0;
}