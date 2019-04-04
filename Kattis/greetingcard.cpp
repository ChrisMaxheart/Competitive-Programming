#include <bits/stdc++.h>

using namespace std;

// defines
  #define PI 3.14159265359
  #define INF 1E9
  #define Tloop int T; cin >> T; for(int count_ = 1; count_ < T+1; count_++)
  #define Nloop int N; cin >> N; for(int count__ = 0; count__ < N; count__++)
  #define printcaseg cout << "Case #" << count_ << ": "
  #define printcaseu cout << "Case " << count_ << ": "
  #define MOD 1000000007

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
    int x, y;
  };

  // namespace std {
  //   template<>
  //   struct hash<mystruct> {
  //     // size_t
  //     operator()(const mystruct&obj) const {
  //       pii dummy = make_pair(hash<int>()(int(obj.x)), hash<int>()(int(obj.y)));
  //       return dummy.first - dummy.second;
  //     }
  //   };
  // }

  struct pair_hash {
    inline std::size_t operator()(const std::pair<int,int> & v) const {
        return v.first*31+v.second*7;
    }
};

// pq/set custom comparator, will get reversed
  class mycomp {
    public:
    bool operator() (int a, int b) {
      return a > b; 
    }
  };

// sort custom comparator
  bool customcompare(int a, int b) {
    return a > b;
  }

int main ()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);


  unordered_set<pii, pair_hash> myset;

  Nloop {
    // cout << N << endl;
    int x, y;
    cin >> x >> y;
    mystruct newstruct;
    newstruct.x = x;
    newstruct.y = y;

    pii dummy = make_pair(x,y);
    // cout << dummy.first << " " << dummy.second << endl;

    myset.insert(dummy);
    // cout << myset.size() << endl;
  }

  // cout << myset.size() << endl;

  int counta = 0;

  for (auto x: myset) {
    bool found = false;
    // cout << x.first << " and " << x.second << endl;
    pii dummy;

    mystruct newstruct;
    newstruct.x = x.first + 2018;
    newstruct.y = x.second;

    dummy = make_pair(newstruct.x, newstruct.y);
    if (myset.find(dummy) != myset.end()) {
      found = true;
      counta++;
    }

    newstruct.x = x.first - 2018;
    newstruct.y = x.second;
    dummy = make_pair(newstruct.x, newstruct.y);
    if (myset.find(dummy) != myset.end()) {
      found = true;
      counta++;
    }

    newstruct.x = x.first;
    newstruct.y = x.second + 2018;
    dummy = make_pair(newstruct.x, newstruct.y);
    if (myset.find(dummy) != myset.end()) {
      found = true;
      counta++;
    }

    newstruct.x = x.first;
    newstruct.y = x.second - 2018;
    dummy = make_pair(newstruct.x, newstruct.y);
    if (myset.find(dummy) != myset.end()) {
      found = true;
      counta++;
    }

    newstruct.x = x.first + 1118;
    newstruct.y = x.second + 1680;
    dummy = make_pair(newstruct.x, newstruct.y);
    if (myset.find(dummy) != myset.end()) {
      found = true;
      counta++;
    }

    newstruct.x = x.first - 1118;
    newstruct.y = x.second + 1680;
    dummy = make_pair(newstruct.x, newstruct.y);
    if (myset.find(dummy) != myset.end()) {
      found = true;
      counta++;
    }

    newstruct.x = x.first + 1118;
    newstruct.y = x.second - 1680;
    dummy = make_pair(newstruct.x, newstruct.y);
    if (myset.find(dummy) != myset.end()) {
      found = true;
      counta++;
    }

    newstruct.x = x.first - 1118;
    newstruct.y = x.second - 1680;
    dummy = make_pair(newstruct.x, newstruct.y);
    if (myset.find(dummy) != myset.end()) {
      found = true;
      counta++;
    }

    newstruct.x = x.first + 1680;
    newstruct.y = x.second + 1118;
    dummy = make_pair(newstruct.x, newstruct.y);
    if (myset.find(dummy) != myset.end()) {
      found = true;
      counta++;
    }

    newstruct.x = x.first - 1680;
    newstruct.y = x.second + 1118;
    dummy = make_pair(newstruct.x, newstruct.y);
    if (myset.find(dummy) != myset.end()) {
      found = true;
      counta++;
    }

    newstruct.x = x.first + 1680;
    newstruct.y = x.second - 1118;
    dummy = make_pair(newstruct.x, newstruct.y);
    if (myset.find(dummy) != myset.end()) {
      found = true;
      counta++;
    }

    newstruct.x = x.first - 1680;
    newstruct.y = x.second - 1118;
    dummy = make_pair(newstruct.x, newstruct.y);
    // cout << dummy.first << dummy.second << endl;
    if (myset.find(dummy) != myset.end()) {
      found = true;
      counta++;
    }

    // if (found) {
    //   counta++;
    // }

  }

  cout << counta/2 << endl;

  return 0;
}