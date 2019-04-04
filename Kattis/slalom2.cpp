#include <bits/stdc++.h>

using namespace std;

// to minimize
  // defines
    const double PI = acos(-1);
    #define INF 1E9
    #define endl '\n'
    #define Tloop int T; cin >> T; for(int count_ = 1; count_ < T+1; count_++)
    #define Nloop int N; cin >> N; for(int count__ = 0; count__ < N; count__++)
    #define printcaseg cout << "Case #" << count_ << ": "
    #define printcaseu cout << "Case " << count_ << ": "
    #define MOD 1000000007
    #define LSOne(S) ((S)&(-S))
    #define pb push_back
    #define fi first
    #define se second

  // A lot of typedefs
    typedef long long ll;
    typedef unsigned long long ull;
    typedef stack<int> si;
    typedef stack<long long> sll;
    typedef stack<string> ss;
    typedef stack<double> sd;
    typedef queue<int> qi;
    typedef queue<long long> qll;
    typedef queue<string> qs;
    typedef queue<double> qd;
    typedef deque<int> di;
    typedef deque<long long> dll;
    typedef deque<string> ds;
    typedef deque<double> dd;
    typedef priority_queue<int> pqi;
    typedef priority_queue<long long> pqll;
    typedef priority_queue<string> pqs;
    typedef priority_queue<double> pqd;
    typedef set<int> seti;
    typedef set<long long> setll;
    typedef set<string> sets;
    typedef set<double> setd;
    typedef unordered_set<int> useti;
    typedef unordered_set<long long> usetll;
    typedef unordered_set<string> usets;
    typedef unordered_set<double> usetd;
    typedef map<int, string> mapis;
    typedef map<string, int> mapsi;
    typedef map<long long, string> maplls;
    typedef map<string, long long> mapsll;
    typedef map<int, int> mapii;
    typedef map<string, string> mapss;
    typedef map<long long, long long> mapllll;
    typedef map<long long, double> maplld;
    typedef map<double, long long> mapdll;
    typedef map<string, double> mapsd;
    typedef map<double, string> mapds;
    typedef map<int, double> mapid;
    typedef map<double, int> mapdi;
    typedef unordered_map<int, string> umapis;
    typedef unordered_map<string, int> umapsi;
    typedef unordered_map<long long, string> umaplls;
    typedef unordered_map<string, long long> umapsll;
    typedef unordered_map<int, int> umapii;
    typedef unordered_map<string, string> umapss;
    typedef unordered_map<long long, long long> umapllll;
    typedef unordered_map<long long, double> umaplld;
    typedef unordered_map<double, long long> umapdll;
    typedef unordered_map<string, double> umapsd;
    typedef unordered_map<double, string> umapds;
    typedef unordered_map<int, double> umapid;
    typedef unordered_map<double, int> umapdi;
    typedef vector<int> vi;
    typedef vector<long long> vll;
    typedef vector<string> vs;
    typedef vector<double> vd;
    typedef pair<int, int> pii;
    typedef pair<int, string> pis;
    typedef pair<long long, long long> pllll;
    typedef pair<long long, string> plls;
    typedef pair<double, string> pds;
    typedef pair<double, double> pdd;
    typedef pair<double, int> pdi;
    typedef pair<double, long long> pdll;

  // struct
    struct mystruct {
      int counter;
    };

  //custom hashing
    struct custom_hash {
      inline std::size_t operator()(const std::pair<int,int> & v) const {
          return v.first*31+v.second*7;
      }
    };

  // pq/set custom comparator, will get reversed
    class mycomp {
      public:
      bool operator() (mystruct a, mystruct b) {
        return a.counter > b.counter; 
      }
    };

  // sort custom comparator
    bool customcompare(mystruct a, mystruct b) {
      return a.counter > b.counter;
    }

int main ()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int W, v, N;

  cin >> W >> v >> N;

  vi xlst, ylst;

  for (int i = 0; i < N; i++) {
    int x, y;
    cin >> x >> y;
    xlst.pb(x);
    ylst.pb(y);
  }

  int vleft = 1;
  int vright = 1E6 + 1;
  int vmid = -1;

  int vsave = 0;
  // cout << N << endl;
  for (int j = 0; j < 50; j++) {
    vmid = (vleft+vright)/2;

    bool can = true;

    double left = double(xlst[0]);
    double right = double(xlst[0] + W);

    for (int i = 1; i < N; i++) { 
      double dy = ylst[i]-ylst[i-1];
      double dt = dy/vmid;
      double dx = v * dt;
      left = max(left-dx, double(xlst[i]));
      right = min(right+dx, double(xlst[i])+double(W));
      // cout << N << endl;
        // cout << "left " << 
      // cout << i << endl;
      // cout << "left " << left << " right " << right << endl;
      if (left > right) {
        // cout << "test" << endl;
        can = false;
        break;
      }
    }
    if (can) {
      vleft = vmid+1;
      vsave = max(vsave, vmid);
    } else {
      vright = vmid-1;
    }
    // cout << vmid << " " << vleft << " " << vright << endl;
    // if (vright < vleft) {
    //   break;
    // }
  }
  // cout << vmid << endl;
  int maxi = 0;

  int S;
  cin >> S;
  while(S--) {
    int x;
    cin >> x;
    if (double(x) <= vsave) {
      maxi = max(maxi, x);
    }
  }
  if (maxi == 0) {
    cout << "IMPOSSIBLE" << endl;
  } else {
    cout << maxi << endl;
  }



  return 0;
}