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

    class FenwickTree {
    private:
      vi ft;
      int n;

    public:
      FenwickTree(int _n) : n(_n) {
        ft.assign(n+1, 0);
      }
      FenwickTree(const vector<int>& f) : n(f.size()-1) {
        ft.assign(n+1, 0);
        for(int i = 1; i <= n; i++) {
          ft[i] += f[i];
          if(i+LSOne(i) <= n) {
            ft[i+LSOne(i)] += ft[i];
          }
        }
      }
      int rsq(int j) {
        int sum = 0;
        for (; j; j-= LSOne(j)) {
          sum += ft[j];
        }
        return sum;
      }
      int rsq(int i, int j) {
        return rsq(j) - rsq(i-1);
      }
      void update(int i, int v) {
        for (; i <= n; i += LSOne(i)) {
          ft[i] += v;
        }
      }
    };

vi curpos;
vll val;
umapsi pos;
vs mylist;

int main ()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;

  cin >> n >> k;

  string word;
  for (int i = 0; i < n; i++) {
    cin >> word;
    mylist.push_back(word);
   } // o(N)

  sort(mylist.begin(), mylist.end()); // O(N log N)

  for (int i = 0; i < n; i++) {
    pos[mylist[i]] = i+1;
  } // O(N)

  string dum = "";

  cin >> word;


  for (int i = 0; i < word.length(); i++) {
    dum += word[i];
    // cout << dum << endl;
    if (pos.find(dum) != pos.end()) {
      curpos.push_back(pos[dum]);
      dum = "";
    }
  } //O(N)

  for (int i = 0; i < k; i++) {
    val.push_back(0);
  } //(O(N))

  for (int i = k-1; i >= 0; i--) {
    if (i == k-1) {
      val[i] = 1;
    } else {
      val[i] = val[i+1] * (n-i-1);
      val[i] = val[i]% MOD;
    }
  } // O(N)

  // for (auto x : val) {cout << x << endl;}

  ll total = 0;
  int counter = 0;

  FenwickTree ft(n);

  for (auto x : curpos) {
    ll minus = ft.rsq(x);
    ft.update(x, 1);
    // cout << x << endl;
    ll temp = val[counter] * (x-1-minus);
    counter++;
    // cout << temp << endl;
    temp = temp % MOD;
    total += temp;
    total = total % MOD; 
  } // O(N log N)
  total++;

  total = total % MOD;

  cout << total << endl;



  return 0;
}