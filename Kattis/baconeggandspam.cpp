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

  while(cin >> N, N) {
    string dummy;
    getline(cin, dummy);
    map<string, set<string>> mymap;
    while(N--) {
      getline(cin, dummy);
      istringstream iss(dummy);
      string name, x;
      iss >> name;
      while(iss >> x) {
        mymap[x].insert(name);
      }
    }
    for (auto &item : mymap) {
        cout << item.first;
        for (auto &human : item.second) {
          cout << " " << human;
        }
        cout << endl;
      }
    cout << endl;
  }

  return 0;
}