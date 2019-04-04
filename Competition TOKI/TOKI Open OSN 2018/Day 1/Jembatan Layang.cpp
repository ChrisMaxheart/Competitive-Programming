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
  struct bridge {
    int loc;
    seti fromless, toless, frommore, tomore, fromequal, toequal;
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

ll modfactorial(ll a) {
  ll final = 1;
  for (ll i = 2; i <= a; i++) {
    final *= i;
    final = final % MOD;
  }
  return final;
}

int main ()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string dumm;

  cin >> dumm;

  int N, K;

  cin >> N >> K;

  vector<bridge> myvect;

  for (int i = 0; i < K; i++) {
    int x;
    cin >> x;
    x--;
    bridge newbridge;
    newbridge.loc = x;
    myvect.push_back(newbridge);
  }

  for (int i = 0; i < N; i++) {
    int x;
    cin >> x;
    x--;
    int dummy = myvect[x].loc;

    if (i < dummy) {
      myvect[x].fromless.insert(i);
    } else if (i > dummy) {
      myvect[x].frommore.insert(i);
    } else {
      myvect[x].fromequal.insert(i);
    }
  }

  for (int i = 0; i < N; i++) {
    int x;
    cin >> x;
    x--;
    int dummy = myvect[x].loc;

    if (i < dummy) {
      myvect[x].toless.insert(i);
    } else if (i > dummy) {
      myvect[x].tomore.insert(i);
    } else {
      myvect[x].toequal.insert(i);
    }
  }

  bool can = true;
  ll possibility = 1;
  if (N == 1) {
    possibility = 1;
  }
  else
  for (auto x : myvect) {
    if (!can) {
      break;
    }
    if (x.fromequal.size()==1 && x.toequal.size()==1) {
      if (abs(int(x.fromless.size())-int(x.tomore.size())) <= 1) {
        ll total;
        if (x.fromless.size() == x.tomore.size()) {
          total = modfactorial(x.fromless.size());
          total = total % MOD;
          total *=  modfactorial(x.frommore.size()+1);
          total = total % MOD;
          ll dummy = modfactorial(x.frommore.size());
          dummy = dummy % MOD;
          dummy *= modfactorial(x.fromless.size()+1);;
          dummy = dummy % MOD;
          total += dummy;
          // total = total % MOD;
          // cout << total << endl;
          total-= (ll(modfactorial(x.frommore.size()) *  modfactorial(x.fromless.size())))%MOD;
          total = total%MOD;
          // cout << total << endl;
        } else {
          ll maxi = max(x.fromless.size(), x.tomore.size());
          ll maxi2 = max(x.frommore.size(), x.toless.size());
          total = modfactorial(maxi);
          total = total % MOD;
          total *= modfactorial(maxi2);
          total = total % MOD;
        }
        // cout << total << endl;
        possibility *= total;
        possibility = possibility % MOD;
      } else {
        can = false;
      }
    } else if (x.fromequal.size()==1 || x.toequal.size()==1) {
      if (abs(int(x.fromless.size())-int(x.tomore.size())) <= 1) {
        ll total;
        ll maxi = max(x.fromless.size(), x.tomore.size());
        ll maxi2 = max(x.frommore.size(), x.toless.size());
        total = modfactorial(maxi);
        total = total % MOD;
        total *= modfactorial(maxi2);
        total = total % MOD;
        possibility *= total;
        possibility = possibility % MOD;
      } else {
        can = false;
      }
    } else {
      if (x.fromless.size() == x.tomore.size()) {
        ll total = 1;
        total *= modfactorial(x.fromless.size());
        total = total % MOD;
        total *= modfactorial(x.frommore.size());
        total = total%MOD;
        possibility *= total;
        possibility = possibility % MOD;
      } else {
        can = false;
      }
    }
    // cout << "toless" << x.toless.size() << endl;
    // cout << "tomore" << x.tomore.size() << endl;
    // cout << "toequal" << x.toequal.size() << endl;
    // cout << "fromless" << x.fromless.size() << endl;
    // cout << "frommore" << x.frommore.size() << endl;
    // cout << "fromequal" << x.fromequal.size() << endl;
    // cout << possibility << endl;
  }
  
  if (possibility < 0) {
    possibility += MOD;
  }

  if (can) {
    cout << possibility << endl;
  } else {
    cout << 0 << endl;
  }

  return 0;
}