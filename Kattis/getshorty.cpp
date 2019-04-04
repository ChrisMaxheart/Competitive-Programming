#include <bits/stdc++.h>

using namespace std;

#define PI 3.14159265359
#define INF 1E9
#define Tloop int T; cin >> T; for(int i = 1; i < T+1; i++)
#define Nloop int N; cin >> N; for(int j = 0; j < N; j++)
#define printcase cout << "Case #" << i << ": "

// Disclaimer: all this typedef only used for competitive programming
//             will not use it in a proper other codes
typedef long long ll;
typedef unsigned long long ull;

struct myvert {
  int id;
  double value;
};

// pq bakal kebalik
class mycomp
{
  public:
  bool operator() (myvert a, myvert b) {
    return a.value < b.value; 
  }
};

bool customcompare(int a, int b) {
  return a > b;
}

int main ()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;

  while(cin >> n >> m, n || m) {
    vector<vector<myvert>> AL;
    for (int i = 0; i < n; i++) {
      vector<myvert> newvect;
      AL.push_back(newvect);
    }
    int x, y;
    double z;
    for (int i = 0; i < m; i++) {
      cin >> x >> y >> z;
      myvert vertex;
      vertex.id = y;
      vertex.value = z;
      AL[x].push_back(vertex);
      vertex.id = x;
      AL[y].push_back(vertex);
    }
    priority_queue<myvert, vector<myvert>, mycomp> pq;
    myvert vertex;
    vertex.id = 0;
    vertex.value = 1;
    pq.push(vertex);
    double DList[10010];
    for (int i = 0; i < 10005; i++) {
      DList[i] = INF;
    }
    while(pq.size() != 0) {
      myvert curr;
      curr = pq.top();
      pq.pop();
      if (DList[curr.id] == INF) {
        DList[curr.id] = curr.value;
        for (auto x : AL[curr.id]) {
          myvert newvert;
          newvert.id = x.id;
          newvert.value = x.value * curr.value;
          pq.push(newvert);
        }
      }
    }

    // for (int i = 0; i < n; i++)
    //   cout << DList[i] << " ";
    // cout << endl;
    cout  << setprecision(4) << fixed << DList[n-1] << endl;
  }

  return 0;
}