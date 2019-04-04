#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

bool reversecompare(int a, int b)
{
  return a > b;
}

vector<int> graf[200010];
bool internet[200010];

queue<int> bfsq;

void bfs(int starting) {
  for (auto &z : graf[starting]) {
    if (internet[z] != true) {
      internet[z] = true;
      bfsq.push(z);
    }
  }
  return;
}

int main ()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, M;

  cin >> N >> M;

  

  for (int i = 1; i <= N; i++) {
    internet[i] = false;
  }  
  internet[1] = true;

  while(M--) {
    int x, y;
    cin >> x >> y;
    graf[x].push_back(y);
    graf[y].push_back(x);
  }

  

  bfs(1);

  while(bfsq.size() > 0) {
    int v = bfsq.front();
    bfsq.pop();
    bfs(v);
  }

  bool stillnot = false;

  for (int i = 2; i <= N; i++) {
    if (internet[i] == false) {
      cout << i << endl;
      stillnot = true;
    }
  }

  if (!stillnot) {
    cout << "Connected" << endl;
  }

  return 0;
}