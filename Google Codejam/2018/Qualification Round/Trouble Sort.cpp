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

  for (int i = 1; i <= T; i++) {
    int N;

    cin >> N;
    // int no;

    // no = N;

    vll myvectodd, myvecteven, myvectfinal;

    ll x;

    for (int j = 0; j < N; j++) {
      cin >> x;
      if (j%2) {
        myvectodd.push_back(x);
      } else {
        myvecteven.push_back(x);
      }
    }

    sort(myvectodd.begin(), myvectodd.end());
    sort(myvecteven.begin(), myvecteven.end());

    for (int j = 0; j < max(myvectodd.size(), myvecteven.size()); j++) {
      if (j == myvectodd.size())
        myvectfinal.push_back(myvecteven[j]);
      else if (j == myvecteven.size())
        myvectfinal.push_back(myvectodd[j]);
      else {
        myvectfinal.push_back(myvecteven[j]);
        myvectfinal.push_back(myvectodd[j]);
      }
    }

    bool can = true;

    for (int j = 0; j < N-1; j++) {
      if (myvectfinal[j] > myvectfinal[j+1]) {
        can = false;
        cout << "Case #" << i << ": " << j << endl;
        break;
      }
    }

    if (can)
      cout << "Case #" << i << ": OK" << endl;

  }

  return 0;
}