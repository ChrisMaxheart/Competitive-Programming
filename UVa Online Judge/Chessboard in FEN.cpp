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

  string x;

  while(cin >> x) {
    int counterrow = 0;
    int countercol = 0;
    bool board[9][9];
    for (int i = 0; i < 8; i++) {
      for (int j = 0; j < 8; j++) {
        board[i][j] = true;
      }
    }
    char copyboard[9][9];
    for (int i = 0; i < x.length(); i++) {
      char chr = x[i];
      if (chr == '/') {
        counterrow++;
        countercol = 0;
        continue;
      }
      if (chr-'0' < 10 && chr-'0' >= 0) {
        countercol += (chr-'0');
        continue;
      }
      board[counterrow][countercol] = false;
      if (chr == 'p') {
        if (counterrow != 7) {
          if (countercol != 0) {
            board[counterrow+1][countercol-1] = false;
          }
          if (countercol != 7) {
            board [counterrow+1][countercol+1] = false;
          }
        }
      }
      if (chr == 'P') {
        if (counterrow != 0) {
          if (countercol != 0) {
            board[counterrow-1][countercol-1] = false;
          }
          if (countercol != 7) {
            board [counterrow-1][countercol+1] = false;
          }
        }
      }
      if (chr == 'Q' || chr == 'q' || chr == 'r' || chr == 'R') {
        for (int j = 0; j < 8; j++) {
          board[j][countercol] = false;
          board[counterrow][j] = false;
        }
      }
      if (chr == 'b' || chr == 'B' || chr == 'q' || chr == 'Q') {
        for (int j = 1; j < 8; j++) {
          if (countercol-j >= 0 && counterrow - j >= 0) {
            board[counterrow-j][countercol-j] = false;
          }
          if (countercol-j >= 0 && counterrow + j <= 7) {
            board[counterrow+j][countercol-j] = false;
          }
          if (countercol+j <= 7 && counterrow - j >= 0) {
            board[counterrow-j][countercol+j] = false;
          }
          if (countercol+j <= 7 && counterrow + j <= 7) {
            board[counterrow+j][countercol+j] = false;
          }
        }
      }
      if (chr == 'k' || chr == 'K') {
        for (int j = 1; j < 2; j++) {
          if (countercol-j >= 0 && counterrow - j >= 0) {
            board[counterrow-j][countercol-j] = false;
          }
          if (countercol-j >= 0 && counterrow + j <= 7) {
            board[counterrow+j][countercol-j] = false;
          }
          if (countercol+j <= 7 && counterrow - j >= 0) {
            board[counterrow-j][countercol+j] = false;
          }
          if (countercol+j <= 7 && counterrow + j <= 7) {
            board[counterrow+j][countercol+j] = false;
          }
        }
        if (countercol != 0 && counterrow != 0) {
          board[counterrow-1][countercol-1] = false;
        }
        if (countercol != 0 && counterrow != 7) {
          board[counterrow+1][countercol-1] = false;
        }
        if (countercol != 7 && counterrow != 0) {
          board[counterrow-1][countercol+1] = false;
        }
        if (countercol != 7 && counterrow != 7) {
          board[counterrow+1][countercol+1] = false;
        }
      }
      if (chr == 'n' || chr == 'N') {
        if (countercol-1 >= 0 && counterrow-2 >= 0) {
          board[counterrow-2][countercol-1] = false;
        }
        if (countercol-2 >= 0 && counterrow-1 >= 0) {
          board[counterrow-1][countercol-2] = false;
        }
        if (countercol-1 >= 0 && counterrow+2 <= 7) {
          board[counterrow+2][countercol-1] = false;
        }
        if (countercol-2 >= 0 && counterrow+1 <= 7) {
          board[counterrow+1][countercol-2] = false;
        }
        if (countercol+2 <= 7 && counterrow+1 <= 7) {
          board[counterrow+1][countercol+2] = false;
        }
        if (countercol+1 <= 7 && counterrow+2 <= 7) {
          board[counterrow+2][countercol+1] = false;
        }
        if (countercol+1 <= 7 && counterrow-2 >= 0) {
          board[counterrow-2][countercol+1] = false;
        }
        if (countercol+2 <= 7 && counterrow-1 >= 0) {
          board[counterrow-1][countercol+2] = false;
        }
      }
      countercol++; 
    }
    // bug: belom ngatasi kalau keblock
    int total = 0;
    for (int i = 0; i < 8; i++) {
      for (int j = 0; j < 8; j++) {
        if (board[i][j]) {
          cout << "row " << i << " and " << "column " << j << endl;
          total++;
        }
      }
    }
    cout << total << endl;

  }

  return 0;
}