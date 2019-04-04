// To run, initialize MinCostFlow mf(v);
// then add edge using add_edge
// then run using min_cost_flow

// how to check which edge is used after run:
// filter the edges in g parameter that have the cap nonzero
// If the cost is -initial cost, then this edge is used, else it is not used

typedef pair<ll, int> P; // for spfa
struct Edge {
    int from, to, cap; ll cost; int rev;
};
struct MinCostFlow {
    static ll INFLL;
    int V;
    vector< vector<Edge> > g;
    vector<int> prevv;
    vector<int> preve;
    // vector<int> match;
    MinCostFlow();
    MinCostFlow(int v);
    void add_edge(int u, int v, int cap, ll cost);
    ll min_cost_flow(int s, int t, int f);
};
// ===== end of Declaration =====
ll MinCostFlow::INFLL = 1e18;
MinCostFlow::MinCostFlow() {;}
MinCostFlow::MinCostFlow(int v): V(v) {
    g = vector< vector<Edge> >(V);
    prevv = vector<int>(V, -1);
    preve = vector<int>(V, -1);
    // match = vector<int>(V, -1);
}

void MinCostFlow::add_edge(int u, int v, int cap, ll cost) {
    g[u].push_back((Edge) {u, v, cap, cost, int(g[v].size())});
    g[v].push_back((Edge) {v, u, 0, -cost, int(g[u].size() - 1)});
}

// What is the minimum cost for this graph from s to t with flow f (if it is impossible, will return -1)
ll MinCostFlow::min_cost_flow(int s, int t, int f) {
    ll res = 0;
    vector<ll> h(V, 0);
    vector<ll> d(V, INFLL);

    while (f > 0) {
        fill(d.begin(), d.end(), INFLL);
        priority_queue< P, vector<P>, greater<P> > pq;

        d[s] = 0;
        pq.push(P(d[s], s));

        while (!pq.empty()) {
            P p = pq.top(); pq.pop();
            int v = p.second;
            if (d[v] < p.first) continue;
            for (int i = 0; i < int(g[v].size()); i++) {
                const Edge& e = g[v][i];
                if (e.cap > 0 && d[e.to] > d[v] + e.cost + h[v] - h[e.to]) {
                    d[e.to] = d[v] + e.cost + h[v] - h[e.to];
                    prevv[e.to] = v;
                    preve[e.to] = i;
                    pq.push(P(d[e.to], e.to));
                }
            }
        }

        if (d[t] == INFLL)
            return -1;

        for (int v = 0; v < V; v++)
            h[v] += d[v];

        int bn = f;
        for (int v = t; v != s; v = prevv[v])
            bn = min(bn, g[prevv[v]][preve[v]].cap);

        // // find match
        // for (int v = prevv[t]; v != s; v = prevv[prevv[v]]) {
        //     int u = prevv[v];
        //     match[v] = u;
        //     match[u] = v;
        // }

        f -= bn;
        res += bn * h[t];
        for (int v = t; v != s; v = prevv[v]) {
            Edge& e = g[prevv[v]][preve[v]];
            e.cap -= bn;
            g[v][e.rev].cap += bn;
        }
    }
    return res;
}


// ===== end of Implementation =====