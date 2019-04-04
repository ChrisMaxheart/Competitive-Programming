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

  int T;

  cin >> T;
  
  set<string> inside;

  inside.insert("zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz");

  while(T--) {
    string name, action;

    cin >> action >> name;

    if (action == "entry") {
      if (inside.find(name) != inside.end()) {
        cout << name << " entered (ANOMALY)" << endl;
      } else {
        inside.insert(name);
        cout << name << " entered" << endl; 
      }
    } else {
      if (inside.find(name) != inside.end()) {
        inside.erase(name);
        cout << name << " exited" << endl;
      } else {
        cout << name << " exited (ANOMALY)" << endl;
      }
    }
  }

  return 0;
}