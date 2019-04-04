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

string myst[100010];
int mypr[100010];

int main ()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  umapsi mydict;
  // sets grp[100010];
  // sets myset;

  int n, k, m;

  cin >> n >> k >> m;

  for (int i = 0; i < n; i ++) {
    cin >> myst[i];
  }

  for (int i = 0; i < n; i ++) {
    cin >> mypr[i];
  }

  for (int i = 0; i < n; i++) {
    mydict[myst[i]] = mypr[i];
  }

  for (int i = 0; i < k; i++) {
    sets myset;
    int x;
    int mprice = 1E9;
    int z;
    cin >> x;
    while(x--) {
      cin >> z;
      myset.insert(myst[z-1]);
      mprice = min(mprice, mypr[z-1]);
    }
    for (auto name : myset) {
      // cout << name << "cost" << mprice << endl;
      mydict[name] = mprice;
    }
  }

  ll total = 0;
  string dummy;

  for (int i = 0; i < m; i++) {
    cin >> dummy;
    // cout << dummy << "cost" << mydict[dummy] << endl;
    total += mydict[dummy];
  }

  cout << total << endl;

  return 0;
}