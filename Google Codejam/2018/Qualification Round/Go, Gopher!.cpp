#include <bits/stdc++.h>

using namespace std;

#define PI 3.141592653

typedef long long ll;
typedef unsigned long long ull;
typedef stack<int> si;
typedef stack<long long> sll;
typedef stack<string> ss;
typedef queue<int> qi;
typedef queue<long long> qll;
typedef queue<string> qs;
typedef priority_queue<int> pqi;
typedef priority_queue<long long> pqll;
typedef priority_queue<string> pqs;
typedef set<int> seti;
typedef set<long long> setll;
typedef set<string> sets;
typedef map<int, string> mapis;
typedef map<string, int> mapsi;
typedef map<long long, string> maplls;
typedef map<string, long long> mapsll;
typedef map<int, int> mapii;
typedef map<string, string> mapss;
typedef map<long long, long long> mapllll;
typedef unordered_map<int, string> umapis;
typedef unordered_map<string, int> umapsi;
typedef unordered_map<long long, string> umaplls;
typedef unordered_map<string, long long> umapsll;
typedef unordered_map<int, int> umapii;
typedef unordered_map<string, string> umapss;
typedef unordered_map<long long, long long> umapllll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<string> vs;

class mycomp
{
  public:
  bool operator() (int a, int b) {
    return a > b; 
  }
};

bool reversecompare(int a, int b) {
  return a > b;
}

int main ()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;

  cin >> T;

  while (T--) {
    
    bool arr[8][1005];

    for (int i = 0; i < 8; i++)
      for (int j = 0; j < 1004; j++)
        arr[i][j] = false;

    int A;

    cin >> A;

    bool solved = false;


    int x, y;

    while (!(arr[6][5] && arr[6][6] && arr[6][7] && arr[5][5] && arr[5][6] && arr[5][7] && arr[7][5] && arr[7][6] && arr[7][7])) {
      cout << 6 << " " << 6 << endl;
      // cout << flush;
      cin >> x >> y;
      // cerr << "yang dilakukan" << endl;
      // cerr << x << "dan" << y << endl;
      if (x == 0 && y == 0)
        break;
      if (x == -1 && y == -1) {
        return 0;
        solved = true;
        break;
      
      }
      arr[x][y] = true;
    }

    for (int i = 7; i < 1002; i++) {
      if (solved)
        break;
      while (!(arr[5][i+1] && arr[6][i+1] && arr[7][i+1])) {
        if (solved)
          break;
        // cerr << "eh udah sampe sini";
        cout << 6 << " " << i << endl;
        // cout << flush;
        cin >> x >> y;
        if (x == 0 && y == 0) {
          solved = true;
          break;
        }
        if (x == -1 && y == -1) {
          return 0;
          solved = true;
          break;
        }
        arr[x][y] = true;
      }
    }

    

  }

  return 0;
}