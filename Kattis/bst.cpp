#include <bits/stdc++.h>

using namespace std;

// defines
  #define PI 3.14159265359
  #define INF 1E9
  #define Tloop ll T; cin >> T; for(ll count_ = 1; count_ < T+1; count_++)
  #define Nloop ll N; cin >> N; for(ll count__ = 0; count__ < N; count__++)
  #define prllcaseg cout << "Case #" << count_ << ": "
  #define prllcaseu cout << "Case " << count_ << ": "
  #define MOD 1000000007

// A lot of typedefs
  typedef long long ll;
  typedef unsigned long long ull;
  typedef stack<ll> si;
  typedef stack<long long> sll;
  typedef stack<string> ss;
  typedef stack<double> sd;
  typedef queue<ll> qi;
  typedef queue<long long> qll;
  typedef queue<string> qs;
  typedef queue<double> qd;
  typedef deque<ll> di;
  typedef deque<long long> dll;
  typedef deque<string> ds;
  typedef deque<double> dd;
  typedef priority_queue<ll> pqi;
  typedef priority_queue<long long> pqll;
  typedef priority_queue<string> pqs;
  typedef priority_queue<double> pqd;
  typedef set<ll> seti;
  typedef set<long long> setll;
  typedef set<string> sets;
  typedef set<double> setd;
  typedef unordered_set<ll> useti;
  typedef unordered_set<long long> usetll;
  typedef unordered_set<string> usets;
  typedef unordered_set<double> usetd;
  typedef map<ll, string> mapis;
  typedef map<string, ll> mapsi;
  typedef map<long long, string> maplls;
  typedef map<string, long long> mapsll;
  typedef map<ll, ll> mapii;
  typedef map<string, string> mapss;
  typedef map<long long, long long> mapllll;
  typedef map<long long, double> maplld;
  typedef map<double, long long> mapdll;
  typedef map<string, double> mapsd;
  typedef map<double, string> mapds;
  typedef map<ll, double> mapid;
  typedef map<double, ll> mapdi;
  typedef unordered_map<ll, string> umapis;
  typedef unordered_map<string, ll> umapsi;
  typedef unordered_map<long long, string> umaplls;
  typedef unordered_map<string, long long> umapsll;
  typedef unordered_map<ll, ll> umapii;
  typedef unordered_map<string, string> umapss;
  typedef unordered_map<long long, long long> umapllll;
  typedef unordered_map<long long, double> umaplld;
  typedef unordered_map<double, long long> umapdll;
  typedef unordered_map<string, double> umapsd;
  typedef unordered_map<double, string> umapds;
  typedef unordered_map<ll, double> umapid;
  typedef unordered_map<double, ll> umapdi;
  typedef vector<ll> vi;
  typedef vector<long long> vll;
  typedef vector<string> vs;
  typedef vector<double> vd;
  typedef pair<ll, ll> pii;
  typedef pair<ll, string> pis;
  typedef pair<long long, long long> pllll;
  typedef pair<long long, string> plls;
  typedef pair<double, string> pds;
  typedef pair<double, double> pdd;
  typedef pair<double, ll> pdi;
  typedef pair<double, long long> pdll;

// struct
  struct mystruct {
    ll root = 0;
    ll left = 0;
    ll right = 0;
  };

  struct custom_hash {
    inline std::size_t operator()(const std::pair<ll,ll> & v) const {
        return v.first*31+v.second*7;
    }
  };

// pq/set custom comparator, will get reversed
  class mycomp {
    public:
    bool operator() (ll a, ll b) {
      return a > b; 
    }
  };

// sort custom comparator
  bool customcompare(mystruct a, mystruct b) {
    return a.root > b.root;
  }

  bool isNumber(string line){
    char* p;
    strtol(line.c_str(), &p, 10);
    return *p == 0;
  }

int main ()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

// do later, 1) make map 2) depth = depth +1, check element sebelum n sesudah, terus itu = max(sebelum, sesudah)+1
  mapllll mymap;

  ll counter = 0;

  Nloop {
    ll subcounter = 0;
    ll x;

    cin >> x;

    if (count__ == 0) {
      mymap[x] = 0;
    } else {
      auto myit = mymap.lower_bound(x);
      auto aft = myit;
      auto bef = myit;
      ll daft, dbef;
      if (aft == mymap.end()) {
        daft = 0;
      } else {
        daft = aft->second;
      }
      if (aft == mymap.begin()) {
        dbef = 0;
      } else {
        --bef;
        dbef = bef->second;
      }


      mymap[x] = max(dbef, daft)+1;
      subcounter = mymap[x];
    }

    counter += subcounter;
    cout << counter << endl;
  }

  return 0;
}