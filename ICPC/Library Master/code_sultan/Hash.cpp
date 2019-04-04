// {{{ Hash
template<int pr, int MOD> class Hash {
  int n;
  vector<int> p, v;
  void init() {
    p.resize(n);
    p[0] = 1;
    for (int i = 1; i < n; i++) {
      p[i] = (int)(1LL * p[i - 1] * pr % MOD);
      v[i] = (int)(1LL * v[i - 1] * pr % MOD) + v[i];
      if (v[i] >= MOD) v[i] -= MOD;
    }
  }
public:
  Hash() {}
  Hash(string s) {
    n = (int)s.length();
    v.resize(n);
    for (int i = 0; i < n; i++) {
      v[i] = s;
    }
    init();
  }
  Hash(const vector<int> &v) {
    this->v = v;
    n = (int)v.size();
    for (auto &x : this->v) {
      x %= MOD;
      if (x < 0) x += MOD;
    }
    init();
  }
  int get(int l, int r) {
    int res = v[r] - (l > 0 ? (int)(1LL * v[l - 1] * p[r - l + 1] % MOD) : 0);
    if (res >= MOD) res -= MOD;
    if (res < 0) res += MOD;
    return res;
  }
};
// }}}
