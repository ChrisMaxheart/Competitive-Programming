#include <bits/stdc++.h>

using namespace std;

#define PI 3.14159265359
#define INF 1E9
#define Tloop int T; cin >> T; for(int i = 1; i < T+1; i++)
#define Nloop int N; cin >> N; for(int j = 0; j < N; j++)
#define printcaseg cout << "Case #" << i << ": "
#define printcaseu cout << "Case " << i << ": "

// Disclaimer: all this typedef only used for competitive programming
//             will not use it in a proper other codes
typedef long long ll;
typedef unsigned long long ull;

struct mystruct {

};

// pq bakal kebalik
class mycomp
{
  public:
  bool operator() (int a, int b) {
    return a > b; 
  }
};

bool customcompare(int a, int b) {
  return a > b;
}

int main ()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;

  bool dum = false;

  while (cin >> N) {
    if (dum) {
      cout << endl;
    }
    dum = true;
    vector<string> names;
    string x;
    for (int i = 0; i < N; i++) {
      cin >> x;
      names.push_back(x);
    }
    unordered_map<string, int> net;
    for (auto y : names) {
      net[y] = 0;
    }
    string giver, taker;
    int amt, nooftarget;
    for (int i = 0; i < N; i++) {
      cin >> giver >> amt >> nooftarget;
      if (nooftarget == 0) {
        continue;
      }
      // net[giver] += amt%nooftarget;
      for (int j = 0; j < nooftarget; j++) {
        cin >> x;
        // cout << giver << " to " << x << " sebanyak " << amt/nooftarget << endl;
        net[x] += amt/nooftarget;
        net[giver] -= amt/nooftarget;
      }
    }
    for (auto y : names) {
      cout << y << " " << net[y] << endl;
    }
    // cout << endl;
  }

  return 0;
}