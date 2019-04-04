class FenwickTree { private:
    vector<long long int> ft;
    int n;

  public:
    FenwickTree(int _n) : n(_n) {
      ft.assign(n+1, 0);
    }

    FenwickTree(const vector<int>& f) : n(f.size() - 1) {
      ft.assign(n+1, 0);
      for(int i = 1; i <= n; ++i) {
        ft[i] += f[i];
        if(i + LSOne(i) <= n) {
          ft[i + LSOne(i)] += ft[i];
        }
      }
    }

    long long int rsq(int b) {
      long long int sum = 0;
      for(; b; b -= LSOne(b)) {
        sum += ft[b];
      }
      return sum;
    }

    long long int rsq(int a, int b) {
      return rsq(b) - rsq(a);
    }

    void adjust(int k, long long int v) {
      for(; k <=n; k += LSOne(k)) {
        ft[k] += v;
      }
    }
};
