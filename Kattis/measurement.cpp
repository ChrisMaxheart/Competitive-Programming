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
    int to;
    double dist;
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

  bool grafcheck[8];
  double graf[8];
  vector<vector<mystruct>> AL;


  void dfs(double multi, int curr, int to) {
    graf[curr] = multi;
    grafcheck[curr] = false;
    for (auto xx : AL[curr]) {
      if (!grafcheck[xx.to]) {
        continue;
      } else {
        dfs(xx.dist*multi, xx.to, to);
      }
    }
  }

int main ()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  umapsi mymap;

  mymap["thou"] = 0;
  mymap["th"] = 0;
  mymap["inch"] = 1;
  mymap["in"] = 1;
  mymap["foot"] = 2;
  mymap["ft"] = 2;
  mymap["yard"] = 3;
  mymap["yd"] = 3;
  mymap["chain"] = 4;
  mymap["ch"] = 4;
  mymap["furlong"] = 5;
  mymap["fur"] = 5;
  mymap["mile"] = 6;
  mymap["mi"] = 6;
  mymap["league"] = 7;
  mymap["lea"] = 7;


  for (int i = 0; i < 8; i++) {
    vector<mystruct> newvect;
    AL.push_back(newvect);
    grafcheck[i] = true;
  }

  double myarr[] = {1000, 12, 3, 22, 10, 8, 3};



  for (int i = 0; i < 7; i++) {
    mystruct newpoint;
    newpoint.to = i+1;
    newpoint.dist = 1.00000000/myarr[i];
    AL[i].push_back(newpoint);
    newpoint.to = i;
    newpoint.dist = myarr[i];
    AL[i+1].push_back(newpoint);
  }

  int counter = 1;

  double x;

  string y, z;

  cin >> x >> y >> z >> z;
  dfs(x, mymap[y], mymap[z]);
  // cout << x << y << z << mymap[y] << mymap[z] << endl;

  cout << setprecision(15) << graf[mymap[z]] << endl;

  return 0;
}