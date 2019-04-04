#include <bits/stdc++.h>

using namespace std;

// defines
  #define PI 3.14159265359
  #define INF 1E9
  #define Tloop int T; cin >> T; for(int count_ = 1; count_ < T+1; count_++)
  #define Nloop int N; cin >> N; for(int count__ = 0; count__ < N; count__++)
  #define printcaseg cout << "Case #" << count_ << ": "
  #define printcaseu cout << "Case " << count_ << ": "

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

  
  int T;
  bool first = true;
  while (cin >> T, T) {
    if (first) {
      first = false;
    } else {
      cout << endl;
    }
    int pile1 = 0;
    int pile2 = 0;
    int countdrop = 0;
    int counttake = 0;
    qs order;
    qi no;
    for (int i = 0; i < T; i++) {
      string x;
      int y;

      cin >> x >> y;
      order.push(x);
      no.push(y);
      if (x == "DROP") {
        countdrop++;
      } else {
        counttake++;
      }
      
    }
    while(order.size() != 0) {
      string x = order.front();
      order.pop();
      int y = no.front();
      no.pop();
      if (x == "DROP") {
        cout << "DROP 1 " << y << endl;
        pile1 += y;
      } else {
        if (y > pile2) {
          if(pile2 != 0) {
              cout << "TAKE 2 " << pile2 << endl;
              y -= pile2;
              pile2 = 0;
          }
          cout << "MOVE 1->2 " << pile1 << endl;
          pile2 = pile1;
          pile1 = 0;
          cout << "TAKE 2 " << y << endl;
          pile2 -= y;
        } else {
          cout << "TAKE 2 " << y << endl;
          pile2 -= y;
        }
      }
    }
      
  }
  return 0;
}