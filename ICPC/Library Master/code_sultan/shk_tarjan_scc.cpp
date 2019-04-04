// UPDATED: run tarjanCheck() after the tarjan loop finishes to find and kill the bug if present, nothing happen if absent
    #define UNVISITED  0
    vector<vi> final;
    vector<vector<pii>> AL;
    vi dfs_num, dfs_low, S, visited; // dfs_num(UNVISITED); dfs_low, visited each has 0 for each node initially
    int dfsNumberCounter = 0;
    int numSCC = 0;

    void emptyTarjan(int m) { // m = vertex total
        final.clear();
        dfs_num.clear();
        dfs_low.clear();
        visited.clear();
        S.clear();
        for (int i = 0; i < m; i++) {
            dfs_num.pb(0);
            dfs_low.pb(0);
            visited.pb(0);
        }
        dfsNumberCounter = 0;
    }

    // how to use, for every node, if dfs_num[node] == UNVISITED, run tarjan on that node
    void tarjanSCC(int u) {
        dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
        S.pb(u);
        visited[u] = 1;
        for (auto &v : AL[u]) {
            if (dfs_num[v.fi] == UNVISITED) {
                tarjanSCC(v.fi);
            }
            if (visited[v.fi]) {
                dfs_low[u] = min(dfs_low[u], dfs_low[v.fi]);
            }
        }
        if(dfs_low[u] == dfs_num[u]) {
            vi emp;
            while(true) {
                int v = S.back();
                S.pop_back();
                visited[v] = 0;
                emp.pb(v);
                if (u == v) {
                    break;
                }
            }
            final.pb(emp);
        }
    }

    void tarjanCheck() {
        int bug = 0;

        for (auto x : final) {
            for (auto y : x) {
                if (y == 0) {
                    bug ++;
                }
            }
        }
        vector<vi> final2;
        if (bug > 1) {
            bool killed = false;
            for (auto x : final) {
                if (x.size() == 1 && x[0] == 0 && !killed) {
                    killed = true;
                } else {
                    vi emp;
                    for (auto y : x) {
                        emp.pb(y);
                    }
                    final2.pb(emp);
                }       
            }
            final = final2;
        }
        return;
    }