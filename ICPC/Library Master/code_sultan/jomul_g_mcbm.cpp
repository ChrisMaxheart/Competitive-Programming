vector<vi> AdjList;
vi match, vis;                                          // global variables

int Aug(int l) {                 // return 1 if an augmenting path is found
  if (vis[l]) return 0;                               // return 0 otherwise
  vis[l] = 1;
  for (int j = 0; j < (int)AdjList[l].size(); j++) {
    int r = AdjList[l][j];
    if (match[r] == -1 || Aug(match[r])) {
      match[r] = l; return 1;                           // found 1 matching
  } }
  return 0;                                                  // no matching
}

int main() {
  int V = 5, Vleft = 3;                               // we ignore vertex 0
  AdjList.assign(V, vi());
  AdjList[1].push_back(3); AdjList[1].push_back(4);
  AdjList[2].push_back(3);

  int MCBM = 0;
  match.assign(V, -1);    // V is the number of vertices in bipartite graph
  for (int l = 0; l < Vleft; l++) {         // Vleft = size of the left set
    vis.assign(Vleft, 0);                    // reset before each recursion
    MCBM += Aug(l);
  }
  printf("Found %d matchings\n", MCBM);  // the answer is 2 for Figure 4.42

  return 0;
}
