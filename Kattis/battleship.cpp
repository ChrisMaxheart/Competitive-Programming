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

int main ()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Tloop {
    int w, h, n;
    cin >> w >> h >> n;
    char p1board [35][35];
    char p2board[35][35];
    int p1ship, p2ship;
    p1ship = 0;
    p2ship = 0;
    for (int j = 0; j < 33; j++) {
      for (int k = 0; k < 33; k++) {
        p1board[j][k] = '_';
        p2board[j][k] = '_';
      }
    }
    for (int j = h-1; j >= 0; j--) {
      string x;
      cin >> x;
      for (int k = 0; k < w; k++) {
        p1board[j][k] = x[k];
        if (x[k] == '#') {
          p1ship++;
        }
      }
    }
    for (int j = h-1; j >= 0; j--) {
      string x;
      cin >> x;
      for (int k = 0; k < w; k++) {
        p2board[j][k] = x[k];
        if (x[k] == '#') {
          p2ship++;
        }
      }
    }
    // for (int j = 0; j < h; j++) {
    //   for (int k = 0; k < w; k++) {
    //     cout << p1board[j][k] << " ";
    //   }
    //   cout << endl;
    // }
    bool p1play = true;
    bool game = true;
    for (int j = 0; j < n; j++) {
      int x, y;
      cin >> x >> y;
      if (!game) {
        continue;
      }
      if (p1play) {
        if (p2board[y][x] == '#') {
          p2board[y][x] = '_';
          p2ship--;
          if (p2ship == 0) {
            p1play = false;
          }
        } else {
          p1play = false;
        }
      } else {
        if (p1board[y][x] == '#') {
          // cout << y << " " << x << endl;
          p1board[y][x] = '_';
          p1ship--;
        } else {
          if (p1ship == 0 || p2ship == 0) {
            game = false;
          }
          p1play = true;
        }
      }
    }
    // cout << p1ship << endl;
    // cout << p2ship << endl;
    if (p1ship == 0 && p2ship == 0) {
      cout << "draw" << endl;
    } else if (p1ship == 0) {
      cout << "player two wins" << endl;
    } else if (p2ship == 0) {
      cout << "player one wins" << endl;
    } else {
      cout << "draw" << endl;
    }

  }

  return 0;
}