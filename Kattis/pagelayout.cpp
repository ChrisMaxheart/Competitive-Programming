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

bool singleintersect(int x1, int l1, int x2, int l2) {
  if (x2 < x1+l1 && x2+l2 > x1) {
    return true;
  } else {
    return false;
  }
}

bool intersect(int x1, int y1, int h1, int l1, int x2, int y2, int h2, int l2) {
  if (singleintersect(x1, l1, x2, l2) && singleintersect(y1, h1, y2, h2)) {
    return true;
  } else {
    return false;
  }
}

vi xlst;
vi ylst;
vi llst;
vi hlst;
vll ttlarea;

ll maxi = -1;

void recurs(int curr, ll currarr, vi lst) {
  if (curr == ttlarea.size()) {
    maxi = max(maxi, currarr);
    return;
  }
  if (curr != 0 && currarr + ttlarea[curr-1] <= maxi) {
    return;
  }
  recurs(curr+1, currarr, lst);
  bool can = true;
  for (int i = 0; i < lst.size(); i++) {
    int obj1 = lst[i];
    int obj2 = curr;
    if (intersect(xlst[obj1], ylst[obj1], hlst[obj1], llst[obj1], xlst[obj2], ylst[obj2], hlst[obj2], llst[obj2])) {
      can = false;
      break;
    }
  }
  if (can) {
    lst.pb(curr);
    recurs(curr+1, currarr + llst[curr]*hlst[curr], lst);
  }
  return;
}

int main ()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;

  while(cin >> N, N) {
    xlst.clear();
    ylst.clear();
    llst.clear();
    hlst.clear();
    ttlarea.clear();
    maxi = -1;
    int x, y, l, h;

    for (int i = 0; i < N; i++) {
      cin >> l >> h >> x >> y;
      xlst.pb(x);
      ylst.pb(y);
      hlst.pb(h);
      llst.pb(l);
      ttlarea.pb(h*l);
    }
    ll total = 0;
    for (int i = 0; i < N; i++) {
      total += ttlarea[i];
    }

    for (int i = 0; i < N; i++) {
      if (i == 0) {
        ttlarea[i] = total - ttlarea[i];
      } else {
        ttlarea[i] = ttlarea[i-1] - ttlarea[i];
      }
    }
    vi newvi;
    recurs(0, 0, newvi);
    cout << maxi << endl;
  }

  return 0;
}