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

  int n, k, x;

  cin >> n >> k;

  int dp[257];
  int memo[257];


  for (int i = 0; i < 256; i++) {
    dp[i] = INF;
    memo[i] = 0;
  }


  // cout << n << endl << k << endl;

  for (int i = 0; i < n; i++) {
    bool cases = false;
    cin >> x;
    if (i != 0)
      cout << " ";
    if (dp[x] == INF) {
      int dum = max(0, x+1-k);
      // cout << endl << "mulai" << endl << dum << endl << x << endl << "hai" << endl << x+1-k << "test" << endl;
      for (int j = x; j >= dum; j--) {
        if (dp[j] != INF) {
          // cout << k - memo[j] << endl << (x-dum+1) << endl << "test" << endl;
          if (k - memo[j] >= (x-j)) {
            cases = true;
          }
          dum = j+1;
          break;
        }
      }
      if (!cases) {
        int mem = x-dum+1;
        for (int j = dum; j <= x; j++) {
          dp[j] = dum;
          memo[j] = mem;
        }
      } else {
        // cout << endl << "Test" << endl;
        for (int j = dum; j <= x; j++) {
          dp[j] = dp[dum-1];
          memo[j] = memo[dum-1] + (x-dum+1);
        }
      }
      cout << dp[x];
    } else {
      // cout << endl << "mulai" << endl << dp[i] << endl << x << endl << "hai" << endl;
      cout << dp[x];
    }
  }

  cout << endl;

  // for (int i = 0; i < 256; i++) {
  //   cout << dp[i] << " ";
  // }
  
  // for (int i = 0; i < 256; i++) {
  //   cout << memo[i] << " ";
  // }
  return 0;
}