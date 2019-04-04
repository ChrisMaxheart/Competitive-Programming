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
    // cout << "test";

  while(getline(cin, x)) {
    // assert(x != "");
    int totrow, totcol;
    totcol = x.length();
    int counter = 0;
    int row[90];
    int col[90];
    for (int i = 0; i < 90; i++) {
      row[i] = INF;
      col[i] = INF;
    }
    char board[105][105];
    for (int i = 0; i < x.length(); i++) {
      board[counter][i] = x[i];
      if (x[i] != '.') {
        if (x[i]-'0' < 10 && x[i]-'0' >= 0) {
          row[x[i]-'0'] = counter;
          col[x[i]-'0'] = i;
        } else if (x[i]-'a' < 26 && x[i]-'a' >= 0) {
          row[x[i]-'a'+10] = counter;
          col[x[i]-'a'+10] = i;
        } else if (x[i]-'A' < 26 && x[i]-'A' >= 0) {
          row[x[i]-'A'+36] = counter;
          col[x[i]-'A'+36] = i;
        }
      }
    }
    while(getline(cin, x)) {
      if (x == "") {
        break;
      }
      // cout << x << endl;
      counter++;
      for (int i = 0; i < x.length(); i++) {
        board[counter][i] = x[i];
        if (x[i] != '.') {
          if (x[i]-'0' < 10 && x[i]-'0' >= 0) {
            row[x[i]-'0'] = counter;
            col[x[i]-'0'] = i;
          } else if (x[i]-'a' < 26 && x[i]-'a' >= 0) {
            row[x[i]-'a'+10] = counter;
            col[x[i]-'a'+10] = i;
          } else if (x[i]-'A' < 26 && x[i]-'A' >= 0) {
            row[x[i]-'A'+36] = counter;
            col[x[i]-'A'+36] = i;
          }
        }
      }
    }
    totrow = counter+1;
    counter = 0;
    while(row[counter+1] != INF) {
    // cout << "hai" << endl;
      if (row[counter] == row[counter+1]) {
        for (int i = col[counter]; i < col[counter+1]; i++) {
          if (board[row[counter]][i] == '.') {
            board[row[counter]][i] = '-';
          } else if (board[row[counter]][i] == '|') {
            board[row[counter]][i] = '+';
          }
        }
        for (int i = col[counter]; i > col[counter+1]; i--) {
          if (board[row[counter]][i] == '.') {
            board[row[counter]][i] = '-';
          } else if (board[row[counter]][i] == '|') {
            board[row[counter]][i] = '+';
          }
        }
      } else if (col[counter] == col[counter+1]) {
        for (int i = row[counter]; i < row[counter+1]; i++) {
          if (board[i][col[counter]] == '.') {
            board[i][col[counter]] = '|';
          } else if (board[i][col[counter]] == '-') {
            board[i][col[counter]] = '+';
          }
        }
        for (int i = row[counter]; i > row[counter+1]; i--) {
          if (board[i][col[counter]] == '.') {
            board[i][col[counter]] = '|';
          } else if (board[i][col[counter]] == '-') {
            board[i][col[counter]] = '+';
          }
        }
      }
      counter++;
    }    
    for (int i = 0; i < totrow; i++) {
      for (int j = 0; j < totcol; j++) {
        cout << board[i][j];
      }
      cout << endl;
    }
    cout << endl;
  }

  return 0;
}