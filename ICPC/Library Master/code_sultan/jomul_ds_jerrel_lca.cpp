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