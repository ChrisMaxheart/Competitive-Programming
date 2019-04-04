// O(N + M)
int psetBridge[N], psetComp[N]; // UF super vertice, UF tree int par[N];
bool seen[N];
int size[N];
int bridge;
int n;
void reset() {
  for(int i = 0 ; i <= n ; i++) {
    psetBridge[i] = psetComp[i] = i;
    par[i] = -1;
    seen[i] = 0;
    size[i] = 1;
  }
  bridge = 0;
}
int findsB(int x) {
  if(x == -1) return -1;
  return x == psetBridge[x] ? x : psetBridge[x] = findsB(psetBridge[x]);
}
int findsC(int x) {
  x = findsB(x);
  return x == psetComp[x] ? x : psetComp[x] = findsC(psetComp[x]);
}
void makeRoot(int x) { // make super vertice which contains x root of its tree
  x = findsB(x);
  int root = x;
  int chld = -1;
  while(x != -1) {
    int papa = findsB(par[x]);
    par[x] = chld;
    psetComp[x] = root;
    chld = x;
    x = papa;
  }
  size[root] = size[chld];
}
void mergePath(int u,int v) { // remove bridge between u and v in tree vector<int> vu,vv;
  int lca = -1;
  while(1) {
    if(u != -1) {
      u = findsB(u);
      vu.push_back(u);
      if(seen[u]) {
        lca = u;
        break;
      }
      seen[u] = 1;
      u = par[u];
    }
    if(v != -1) {
      v = findsB(v);
      vv.push_back(v);
      if(seen[v]) {
        lca = v;
        break;
      }
      seen[v] = 1;
      v = par[v];
    }
  }
  for(int i = 0 ; i < 2 ; i++) {
    vector<int> &proc = i ? vv : vu;
    for(int x : proc) {
      psetBridge[x] = lca;
      if(x == lca) {
        break;
      }
      bridge--; 
    }
    for(int x : proc)
      seen[x] = 0;
  } 
}
void addEdge(int u,int v) {
  u = findsB(u);
  v = findsB(v);
  if(u != v) {
    int uu = findsC(u);
    int vv = findsC(v);
    if(uu != vv) {
      bridge++;
      if(size[uu] > size[vv]) {
        swap(u,v);
        swap(vv,uu);
      }
      makeRoot(u);
      par[u] = psetComp[u] = v;
      size[vv] += size[u];
    } else
      mergePath(u,v);
  }
}

