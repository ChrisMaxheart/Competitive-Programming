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

  int months, N;
  double cicil, dp;

  while(cin >> months >> cicil >> dp >> N, months >= 0) {
    double loan = dp;
    double qual = dp+cicil;
    double bayar = dp/double(months);
    double dep = 0.000;
    map<int, double> mymap;
    while(N--) {
      int mon;
      string dum;
      double percent;
      cin >> mon >> dum;
      dum = '0' + dum;
      percent = stod(dum);
      mymap[mon] = percent;
    }
    qual *= (1.0 - mymap[0]);
    dep = mymap[0];
    if (loan < qual) {
      cout << "0 months" << endl;
      continue;
    }
    for (int i = 0; i < months; i++) {
      if (mymap[i+1] != 0) {
        dep = mymap[i+1];
      }
      qual *= (1.000000 - dep);
      loan -= bayar;
      // cout << "bulan ke " << i+1 << " loan " << loan << " qual " << qual << " kurang qual " << dep << endl;
      if (loan < qual) {
        cout << i+1;
        if ( i == 0) {
          cout << " month" << endl;
        } else {
          cout << " months" << endl;
        }
        break;
      }
    }
  }

  return 0;
}