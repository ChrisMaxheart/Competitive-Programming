#include <bits/stdc++.h>

using namespace std;

// defines
  #define PI 3.14159265359
  #define INF 1E9
  #define Tloop int T; cin >> T; for(int i = 1; i < T+1; i++)
  #define Nloop int N; cin >> N; for(int j = 0; j < N; j++)
  #define printcaseg cout << "Case #" << i << ": "
  #define printcaseu cout << "Case " << i << ": "

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
    int hours;
    int sphours;
    int mins;
    string ampm;
  };

// pq/set custom comparator, will get reversed
  class mycomp {
    public:
    bool operator() (int a, int b) {
      return a > b; 
    }
  };

// sort custom comparator
  bool customcompare(mystruct a, mystruct b) {
    if (a.ampm == b.ampm) {
      if (a.sphours == b.sphours) {
        return a.mins < b.mins;
      }
      return a.sphours < b.sphours;
    }
    return a.ampm < b.ampm;
  }

int main ()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  bool first = true;
  while(cin >> N, N) {
    if (first) {
      first = false;
    } else {
      cout << endl;
    }
    string tme, ap;
    vector<mystruct> lst;
    for (int i = 0; i < N; i++) {
      cin >> tme >> ap;
      istringstream iss(tme);
      string token;
      vs dummy;
      while(getline(iss, token, ':')) {
        dummy.push_back(token);
      }
      mystruct newstruct;
      newstruct.ampm = ap;
      newstruct.hours = stoi(dummy[0]);
      if (newstruct.hours == 12) {
        newstruct.sphours = 0;
      } else {
        newstruct.sphours = newstruct.hours; 
      }
      newstruct.mins = stoi(dummy[1]);
      lst.push_back(newstruct);
    }
    sort(lst.begin(), lst.end(), customcompare);
    for (auto x : lst) {
      cout << x.hours <<":"; 
      if (x.mins < 10) {
        cout << "0";
      }
        cout << x.mins;
      cout << " " << x.ampm << endl;
    }
  }

  return 0;
}