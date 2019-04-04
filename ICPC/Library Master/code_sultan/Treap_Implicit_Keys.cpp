// {{{ Treap with Implicit Keys
struct Treap {
  struct node {
    int x, cnt, mn, pos, rev;
    unsigned y;
    node *l, *r;
    node() { l = r = NULL; }
    node(int xx) {
      x = xx;
      y = rand();
      cnt = 1;
      mn = x;
      pos = 0;
      rev = 0;
      l = r = NULL;
    }
  };

  typedef node* Node;

  inline int cnt(Node x) { return x ? x->cnt : 0; }

  Node root, t1, t2, t3;

  Treap() { root = NULL; }

  inline void refresh(Node &x) {
    if (!x) return;
    x->cnt = 1 + cnt(x->l) + cnt(x->r);
    x->mn = x->x;
    x->pos = cnt(x->l);
    if (x->l) {
      push(x->l);
      if (x->mn > x->l->mn) x->pos = x->l->pos;
      MIN(x->mn, x->l->mn);
    }
    if (x->r) {
      push(x->r);
      if (x->mn > x->r->mn) x->pos = cnt(x->l) + 1 + x->r->pos;
      MIN(x->mn, x->r->mn);
    }
  }

  inline void push(Node &x) {
    if (!x) return;
    if (x->rev) {
      if (x->l) x->l->rev ^= 1;
      if (x->r) x->r->rev ^= 1;
      swap(x->l, x->r);
      x->pos = cnt(x) - 1 - x->pos;
      x->rev = 0;
    }
  }

  inline void split(Node x, const int &val, Node &l, Node &r, int add) {
    l = r = NULL;
    push(x);
    if (!x) return;
    int cur = add + cnt(x->l);
    if (val <= cur) {
      split(x->l, val, l, x->l, add);
      r = x;
    } else {
      split(x->r, val, x->r, r, add + 1 + cnt(x->l));
      l = x;
    }
    refresh(x);
  }

  inline Node merge(Node l, Node r) {
    push(l); push(r);
    if (!l || !r) return l ? l : r;
    if (l->y < r->y) {
      l->r = merge(l->r, r);
      refresh(l);
      return l;
    } else {
      r->l = merge(l, r->l);
      refresh(r);
      return r;
    }
  }

  inline void erase(Node &x) {
    push(x);
    if (x->l) {
      erase(x->l);
      refresh(x);
    } else {
      x = x->r;
      push(x);
    }
  }

  inline void insert(int x) { root = merge(root, new node(x)); }

  inline void update() { erase(root); }

  inline void reverse(int l, int r) {
    split(root, l, t1, t2, 0);
    split(t2, r-l+1, t2, t3, 0);
    t2->rev ^= 1;
    push(t2);
    root = merge(t1, t2);
    root = merge(root, t3);
  }
};
// }}}
