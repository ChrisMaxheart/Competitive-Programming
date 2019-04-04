#include <bits/stdc++.h>

using namespace std;

#define PI 3.14159265359
#define INF 1E9
#define Tloop int T; cin >> T; for(int i = 1; i < T+1; i++)
#define Nloop int N; cin >> N; for(int j = 0; j < N; j++)
#define printcase cout << "Case #" << i << ": "

// Disclaimer: all this typedef only used for competitive programming
//             will not use it in a proper other codes
typedef long long ll;
typedef unsigned long long ull;

struct mystruct {

};

  ll interest[205];

// pq bakal kebalik
class mycomp
{
  public:
  bool operator() (int a, int b) {
    return a > b; 
  }
};

bool customcompare(int a, int b) {
  return interest[a] < interest[b];
}

int main ()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, T, x;

  cin >> T;

  for (int i = 0; i < 203; i++) {
    interest[i] = 0;
  }

  while(T--) {
    bool avail[205];
    for (int i = 0; i < 203; i++) {
      avail[i] = true; 
    }
    cin >> N;
    while(N--) {
      cin >> x;
      bool found = false;
      if (x == 0) {
        cout << -1 << endl;
        cout.flush();
        continue;
      }
      int dummy[205];
      for (int i = 0 ; i < x; i++) {
        cin >> dummy[i];
        interest[dummy[i]]++;
      }
      stable_sort(dummy, dummy+x, customcompare);
      for (int i = 0; i < x; i++) {
        if (avail[dummy[i]]) {
          // cerr << "haihai" << endl;
          avail[dummy[i]] = false;
          cout << dummy[i] << endl;
          cout.flush();
          // cout << flush;
          found = true;
          break;
        }
      }
      if (!found) {
        cout << -1 << endl;
        cout.flush();
      }
      // cerr << "test" << N <<"dan" << T << endl;
    }
  }  

  return 0;
}