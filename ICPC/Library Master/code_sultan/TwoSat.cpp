// VAR(x), NOT(x)
// TwoSat(int varCount)
// bool TwoSat.solve() -> vector<int> TwoSat.value
// {{{ 2-SAT
using graph = vector<vi>;
inline int VAR(int x) { return 2 * x; }
inline int NOT(int x) { return x ^ 1; }

struct TwoSat {
  int n;
  vi value;
  graph g, grev;
  TwoSat(int n) : n(2 * n), g(2 * n) {}

  void addImplication(int x, int y) {
    g[x].emplace_back(y);
    g[NOT(y)].emplace_back(NOT(x));
  }

  void addOr(int x, int y) {
    g[NOT(x)].emplace_back(y);
    g[NOT(y)].emplace_back(x);
  }

  void dfs(int u, graph &g, vi &visit, vi &order) {
    visit[u] = 1;
    for (int v : g[u]) {
      if (!visit[v]) {
        dfs(v, g, visit, order);
      }
    }
    order.push_back(u);
  }

  bool solve() {
    grev.assign(n, vi());
    for (int i = 0; i < n; i++) {
      for (int j : g[i]) {
        grev[j].push_back(i);
      }
    }
    vi visited(n, false);
    vi order;
    for (int i = 0; i < n; i++) {
      if (!visited[i]) {
        dfs(i, g, visited, order);
      }
    }
    reverse(ALL(order));
    vi repr(n);
    fill(ALL(visited), false);
    value.assign(n, -1);
    for (int u : order) {
      if (!visited[u]) {
        vi tmp;
        dfs(u, grev, visited, tmp);
        for (int v : tmp) {
          repr[v] = tmp[0];
          if (value[v] == -1) {
            value[v] = 1;
            value[NOT(v)] = 0;
          }
        }
      }
    }
    for (int i = 0; i < n; i++) {
      if (repr[i] == repr[NOT(i)]) {
        return false;
      }
    }
    return true;
  }
};
// }}}
