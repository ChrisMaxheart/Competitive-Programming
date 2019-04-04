#include<bits/stdc++.h>
using namespace std;
# define N 30
typedef long long ll;

ll c[N], b[150];
ll dp[150][N];
long long best(int pos, int cap) {
  if (pos < 0) return 0;
  if (cap < 0) return 0;

  if (dp[pos][cap] != 0) return dp[pos][cap];
  ll m = 0; 
  m = max(m, best(pos - 1, cap - 1));
  m = max(m, best(pos - 2, cap));
  for (int i = 0; i < N; i++) 
    m = max(m, best(pos - 3, i));
  return dp[pos][cap] = m + min(b[pos], c[cap]);
}
int main() {
  ll n, k; scanf("%lld %lld", &n, &k);
  for (ll i = 0; i < n; i++) scanf("%lld", &b[i]);

  for (ll i = 0, cur = k; i < N; i++, cur = cur * 2 / 3)
    c[i] = cur; 

  ll ans = 0;
  for(ll i = 0; i < N; i++) {
    ans = max(ans, best(n - 1, i));
  }
  
  //for (int i = 0; i < n; i++) {
  //  for (int j = 0; j < n; j++) {
  //    printf("%7lld ", dp[i][j]);
  //  }printf("\n");
  //}
  printf("%lld\n", ans);
}