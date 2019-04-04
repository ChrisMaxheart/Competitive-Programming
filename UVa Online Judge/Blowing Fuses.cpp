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

  int n, m, c;
  int counter = 0;
  while (cin >> n >> m >> c, n || m || c) {
    unordered_map<int, int> mymap;
    int consumption = 0;
    int maxconsumption = 0;
    unordered_map<int, bool> condition;
    int x;
    // if(counter) {
    //   cout << endl;
    // }
    counter++;
    for (int i = 1; i <= n; i++) {
      cin >> x;
      mymap[i] = x;
      condition[i] = false;
    }
    for (int i = 1; i <= m; i++) {
      cin >> x;
      if (condition[x]) {
        consumption -= mymap[x];
      } else {
        consumption += mymap[x];
      }
      condition[x] = !condition[x];
      maxconsumption = max(maxconsumption, consumption);
    }
    cout << "Sequence " << counter << endl;
    if (maxconsumption > c) {
      cout << "Fuse was blown." << endl;
    } else {
      cout << "Fuse was not blown." << endl;
      cout << "Maximal power consumption was " << maxconsumption << " amperes." << endl;
    }
    cout << endl;
  }

  return 0;
}