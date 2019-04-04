#include <map>
using std::map;

const int MAX = 3e5 + 5;

// PalindromicTree.init()
// PalindromicTree.addChar(c)
// PalindromicTree::Char
// {{{ PalindromicTree
struct PalindromicTree {
  typedef char Char;

  map<Char, int> to[MAX];
  int link[MAX], len[MAX];
  int occ[MAX];
  Char s[MAX];
  int n, last, sz = 0;

  PalindromicTree() { init(); }

  void init() {
    for_each(to, to + MAX, [] (map<Char, int> &m) { m.clear(); });
    memset(link, -1, sizeof(link));
    memset(len, -1, sizeof(len));
    n = 0;
    link[0] = 0;
    link[1] = 0;
    len[0] = -1;
    len[1] = 0;
    last = 1;
    sz = 2;
  }

  int getLink(int v) {
    while (n - len[v] - 2 < 0 || (s[n - len[v] - 2] != s[n - 1])) {
      v = link[v];
    }
    return v;
  }

  void addChar(Char c) {
    s[n++] = c;
    int lnk = getLink(last);
    if (to[lnk].count(c) == 0) {
      len[sz] = len[lnk] + 2;
      if (len[sz] == 1) {
        link[sz] = 1;
      } else {
        //TODO remove
        int next = getLink(link[lnk]);
        assert(to[next].count(c));
        link[sz] = to[next][c];
      }
      to[lnk][c] = sz;
      sz++;
    }
    last = to[lnk][c];
    occ[last]++;
  }

  ll go() {
    ll ret = 0;
    for (int i = sz - 1; i >= 0; i--) {
      occ[link[i]] += occ[i];
      ret = max(ret, 1LL * len[i] * occ[i]);
    }
    // vector<string> result(sz);
    // queue<int> q;
    // for (auto it : to[0]) {
    //   result[it.second] = string(1, it.first);
    //   q.push(it.second);
    // }
    // for (auto it : to[1]) {
    //   result[it.second] = string(2, it.first);
    //   q.push(it.second);
    // }
    // while (!q.empty()) {
    //   int u = q.front();
    //   q.pop();
    //   for (auto it : to[u]) {
    //     if (result[it.second] != "") {
    //       continue;
    //     }
    //     result[it.second] = it.first + result[u] + it.first;
    //     q.push(it.second);
    //   }
    // }
    // for (int i = 2; i < sz; i++) {
    //   cout << result[i] << " " << occ[i] << endl;
    // }
    return ret;
  }
};
// }}}
