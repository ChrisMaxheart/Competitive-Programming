// {{{ Splay Tree
struct Node {
  int size;
  int val, mn;
  int sum, lazy;
  bool rev;
  Node *p, *c[2];
  Node(int val) : size(1), val(val), mn(val), sum(val), lazy(0), rev(0), p(), c() {}
};

inline int getDir(Node *n) { return n->p->c[1] == n; }
inline int getMin(Node *n) { return n ? n->mn : INT_MAX; }
inline int getSum(Node *n) { return n ? n->sum : 0; }
inline int getSize(Node *n) { return n ? n->size : 0; }

inline void push(Node *n) {
  if (!n) return;
  if (n->rev) {
    swap(n->c[0], n->c[1]);
    if (n->c[0]) n->c[0]->rev ^= true;
    if (n->c[1]) n->c[1]->rev ^= true;
    n->rev = false;
  }
  if (n->lazy) {
    if (n->c[0]) n->c[0]->lazy += n->lazy;
    if (n->c[1]) n->c[1]->lazy += n->lazy;
    n->sum += n->lazy;
    n->mn += n->lazy;
    n->val += n->lazy;
    n->lazy = 0;
  }
}

inline void update(Node *n) {
  if (!n) return;
  push(n); push(n->c[0]); push(n->c[1]);
  n->size = getSize(n->c[0]) + getSize(n->c[1]) + 1;
  n->sum = getSum(n->c[0]) + getSum(n->c[1]) + n->val;
  n->mn = min(min(getMin(n->c[0]), getMin(n->c[1])), n->val);
}

inline void connect(Node *p, Node *n, int dir) {
  if (p) p->c[dir] = n;
  if (n) n->p = p;
}

inline void rotate(Node *n) {
  assert(n->p);
  int d = getDir(n);
  Node *p = n->p;
  if (p->p) connect(p->p, n, getDir(p));
  else n->p = nullptr;
  connect(p, n->c[!d], d);
  connect(n, p, !d);
  update(p);
  update(n);
}

Node *splay(Node *n) {
  while (n->p) {
    Node *p = n->p;
    if (p->p) push(p->p);
    push(p);
    push(n);
    if (p->p) rotate(getDir(n) == getDir(p) ? p : n);
    rotate(n);
  }
  push(n);
  return n;
}

Node *accessKey(Node *root, int x) {
  if (!root) return root;
  Node *cur = root;
  while (true) {
    push(cur);
    if (x == cur->val) break;
    int d = x > cur->val;
    if (!cur->c[d]) break;
    cur = cur->c[d];
  }
  return splay(cur);
}

Node *accessKth(Node *root, int k) {
  assert(k <= root->size);
  Node *cur = root;
  while (true) {
    push(cur);
    int upToCur = getSize(cur->c[0]) + 1;
    if (upToCur == k) return splay(cur);
    if (k > upToCur) {
      k -= upToCur;
      cur = cur->c[1];
    } else {
      cur = cur->c[0];
    }
  }
  assert(false);
}

void splitKey(Node *root, int x, Node *&l, Node *&r) {
  l = r = nullptr;
  if (!root) return;
  Node *cur = accessKey(root, x);
  if (cur->val <= x) {
    l = cur;
    r = cur->c[1];
    l->c[1] = nullptr;
    if (r) r->p = nullptr;
  } else {
    l = cur->c[0];
    r = cur;
    if (l) l->p = nullptr;
    r->c[0] = nullptr;
  }
  update(l); update(r);
}

void splitKth(Node *root, int k, Node *&l, Node *&r) {
  l = r = nullptr;
  if (!root) return;
  assert(k <= root->size);
  if (k == 0) {
    push(root);
    r = root;
    return;
  }
  root = accessKth(root, k);
  l = root;
  r = root->c[1];
  l->c[1] = nullptr;
  if (r) r->p = nullptr;
  update(l);
}

Node *join(Node *l, Node *r) {
  if (!l || !r) return l ? l : r;
  while (true) {
    push(l);
    if (!l->c[1]) break;
    l = l->c[1];
  }
  splay(l);
  connect(l, r, 1);
  push(r);
  update(l);
  return l;
}

Node *insert(Node *root, int val) {
  if (!root) return new Node(val);
  Node *l, *r;
  splitKey(root, val, l, r);
  if (!l || l->val != val) {
    Node *tmp = new Node(val);
    connect(tmp, l, 0);
    update(tmp);
    l = tmp;
  }
  return join(l, r);
}

Node *erase(Node *root, int val) {
  if (!root) return nullptr;
  root = accessKey(root, val);
  if (root->val != val) return root;
  else {
    Node *l = root->c[0], *r = root->c[1];
    if (l) l->p = nullptr;
    if (r) r->p = nullptr;
    delete root;
    return join(l, r);
  }
}

pair<Node*, int> queryKth(Node *root, int k) {
  if (!root || root->size < k) return {root, INT_MAX};
  root = accessKth(root, k);
  return {root, root->val};
}

pair<Node*, int> queryLt(Node *root, int x) {
  Node *l, *r;
  splitKey(root, x - 1, l, r);
  int ret = getSize(l);
  return {join(l, r), ret};
}

Node *add(Node *root, int l, int r, int v) {
  Node *t1, *t2, *t3;
  splitKth(root, l - 1, t1, t2);
  splitKth(t2, r - l + 1, t2, t3);
  if (t2) t2->lazy += v;
  return join(join(t1, t2), t3);
}

Node *reverse(Node *root, int l, int r) {
  Node *t1, *t2, *t3;
  splitKth(root, l - 1, t1, t2);
  splitKth(t2, r - l + 1, t2, t3);
  if (t2) t2->rev ^= true;
  return join(join(t1, t2), t3);
}

// }}}
