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

  int counter = 0;

  while (cin >> N, N) {
    counter++;
    cout << "List " << counter << ":" << endl;
    map<string, int> myzoo;
    string x;
    getline(cin, x);
    for (int i = 0; i < N; i++) {
      getline(cin, x);
      istringstream iss(x);
      while(iss >> x) {

      }
      string final = "";
      for (int j = 0; j < x.length(); j++) {
        if (int(x[j]) >= 64 && int(x[j]) <= 92) {
          final += char(int(x[j]) + 32);
        } else {
          final += x[j];
        }
      }
      myzoo[final]++;
    }
    for (auto &z : myzoo) {
      cout << z.first << " | " << z.second << endl;
    } 
  }

  return 0;
}