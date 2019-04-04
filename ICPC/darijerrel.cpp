#define MAX_N 1000
#define LOG_TWO_N 10

class RMQ {
private:
  int _A[MAX_N], SpT[MAX_N][LOG_TWO_N];
public:
  RMQ(int n, int A[]) {
    for(int i = 0; i < n; i++) {
      _A[i] = A[i];
      SpT[i][0] = i;
    }
    for (int j = 1; (1 << j) <= n; j++)
      for (int i = 0; i + (1 << j) - 1 < n; i++)
        if(_A[SpT[i][j-1]] < _A[SpT[i+(1<<(j-1))][j-1]])
          SpT[i][j] = SpT[i][j-1];
        else
          SpT[i][j] = SpT[i+(1 << (j-1))][j-1];
  }

  int query(int i, int j) {
    int k = (int)floor(log((double)j-i+1) / log(2.0));
    if (_A[SpT[i][k]] <= _A[SpT[j-(1<<k)+1][k]]) return SpT[i][k];
    else return SpT[j-(1<<k)+1][k];
  }
};

inline void makeP(){
  int logg = lg[n];
  for (int j = 1; j <= logg; j++) {
    for (int i = 1; i <= n; i++) {
      if (P[i][j-1] != -1) {
        P[i][j] = P[P[i][j-1]][j-1];
      }
    }
  }
}

inline int LCA(int p, int q) {
  if (L[p] < L[q]) swap(p, q);
  int logg = lg[L[p]];
  for (int i = logg; i >= 0; i--) {
    if (L[p] - (1 << i) >= L[q]) {
      p = P[p][i]l
    }
  }
  if (p == q) return p;
  for (int i = logg; i >= 0; i--) {
    if (P[p][i] != -1 && P[p][i] != P[q][i]) {
      p = P[p][i];
      q = P[q][i];
    }
  }
  return P[p][0]; 
}