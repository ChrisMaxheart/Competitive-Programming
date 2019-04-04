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

struct vertex {
  int dist;
  int no;
};

int myarr[10010];


class mycomp
{
  public:
  bool operator() (vertex a, vertex b) {
    return a.dist > b.dist; 
  }
};

bool customcompare(int a, int b) {
  return a > b;
}

int main ()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, q, s;

  

  while(cin >> n >> m >> q >> s, (n||m||q||s)) {
    vector<vector<vertex>> myAL;
    for (int i = 0; i < n; i++) {
      vector<vertex> subAL;
      myAL.push_back(subAL);
      myarr[i] = 1E9;
    }

    int u, v, w;

    for (int i = 0; i < m; i++) {
      cin >> u >> v >> w;
      vertex newvert;
      newvert.dist = w;
      newvert.no = v;
      myAL[u].push_back(newvert);
    }

    priority_queue<vertex, vector<vertex>, mycomp> mypq;

    vertex newvert;

    newvert.no = s;
    newvert.dist = 0;

    mypq.push(newvert);

    while(mypq.size() != 0) {
      newvert = mypq.top();
      mypq.pop();

      if(myarr[newvert.no] != 1E9)
        continue;

      // cout << newvert.no << endl;
      // cout << endl;

      myarr[newvert.no] = min(newvert.dist, myarr[newvert.no]);

      for (auto i : myAL[newvert.no]) {
        if(myarr[i.no] != 1E9)
          continue;
        vertex morevert;
        morevert.no = i.no;
        morevert.dist = i.dist + newvert.dist;
        mypq.push(morevert);
      }
    }

    int ask;

    // for (auto x : myarr) {
    //   cout << x << " ";
    // }
    // cout << endl;

    while(q--) {
      cin >> ask;
      if (myarr[ask] == 1E9)
        cout << "Impossible" << endl;
      else
        cout << myarr[ask] << endl;
    }
    cout << endl;

  }

  return 0;
}