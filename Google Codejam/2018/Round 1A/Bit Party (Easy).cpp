#include <bits/stdc++.h>

using namespace std;

#define PI 3.141592653
#define INF 1E9

// Disclaimer: all this typedef only used for competitive programming
//             will not use it in a proper other codes
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
typedef pair<int, int> pii;
typedef pair<string, int> psi;
typedef pair<long long, long long> pllll;
typedef pair<string, long long> psll;

struct mystruct {

};

// for pq, return kiri bakal lebih di atas
class mycomp
{
  public:
  bool operator() (int a, int b) {
    return a > b; 
  }
};

bool customcompare(int a, int b) {
  return a > b;
}

int dp[25][8];


int main ()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;

  cin >> T;

  for (int i = 0; i < T; i++) {

    for (int j = 0; j < 24; j++) {
      for (int k = 0 ; k < 7; k++) {
        dp[j][k] = 0;
      }
    }

    int maxi[8];
    int scan[8];
    int pack[8];

    int R, B, C;

    cin >> R >> B >> C;

    for (int j = 0; j < C; j++) {
      cin >> maxi[i] >> scan[i] >> pack[i];
    }
  }  

  return 0;
}