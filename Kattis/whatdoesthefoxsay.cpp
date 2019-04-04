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

  string dummy;
  string a, b, c;


  int N;

  cin >> N;
  getline(cin, dummy);

  while(N--){
    unordered_map<string, int> mymap;
    getline(cin, dummy);
    // cout << dummy << endl;
    istringstream dum(dummy);
    while(true) {
      cin >> a >> b >> c;
      if ((a == "what") && (b == "does") && (c == "the")) {
        cin >> a >> b;
        break;
      }
      mymap[c] = 1;
    }
    while(getline(dum, dummy, ' ')) {
      // cout << dummy << endl;
      if ((mymap[dummy]) == 0)
        cout << dummy << ' ';
    }   
    cout << endl;
    getline(cin, dummy);
  }

  return 0;
}