// tree which represents all-pair min-cut
// min-cut of u-v = minimum edge in path from u to v in tree
// combine the following function with usual max flow routine
// also because we need to reset the flow graph during each max flow, // don't forget to add variable in struct to record initial capacity
void buildGomoryHu() {
  for(int i = 2 ; i <= n ; i++)
    parent[i] = 1;
  for(int i = 2 ; i <= n ; i++) {
    int minCut = maxFlow(i,parent[i]);
    tree[parent[i]].pb({i,minCut});
    // the one below is not necessary if we want to make a rooted tree tree[i].pb({parent[i],minCut});
    for(int j = i + 1 ; j <= n ; j++) {
      if(dist[j] != -1 && parent[j] == parent[i]) {
        parent[j] = i;
      }
    }
  }
}
