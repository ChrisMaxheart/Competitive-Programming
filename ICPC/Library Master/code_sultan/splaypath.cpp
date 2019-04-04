// change cost of edge and query path max

const int N = 1e4 + 4;

struct Node {
  int val, ans;
  bool rev;
  Node *c[2], *p;

  Node() {}
  Node(int val) : val(val), ans(val), rev(false), c(), p() {}
};

Node nodes[N * 2];
pii edge[N];
vector<pii> adj[N];

void dfs(int u, int par) {
  for (int i = 0; i < SZ(adj[u]); i++) {
    const pii &v = adj[u][i];
    if (v.first != par) {
      edge[v.second] = pii(u, v.first);
      dfs(v.first, u);
    }
  }
}

inline int getDir(Node *n) { return n->p->c[1] == n; }
inline bool isRoot(Node *n) { return n->p == nullptr || n->p->c[getDir(n)] != n; }

void push(Node *n) {
  if (n->rev) {
    if (n->c[0]) {
      n->c[0]->rev ^= true;
    }
    if (n->c[1]) {
      n->c[1]->rev ^= true;
    }
    swap(n->c[0], n->c[1]);
    n->rev = false;
  }
}

void update(Node *n) {
  n->ans = n->val;
  push(n);
  if (n->c[0]) {
    push(n->c[0]);
    n->ans = max(n->ans, n->c[0]->ans);
  }
  if (n->c[1]) {
    push(n->c[1]);
    n->ans = max(n->ans, n->c[1]->ans);
  }
}

void connect(Node *p, Node *n, int dir) {
  if (p) {
    p->c[dir] = n;
  }
  if (n) {
    n->p = p;
  }
}

void rotate(Node *n) {
  int dir = getDir(n);
  Node *p = n->p;
  Node *c = n->c[!dir];
  if (isRoot(p)) {
    n->p = p->p;
  } else {
    connect(p->p, n, getDir(p));
  }
  connect(p, c, dir);
  connect(n, p, !dir);
  update(p);
  update(n);
}

void splay(Node *n) {
  while (!isRoot(n)) {
    Node *p = n->p;
    if (!isRoot(p)) {
      push(p->p);
    }
    push(p);
    push(n);
    if (!isRoot(p)) {
      rotate(getDir(n) == getDir(p) ? p : n);
    }
    rotate(n);
  }
  update(n); // useful if n is already a root
}

void expose(Node *n) {
  splay(n);
  n->c[1] = nullptr;
  while (n->p) {
    splay(n->p);
    n->p->c[1] = n;
    splay(n);
  }
  update(n); // useful if n is already a root
}

void evert(Node *n) {
  expose(n);
  n->rev ^= true;
}

void link(Node *n, Node *m) {
  evert(n); expose(m);
  n->p = m;
}

void change(Node *n, int newValue) {
  expose(n);
  n->val = newValue;
}

int query(Node *n, Node *m) {
  evert(n); expose(m);
  return m->ans;
}

int main() {
  //ios::sync_with_stdio(false);
  //cin.tie(nullptr);
  int T;
  getint(T);
  while (T--) {
    int n;
    getint(n);
    for (int i = 0; i < n; i++) {
      adj[i].clear();
      nodes[i] = Node(-1e9);
    }
    for (int i = 0; i < n - 1; i++) {
      int u, v, w;
      getint(u); getint(v); getint(w);
      u--; v--;
      adj[u].push_back(pii(v, i));
      adj[v].push_back(pii(u, i));
      nodes[n + i] = Node(w);
    }
    dfs(0, -1);
    for (int i = 0; i < n - 1; i++) {
      link(&nodes[edge[i].second], &nodes[n + i]);
      link(&nodes[n + i], &nodes[edge[i].first]);
    }
    char buff[11];
    for (;;) {
      scanf("%s", buff);
      if (buff[0] == 'Q') {
        int u, v;
        getint(u); getint(v);
        u--; v--;
        printf("%d\n", query(&nodes[u], &nodes[v]));
      } else if (buff[0] == 'C') {
        int i, w;
        getint(i); getint(w);
        i--;
        change(&nodes[n + i], w);
      } else {
        break;
      }
    }
  }
  return 0;
}
