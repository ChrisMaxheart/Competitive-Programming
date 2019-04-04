#include<bits/stdc++.h>
using namespace std;
#define N 10500
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef pair<int, int> ii;
typedef vector<int> vi;

int p[N];
vi c[N], ng[N];
int chico[N];
int dfs(int cur, int par) {
  p[cur] = par;
  if (par != -1)
    c[par].pb(cur);

  int ans = 1;
  for (int q: ng[cur])
    if (q != par) ans += dfs(q, cur);

  return chico[cur] = ans;
}

int main() {
  int n; scanf("%d", &n); n++;
  for (int i = 0; i < n - 1; i++) {
    int p, q; scanf("%d%d", &p, &q);
    ng[p].pb(q);
    ng[q].pb(p);
  }
  dfs(0, -1);
  
  ii sol = mp(0, -1);
  for (int i = 0; i < n; i++) {
    int rel = 0;
    int tot = 0;
    for (int q: c[i]) {
      tot += chico[q];
      rel += chico[q] * (n - chico[q] - 1);
    }
    rel += (n - tot - 1) * tot;
    rel /= 2;
    sol = max(sol, mp(rel, i)); 
  }
  printf("%d ", sol.fi);

  vi sisaan;
  int tot = 0;
  for (int q: c[sol.se]) {
    tot += chico[q];
    sisaan.pb(chico[q]);  
  }
  sisaan.pb(n - tot - 1);
  sisaan.pb(0);
  sort(sisaan.begin(), sisaan.end(), greater<int>());
  int p = sisaan[0] * sisaan[1];
  printf("%d\n", sol.fi - p);
}
