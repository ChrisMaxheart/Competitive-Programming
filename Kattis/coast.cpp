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

int coast[1010][1010];

void dfs(int x, int y, int N, int M) {
  if (coast[y][x] == 1) {
    coast[y][x] = 2;
    if (x != 0)
      dfs(x-1, y, N, M);
    if (y != 0)
      dfs(x, y-1, N, M);
    if (y != N+1)
      dfs (x, y+1, N, M);
    // else
    //   cout << y<<endl;
    if (x != M+1)
      dfs(x+1, y, N, M);
    // else
      // cout << x << endl;
  }
  return;
}

int main ()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  

  int N, M;

  cin >> N >> M;

  char x;

  for (int i = 0; i < 1005; i++)
    for (int j = 0; j < 1005; j++)
      coast[i][j] = 1;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> x;
      if (x-48) {
        coast[i+1][j+1] = 0;
      } else {
        coast[i+1][j+1] = 1;
      }
    }
  }



  ll ttl = 0;

  dfs(0, 0, N, M);

  // for (int i = 0; i <= N+1; i++) {
  //   for (int j = 0; j <= M+1; j++)
  //     cout << coast[i][j];
  //   cout << endl;
  // }

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
      if (coast[i][j] == 0) {
        // cout << ttl << endl;
        // cout << i << "and" << j << endl;
        // ttl += coast[i-1][j-1];
        ttl += max(coast[i-1][j]-1, 0);
        // ttl += coast[i-1][j+1];
        ttl += max(coast[i][j-1]-1, 0);
        ttl += max(coast[i][j+1]-1, 0);
        // ttl += coast[i+1][j-1];
        ttl += max(coast[i+1][j]-1, 0);
        // ttl += coast[i+1][j+1];
      }
    }
  }

  cout << ttl << endl;

  return 0;
}