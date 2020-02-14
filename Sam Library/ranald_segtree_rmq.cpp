template <typename T>
struct SegTree {
  int s, e;
  T mn, mx, sum, add_val, set_val;
  bool lset;
  SegTree *l, *r;
  SegTree(int _s, int _e, T A[] = NULL): s(_s), e(_e), mn(0), mx(0), sum(0), lset(0), add_val(0), set_val(0), l(NULL), r(NULL) {
    if (A == NULL) return;
    if (s == e) mn = mx = sum = A[s];
    else {
      l = new SegTree(s, (s + e) >> 1, A), r = new SegTree((s + e + 2) >> 1, e, A);
      combine();
    }
  }

  void create_children() {
    if (s == e || l != NULL) return;
    int m = (s + e) >> 1;
    l = new SegTree(s, m);
    r = new SegTree(m + 1, e);
  }
  void self_set(T v) {
    lset = 1;
    mn = mx = set_val = v;
    sum = v * (e - s + 1);
    add_val = 0;
  }
  void self_add(T v) {
    if (lset) { self_set(v + set_val); return; }
    mn += v, mx += v, add_val += v;
    sum += v * (e - s + 1);
  }
  void lazy_propagate() {
    if (s == e) return;
    if (lset) {
      l->self_set(set_val), r->self_set(set_val);
      lset = set_val = 0;
    }
    if (add_val != 0) {
      l->self_add(add_val), r->self_add(add_val);
      add_val = 0;
    }
  }
  void combine() {
    if (l == NULL) return;
    sum = l->sum + r->sum;
    mn = min(l->mn, r->mn);
    mx = max(l->mx, r->mx);
  }
#define UPDATE(name)\
  void name(int x, int y, T v) { \
    if (s == x && e == y) { self_##name(v); return; } \
    int m = (s + e) >> 1; \
    create_children(); lazy_propagate(); \
    if (x <= m) l->name(x, min(y, m), v); \
    if (y > m) r->name(max(x, m + 1), y, v); \
    combine(); \
  }
  UPDATE(add)
    UPDATE(set)
#define QUERY(name, fn, var, lazyfn) \
    T range_##name(int x, int y) {\
      if (s == x && e == y) return var; \
      if (l == NULL || lset) return lazyfn(var);\
      int m = (s + e) >> 1; lazy_propagate(); \
      if (y <= m) return l->range_##name(x, y); \
      if (x > m) return r->range_##name(x, y); \
      return fn(l->range_##name(x, m), r->range_##name(m + 1, y)); \
    }
#define SAME(var) (var)
#define PART(var) ((var) / (e - s + 1) * (y - x + 1))
#define SUM(a, b) ((a)+(b))
    QUERY(min, min, mn, SAME)
    QUERY(max, max, mx, SAME)
    QUERY(sum, SUM, sum, PART)
    ~SegTree() {
      if (l != NULL) delete l;
      if (r != NULL) delete r;
    }
};

// int main() {
//   ios::sync_with_stdio(false);
//   cin.tie(nullptr);
//   cout.tie(nullptr);

//   int W, H, Q;
//   cin >> W >> H >> Q;

  
//   SegTree<ll> * stmax = new SegTree<ll>(0, W-1);
//   SegTree<ll> * stmin = new SegTree<ll>(0, W-1);
  
//   stmax->set(0, W-1, -H);
//   stmin->set(0, W-1, H);

  
//   for (int i = 0; i < Q; i++) {
//     int com, L , R, Y;
//     cin >> com;
//     if (com == 1) {
//       cin >> L >> R >> Y;
//       L--; R--;
//       int mini = stmin->range_min(L, R);
//       //cout << "will cut from " << L << " to " << R << " with " << Y << " or " << mini << " = " << min(Y, mini) << endl; 
      
//       Y = min(Y, mini);
//       stmin->set(L, R, Y);
//       stmax->set(L, R, -Y);
//     } else {
//       cin >> L >> R;
//       L--; R--;
//       int maxi = -stmax->range_min(L, R);
//       int mini = stmin->range_min(L, R);
//       //cout << " from " << L << " to " << R << " ";
//       cout << mini << " " << maxi << endl;
//     }
//   }

// }