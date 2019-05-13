#include <bits/stdc++.h>
using namespace std;

#define MAX_N 1000

vector<vector<int>> children;

// How to use
// Root at index 0
// H[i] records the index of first occurence of node i in E
// L records the depth for each node
// E records the node name --> can be multiple, like 1 2 1 3 1 4 if 1 have childrens 2, 3, and 4
// So to compute LCA(4, 6) will need to see H[4] = 5 and H[6] = 10, then do RMQ on L from 5 to 10, then for example RMQ returns index 9, answer is E[9]
int L[2*MAX_N], E[2*MAX_N], H[MAX_N], idx;

void dfs(int cur, int depth) {
  H[cur] = idx;
  E[idx] = cur;
  L[idx++] = depth;
  for (auto &nxt : children[cur]) {
    dfs(nxt, depth+1);
    E[idx] = cur;                              // backtrack to current node
    L[idx++] = depth;
} }

void buildRMQ() {
  idx = 0;
  memset(H, -1, sizeof H);
  dfs(0, 0);                       // we assume that the root is at index 0
}

// int main() {
//   children.assign(10, vector<int>());
//   children[0].push_back(1); children[0].push_back(7);
//   children[1].push_back(2); children[1].push_back(3); children[1].push_back(6);
//   children[3].push_back(4); children[3].push_back(5);
//   children[7].push_back(8); children[7].push_back(9);

//   buildRMQ();
//   for (int i = 0; i < 2*10-1; i++) printf("%d ", H[i]);
//   printf("\n");
//   for (int i = 0; i < 2*10-1; i++) printf("%d ", E[i]);
//   printf("\n");
//   for (int i = 0; i < 2*10-1; i++) printf("%d ", L[i]);
//   printf("\n");

//   return 0;
// }