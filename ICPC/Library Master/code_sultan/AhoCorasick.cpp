#include <bits/stdc++.h>
using namespace std;

// {{{ Aho Corasick
namespace AhoCorasick {
  struct Node {
    int next[26];
    int parent;
    int fromParent;
    int fail;
    int wordCount;
  };

  int last;
  Node node[MAXNODE];

  void init() {
    last = 0;
    for (int i = 0; i < MAXNODE; i++) {
      for (int j = 0; j < 26; j++) {
        node[i].next[j] = -1;
      }
      node[i].parent = node[i].fail = -1;
      node[i].wordCount = 0;
    }
    node[0].fail = 0;
  }

  int addString(char *s, int offset = 'a') {
    int len = strlen(s);
    int cur = 0;
    for (int i = 0; i < len; i++) { //no C++11? BibleThump
      if (node[cur].next[s[i] - offset] == -1) {
        node[cur].next[s[i] - offset] = ++last;
        node[last].parent = cur;
        node[last].fromParent = s[i] - offset;
      }
      cur = node[cur].next[s[i] - offset];
    }
    node[cur].wordCount++;
    return cur;
  }

  void constructFail() {
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (int i = 0; i < 26; i++) {
        if (node[u].next[i] != -1) {
          q.push(node[u].next[i]);
        }
      }
      if (u == 0) {
        continue;
      }
      int v = node[node[u].parent].fail;
      int c = node[u].fromParent;
      while (v != 0 && node[v].next[c] == -1) {
        v = node[v].fail;
      }
      node[u].fail = node[v].next[c] != -1  && node[v].next[c] != u ? node[v].next[c] : 0;
    }
  }

  int search(char *s, int offset) {
    int len = strlen(s);
    int cur = 0;
    int match = 0;
    for (int i = 0; i < len; i++) {
      while (cur != 0 && node[cur].next[s[i] - offset] == -1) {
        assert(node[cur].fail != -1);
        cur = node[cur].fail;
      }
      if (node[cur].next[s[i] - offset] != -1) {
        cur = node[cur].next[s[i] - offset];
      }
      assert(cur != -1);
      match += node[cur].wordCount;
    }
    return match;
  }
}
// }}}
