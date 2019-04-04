#include <bits/stdc++.h>
using namespace std;

//Add Edge : MaxFlow.addEdge(int from, int to, F capacity)
//Solve : MaxFlow.calcMaxFlow(int source, int sink)
// {{{ Dinic Max Flow<F=int>
// 
// to check all the edges used, see all edge from the graph parameter (mf.graph), check the one that have cap > 0
// min cut, abis calcmaxflow, bfs dari source ke sink pake edge yang cap > 0, dan cap != flow.
template<typename F = int>
struct DinicMaxFlow {
    struct Edge {
        int to, rev, from;
        F flow, cap;
    };

    const F INF_FLOW = numeric_limits<F>::max() / 2;
    const int INF_DIST = 1e9;

    int source, sink;
    vector<vector<Edge>> graph;
    vector<int> dist, ptr;

    DinicMaxFlow(int N) : graph(N), dist(N), ptr(N) {}

    void addEdge(int from, int to, F cap) {
      if (from == to) {
        return;
      }
      Edge e1 { to, (graph[to].size()), from, 0, cap };
      Edge e2 { from, (graph[from].size()), to, 0, 0 };
      graph[from].push_back(e1);
      graph[to].push_back(e2);
    }

    bool buildLevelGraph() {
      fill(begin(dist), end(dist), INF_DIST);
      queue<int> q;
      dist[source] = 0;
      q.push(source);
      while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (const auto &e : graph[u]) {
          if (e.flow < e.cap && dist[e.to] > dist[u] + 1) {
            dist[e.to] = dist[u] + 1;
            q.push(e.to);
          }
        }
      }
      return dist[sink] != INF_DIST;
    }

    F dfs(int u, F bottleneck) {
      if (u == sink || bottleneck == 0) {
        return bottleneck;
      }
      for (int &i = ptr[u]; i < (graph[u].size()); i++) {
        auto &e = graph[u][i];
        auto &b = graph[e.to][e.rev];
        if (dist[e.to] != dist[u] + 1 || e.flow >= e.cap) {
          continue;
        }
        F pushed = dfs(e.to, min(e.cap - e.flow, bottleneck));
        if (pushed > 0) {
          e.flow += pushed;
          b.flow -= pushed;
          return pushed;
        }
      }
      return 0;
    }

    F calcMaxFlow(const int source, const int sink) {
      this->source = source;
      this->sink = sink;
      F mf = 0;
      while (buildLevelGraph()) {
        fill(begin(ptr), end(ptr), 0);
        F pushed;
        while ((pushed = dfs(source, INF_FLOW))) {
          mf += pushed;
        }
      }
      return mf;
    }
};
// }}}

/*
    Sample usage

int main() {
    int n, m, p; scanf("%d%d%d", &n, &m, &p);
    DinicMaxFlow<int> mf(n + m + p + 2);
    int SOURCE = 0;
    int SINK = n + m + p + 1;

    for (int i = 1; i <= n; i++)
        mf.addEdge(SOURCE, i, 1);

    for (int i = 1; i <= n; i++) {
        int k; scanf("%d", &k);
        for (int j = 1; j <= k; j++) {
            int tmp; scanf("%d", &tmp);
            mf.addEdge(i, n + tmp, 1);
        }
    }

    bool used[1000];
    memset(used, 0, sizeof used);
    for (int i = 1; i <= p; i++) {
        int k; scanf("%d", &k);
        for (int j = 1; j <= k; j++) {
            int tmp; scanf("%d", &tmp);
            used[tmp] = true;
            mf.addEdge(n + tmp, n + m + i, 1);
        }
        int r; scanf("%d", &r);
        mf.addEdge(n + m + i, SINK, r);
    }

    for (int i = 1; i <= m; i++) {
        if (used[i])
            continue;
        mf.addEdge(n + i, SINK, 1);
    }
    printf("%d\n", mf.calcMaxFlow(SOURCE, SINK));
 */

// }}}
