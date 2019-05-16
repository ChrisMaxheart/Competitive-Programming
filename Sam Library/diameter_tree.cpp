// return.fi = furthest node, .se = distance
pii furthest(vector<vi> &AL, int fromNode) {
    vi dist;

    for (auto x: AL) {
        dist.pb(INF);
    }

    pqdijk dijk;
    dijk.push(mp(0, fromNode));
    while(dijk.size() > 0) {
        auto curr = dijk.top();
        dijk.pop();
        if (dist[curr.se] == INF) {
            dist[curr.se] = curr.fi;
            for (auto x: AL[curr.se]) {
                if (dist[x] == INF) {
                    dijk.push(mp(curr.fi+1, x));
                }
            }
        }
    }

    int idx = -1;
    int maxi = -1;

    for (int i = 0; i < AL.size(); i++) {
        if(dist[i] > maxi && dist[i] != INF) {
            idx = i;
            maxi = dist[i];
        }
        dist[i] = INF;
    }
    return mp(idx, maxi);
}

int diameter(vector<vi> &AL, int node = 0) {
    pii furthest1 = furthest(AL, node);
    pii furthest2 = furthest(AL, furthest1.fi);
    return furthest2.se;
}

vi getDiameterPath(vector<vi> &AL, int node = 0) {
    int furthestNode = furthest(AL, node).fi;

    vi dist;
    vAL lst;

    for (int i = 0; i < AL.size(); i++) {
        vi emp;
        lst.pb(emp);
        dist.pb(INF);
    }

    pqdijk2 dijk;
    vi initpath;
    initpath.pb(furthestNode);
    dijk.push(mp(0, mp(initpath, furthestNode)));
    while(dijk.size() > 0) {
        auto curr = dijk.top();
        dijk.pop();
        if (dist[curr.se.se] == INF) {
            dist[curr.se.se] = curr.fi;
            lst[curr.se.se] = curr.se.fi;
            for (auto x: AL[curr.se.se]) {
                if (dist[x] == INF) {
                    vi path = curr.se.fi;
                    path.pb(x);
                    dijk.push(mp(curr.fi+1, mp(path, x)));
                }
            }
        }
    }

    vi finalpath;
    int maxi = -1;

    for(int i = 0; i < dist.size(); i++) {
        if (dist[i] > maxi && dist[i] != INF) {
            maxi = dist[i];
            finalpath = lst[i];
        }
    }
    return finalpath;
}