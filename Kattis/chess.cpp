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
    bool operator() (int a, int b) {
      return a > b; 
    }
  };

// sort custom comparator
  bool customcompare(int a, int b) {
    return a > b;
  }

int colint(string x) {
  return x[0]-'A'+1;
}

char colstr(int x) {
  return x -1 + 'A';
}

double gradient(double x, double y) {
  return y/x;
}

bool isoneline(double x1, double y1, double x2, double y2) {
  if (y1 == y2) {
    return false;
  } else {
    return abs((y1-y2)/(x1-x2)) == 1;
  }
}

int main ()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Nloop {
    string x1, x2;
    double y1, y2;

    cin >> x1 >> y1 >> x2 >> y2;
    double rx1, rx2;
    rx1 = colint(x1);
    rx2 = colint(x2);
    if (int(rx1+y1)%2 != int(rx2+y2)%2) {
      cout << "Impossible" << endl;
      continue;
    }
    if (rx1 == rx2 && y1 == y2) {
      cout << 0 << " " << x2 << " " << y2 << endl;
      continue;
    }
    if (abs(rx1-rx2) == abs(y1-y2)) {
      cout << 1 << " " << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
      continue;
    }

    double dumx, dumy;
    for (int i = 1; i < 8; i++) {
      double newx, newy;
      int intx, inty;
      intx = int(rx1)-i;
      inty = int(y1)-i;
      newx = double(intx);
      newy = double(inty);
      if (intx < 1 || inty < 1) {
        break;
      }
      if (isoneline(newx, newy, rx2, y2)) {
        dumx = newx;
        dumy = newy;
      }
    }
    for (int i = 1; i < 8; i++) {
      double newx, newy;
      int intx, inty;
      intx = int(rx1)+i;
      inty = int(y1)-i;
      newx = double(intx);
      newy = double(inty);
      if (intx > 8 || inty < 1) {
        break;
      }
      if (isoneline(newx, newy, rx2, y2)) {
        dumx = newx;
        dumy = newy;
      }
    }
    for (int i = 1; i < 8; i++) {
      double newx, newy;
      int intx, inty;
      intx = int(rx1)+i;
      inty = int(y1)+i;
      newx = double(intx);
      newy = double(inty);
      if (intx > 8 || inty > 8) {
        break;
      }
      if (isoneline(newx, newy, rx2, y2)) {
        dumx = newx;
        dumy = newy;
      }
    }
    for (int i = 1; i < 8; i++) {
      double newx, newy;
      int intx, inty;
      intx = int(rx1)-i;
      inty = int(y1)+i;
      newx = double(intx);
      newy = double(inty);
      if (intx < 1 || inty > 8) {
        break;
      }
      if (isoneline(newx, newy, rx2, y2)) {
        dumx = newx;
        dumy = newy;
      }
    }
    cout << 2 << " " << x1 << " " << y1 << " " << colstr(int(dumx)) << " " << int(dumy)  << " " << x2 << " " << y2 << endl;
  }

  return 0;
}