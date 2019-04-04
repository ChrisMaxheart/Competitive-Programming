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

  char board[15][15];

  for (int i = 0; i < 13; i++) {
    for (int j = 0; j < 13; j++) {
      board[i][j] = '.';
    }
  }
  bool err = false;

  for (int i = 1; i < 9; i++) {
    string x;
    cin >> x;
    for (int j = 1; j < 9; j++) {
      board[i][j] = x[j-1];
    }
  }

  // for (int i = 0; i < 13; i++) {
  //   for (int j = 0; j < 13; j++) {
  //     cout << board[i][j] << " ";
  //   }
  //   cout << endl;
  // }

  char dir = 'R';
  int posx = 1;
  int posy = 8;

  string x;
  cin >> x;
  for (int i = 0; i < x.length(); i++) {
    // cout << x[i] << endl;
    // cout << "x: " << posx << "y: " << posy << endl;
    // cout << "dir: " << dir << endl;
    if (err) {
      break;
    }
    if (x[i] == 'F') {
      if (dir == 'R') {
        posx++;
      } else if (dir == 'L') {
        posx--;
      } else if (dir == 'U') {
        posy--;
      } else if (dir == 'D') {
        posy++;
      }
      if (posx < 1 || posy < 1 || posx > 8 || posy > 8) {
        err = true;
      }
      char curr = board[posy][posx];
      if (curr == 'C' || curr == 'I') {
        err = true;
      }
    }
    if (x[i] == 'R') {
      if (dir == 'R') {
        dir = 'D';
      } else if (dir == 'L') {
        dir = 'U';
      } else if (dir == 'U') {
        dir = 'R';
      } else if (dir == 'D') {
        dir = 'L';
      }
    }
    if (x[i] == 'L') {
      if (dir == 'R') {
        dir = 'U';
      } else if (dir == 'L') {
        dir = 'D';
      } else if (dir == 'U') {
        dir = 'L';
      } else if (dir == 'D') {
        dir = 'R';
      }
    }
    if (x[i] == 'X') {
      // cout << board[2][7] << endl;
      int noteposx = posx;
      int noteposy = posy;
      if (dir == 'R') {
        noteposx++;
      } else if (dir == 'L') {
        noteposx--;
      } else if (dir == 'U') {
        noteposy--;
      } else if (dir == 'D') {
        noteposy++;
      }
      if (board[noteposy][noteposx] == 'I') {
        board[noteposy][noteposx] = '.';
      } else {
        // cout << "target: " << noteposx << "dan" << noteposy << endl;
        // cout << board [noteposy][noteposx] << endl;
        // cout << "disini" << endl;
        err = true;
      }
    }
  }

  if (board[posy][posx] != 'D') {
    err = true;
  }

  if (err) {
    cout << "Bug!" << endl;
  } else {
    cout << "Diamond!" << endl;
  }
  return 0;
}