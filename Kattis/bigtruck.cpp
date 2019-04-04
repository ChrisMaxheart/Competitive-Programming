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
  int dist;
  int item;
};

// pq bakal kebalik
class mycomp
{
  public:
  bool operator() (myvert a, myvert b) {
    if(a.dist == b.dist) {
      return a.item < b.item;
    } else {
      return a.dist > b.dist;
    }
  }
};

bool customcompare(int a, int b) {
  return a > b;
}

int main ()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int itemarr[105];

  vector<vector<myvert>> AL;

  vector<myvert> dum;
  AL.push_back(dum);

  Nloop {
    cin >> itemarr[j+1];
    vector<myvert> newvect;
    AL.push_back(newvect);
  }

  int AList[105];
  int IList[105];

  for (int i = 0; i < 104; i++) {
    AList[i] = INF;
  }

  Tloop {
    int x, y, z;
    cin >> x >> y >> z;
    myvert vertex;
    vertex.id = y;
    vertex.dist = z;
    vertex.item = 0;
    AL[x].push_back(vertex);
    vertex.id = x;
    vertex.dist = z;
    vertex.item = 0;
    AL[y].push_back(vertex);
  }

  priority_queue<myvert, vector<myvert>, mycomp> pq;

  myvert startvert;
  startvert.id = 1;
  startvert.item = itemarr[1];
  startvert.dist = 0;

  pq.push(startvert);

  while(pq.size() != 0) {
    myvert curr;
    curr = pq.top();
    // cout << curr.id << " with " << curr.dist << "while in pq" << pq.size() << endl;
    pq.pop();
    if(AList[curr.id] == INF) {
      AList[curr.id] = curr.dist;
      IList[curr.id] = curr.item;
      for (auto x : AL[curr.id]) {
        // cout << x.id << endl;
        // if(curr.id == 1) {
        //   cout << x.id << endl;
        // }
        myvert newvert;
        newvert.id = x.id;
        // cout << x.id << " with " << x.dist+curr.dist <<  endl;
        newvert.dist = x.dist + curr.dist;
        newvert.item = curr.item + itemarr[x.id];
        pq.push(newvert);
      }
    }
  }

  if (AList[N] == INF) {
    cout << "impossible" << endl;
  } else {
    cout << AList[N] << " " << IList[N] << endl;
  }

  // for (int i = 0; i <= N; i++) {
  //   cout << IList[i] << " ";
  // }

  return 0;
}