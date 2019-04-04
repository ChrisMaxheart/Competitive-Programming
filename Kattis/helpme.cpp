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

  };

// pq/set custom comparator, will get reversed
  class mycomp {
    public:
    bool operator() (string a, string b) {
      if (a[1] == b[1]) {
        return a[0] < b[0];
      }
      return a[1] < b[1]; 
    }
  };

  class mycomp2 {
    public:
    bool operator() (string a, string b) {
      if (a[1] == b[1]) {
        return a[0] < b[0];
      }
      return a[1] > b[1]; 
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

  string x;

  map<string, set<string, mycomp>> chessboard;

  for (int i = 8; i >= 1; i--) {
    cin >> x;
    cin >> x;
    int counter = 0;
    for (auto y : x) {
      if (y == '|') {
        counter++;
      }
      if (y != ':' && y != '.') {
        string a = "";
        string b = "";
        string dummy = "";
        a += (counter-1+'a');
        b += (i+'0');
        chessboard[dummy+y].insert(a+b);
      }
    }
  }

  cout << "White: ";
  string ans = "";
  if (chessboard["K"].size())
  for (auto y : chessboard["K"]) {
    ans += "K";
    ans += y;
    ans += " ";
  }
  for (auto y : chessboard["Q"]) {
    ans += "Q";
    ans += y;
    ans += " ";
  }
  for (auto y : chessboard["R"]) {
    ans += "R";
    ans += y;
    ans += " ";
  }
  for (auto y : chessboard["B"]) {
    ans += "B";
    ans += y;
    ans += " ";
  }
  for (auto y : chessboard["N"]) {
    ans += "N";
    ans += y;
    ans += " ";
  }

  for (auto y : chessboard["P"]) {
    ans += y;
    ans += " ";
  }

  if (ans != "") {
    for (int i = 0; i < ans.length()-1; i++) {
      if (ans[i] == ' ') {
        ans[i] = ',';
      }
    }

    cout << ans << endl;
  } else {
    cout << endl;
  }

  cout << "Black: ";
  ans = "";
  set<string, mycomp2> dum;
  for (auto y : chessboard["k"]) {
    dum.insert(y);
  }
  for (auto y: dum) {
    ans += "K";
    ans += y;
    ans += " ";
  }
  dum.clear();
  for (auto y : chessboard["q"]) {
    dum.insert(y);
  }
  for (auto y: dum) {
    ans += "Q";
    ans += y;
    ans += " ";
  }
  dum.clear();
  for (auto y : chessboard["r"]) {
    dum.insert(y);
  }
  for (auto y: dum) {
    ans += "R";
    ans += y;
    ans += " ";
  }
  dum.clear();
  for (auto y : chessboard["b"]) {
    dum.insert(y);
  }
  for (auto y: dum) {
    ans += "B";
    ans += y;
    ans += " ";
  }
  dum.clear();
  for (auto y : chessboard["n"]) {
    dum.insert(y);
  }
  for (auto y: dum) {
    ans += "N";
    ans += y;
    ans += " ";
  }
  dum.clear();
  for (auto y : chessboard["p"]) {
    dum.insert(y);
  }
  for (auto y: dum) {
    ans += y;
    ans += " ";
  }
  dum.clear();
  if (ans != "") {
    for (int i = 0; i < ans.length()-1; i++) {
      if (ans[i] == ' ') {
        ans[i] = ',';
      }
    }

    cout << ans << endl;
  } else {
    cout << endl;
  }


  return 0;
}