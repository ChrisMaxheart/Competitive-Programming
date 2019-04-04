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


void dfs(int starting) {
  for (auto &x : graf[starting]) {
    if (internet[x] == false) {
      internet[x] = true;
      dfs(x);
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

  dfs(1);

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