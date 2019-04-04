class FenwickTree {
private: vi ft1, ft2;
  int query(vi &ft, int b) {
    int sum = 0; for (; b; b -= LSOne(b)) sum += ft[b];
    return sum; }
  void adjust(vi &ft, int k, int v) {
    for (; k < (int)ft.size(); k += LSOne(k)) ft[k] += v; }
public:
  FenwickTree() {}
  FenwickTree(int n) { ft1.assign(n + 1, 0); ft2.assign(n+1, 0);}
  int query(int a) { return a * query(ft1, a) - query(ft2, a); }
  int query(int a, int b) { return query(b) - (a == 1 ? 0 : query(a-1)); }
  void adjust(int a, int b, int value){
    adjust(ft1, a, value);
    adjust(ft1, b+1, -value);
    adjust(ft2, a, value * (a-1));
    adjust(ft2, b+1, -1 * value * b);
  }
  int get(int n) {
    return query(n) - query(n-1);  }
};
