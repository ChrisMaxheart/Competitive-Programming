#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

bool reversecompare(int a, int b)
{
  return a > b;
}

void dfs(int x, vector<int> AL[], bool visited[]) {
  visited[x] = true;
  for (auto &z : AL[x]) {
    if (visited[z] == false) {
      dfs(z, AL, visited);
    }
  }
}

int main ()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;

  cin >> N;

  while(N--) {
    int cit;
    bool endp2[1010];
    for (int i = 0; i < 1003; i++) {
      endp2[i] = false;
    }
    vector<int> endp[1010];
    int e, v;
    cin >> v >> e;
    while(e--) {
      int v1, v2;
      cin >> v1 >> v2;
      endp[v1].push_back(v2);
      endp[v2].push_back(v1);
    }
    int counter = 0;
    for (int i = 0; i < v; i++) {
      if (endp2[i] == false) {
        counter++;
        // cout << "test" << i << endl;
        dfs(i, endp, endp2);
      }
    }
    cout << counter-1 << endl;
  }  

  return 0;
}