#include <bits/stdc++.h>

using namespace std;

// defines
  #define PI 3.14159265359
  #define INF 1E9
  #define Tloop int T; cin >> T; for(int count_ = 1; count_ < T+1; count_++)
  #define Nloop int N; cin >> N; for(int count__ = 0; count__ < N; count__++)
  #define printcaseg cout << "Case #" << count_ << ": "
  #define printcaseu cout << "Case " << count_ << ": "
  #define MOD (1E9 + 7)

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
  struct mystruct {
    int a;
    int b;
  };

// pq/set custom comparator, will get reversed
  class mycomp {
    public:
    bool operator() (int a, int b) {
      return a > b; 
    }
  };

  bool check(string x) {
    bool can = true;
    if (x[0] != '1') {
      can = false;
    }
    for (int i = 1; i < x.length(); i++) {
      if (can == false) {
        break;
      }
      if (i%2 && x[i] == '1') {
        can = false;
      } else if (i%2 == 0 && x[i]=='0') {
        can = false;
      }
    }
    return can;
  }

  mystruct counta(string x) {
    int countera = 1;
    int counterb = 0;

    for (int i = 1; i <= x.length(); i++) {
      if (x[i] == '1') {
        countera += counterb;
      } else {
        counterb += countera;
      }
    }

    mystruct final;
    final.a = countera;
    final.b = counterb;
    return final;
  }

// sort custom comparator
  bool customcompare(int a, int b) {
    return a > b;
  }

int main ()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  bool found = false;

  // string ans = "";

  string dummy;

  cin >> dummy;

  int A, B, Q;
  mystruct test = counta("1101");
  cout << test.a << endl;
  cout << test.b << endl;
  cin >> A >> B >> Q;
  string final;
  char myarr[55];
  myarr[0] = '0';
  int dum3 = (A+B)/2 + 1;
  for (int i = 1; i < min((A+B)+1,54); i++) {
    myarr[i] = '1';
  }

  for (int i = min((A+B),54); i < 54; i++) {
    myarr[i] = '0';
  }
  // for (int i = 0; i < 54; i++) {
  //   cout << myarr[i];
  // }
  // cout << endl;
  while(next_permutation(myarr, myarr+2*A+2*B+1)) {
    string ans = "";
    if (found) {
      break;
    }
    for (int i = 0; i < (A+B); i++) {
      if (found) {
        break;
      }
      ans += myarr[i];
      if(check(ans)) {
        mystruct dum;
        dum = counta(ans);
        // cout << dum.a << " and " << dum.b << endl;
        if (dum.a == A && dum.b == B) {
          final = ans;
          found = true;
        }
      }
    }
    cout << ans << endl;
  }

  if (found) {
    cout << "MUNGKIN" << endl;
    for (int i = 0; i < Q; i++) {
      int x, y;
      cin >> x >> y;
      if (y >= final.length() || x >= final.length()) {
        cout << "DI LUAR BATAS" << endl;
      } else {
        cout << final.substr(x, y-x+1) << endl;
      }
    }
  } else {
    cout << "TIDAK MUNGKIN" << endl;
  }

  return 0;
}