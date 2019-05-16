// directed!
// careful with empty graph!
// {{{ eulerianTour
#define SZ(S) S.size()
#define ALL(S) S.begin(), S.end()
template<typename T = int>
bool eulerianTour(const vector<vector<T>> &g, vi &tour) {
  int n = SZ(g);
  int edgeCount = 0;
  vi inDeg(n), outDeg(n);
  for (int i = 0; i < n; i++) {
    outDeg[i] = SZ(g[i]);
    for (auto &it : g[i]) {
      inDeg[it]++;
      edgeCount++;
    }
  }
  int out = -1, in = -1;
  for (int i = 0; i < n; i++) {
    if (inDeg[i] == outDeg[i] + 1) {
      if (out == -1) {
        out = i;
      } else {
        return false;
      }
    } else if (outDeg[i] == inDeg[i] + 1) {
      if (in == -1) {
        in = i;
      } else {
        return false;
      }
    } else if (outDeg[i] != inDeg[i]) {
      return false;
    }
  }
  // either zero or both
  if ((in != -1) ^ (out != -1)) {
    return false;
  }
  if (in == -1) {
    for (int i = 0; i < n; i++) {
      if (outDeg[i] != 0) {
        in = out = i;
        break;
      }
    }
    // empty graph?
    if (in == -1) {
      in = out = 0;
    }
  }
  tour.clear();
  stack<int> st;
  vi visit(n);
  vi ptr(n);
  st.push(in);
  while (!st.empty()) {
    int u = st.top();
    visit[u] = true;
    if (ptr[u] == SZ(g[u])) {
      tour.push_back(u);
      st.pop();
    } else {
      st.push(g[u][ptr[u]++]);
    }
  }
  reverse(ALL(tour));
  return SZ(tour) == edgeCount + 1;
}
// }}}
