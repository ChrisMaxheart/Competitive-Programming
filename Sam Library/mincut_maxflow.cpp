#define REP(i,n)    for(auto i = decltype(n)(0); i<(n); i++)
constexpr ll LLINF = 1e18+1;
using vb = vector<bool>;
struct S{
    int v;          // neighbour
    const int r;    // index of the reverse edge
    ll f;           // current flow
    const ll cap;   // capacity
    const ll cost;  // unit cost
    S(int v, int reverse_index, ll capacity, ll cost = 0) :
        v(v), r(reverse_index), f(0), cap(capacity), cost(cost) {}
};
struct FlowGraph : vector<vector<S>> {
    FlowGraph(size_t n) : vector<vector<S>>(n) {}
    void add_edge(int u, int v, ll capacity, ll cost = 0){
        operator[](u).emplace_back(v, operator[](v).size(), capacity, cost);
        operator[](v).emplace_back(u, operator[](u).size()-1, 0, -cost);
    }
};



struct Dinic{
    FlowGraph &edges; int V,s,t;
    vi l; vector<vector<S>::iterator> its; // levels and iterators
    Dinic(FlowGraph &edges, int s, int t) :
        edges(edges), V(edges.size()), s(s), t(t), l(V,-1), its(V) {}
    ll augment(int u, ll c) { // we reuse the same iterators
        if (u == t) return c;
        for(auto &i = its[u]; i != edges[u].end(); ++i){
            auto &e = *i;
            if (e.cap > e.f && l[u] < l[e.v]) {
                ll d = augment(e.v, min(c, e.cap - e.f));
                if (d > 0) { e.f += d; edges[e.v][e.r].f -= d; return d; }
            }   }
        return 0;
    }
    ll run() {
        ll flow = 0, f;
        while(true) {
            fill(l.begin(), l.end(),-1); l[s]=0; // recalculate the layers
            queue<int> q; q.push(s);
            while(!q.empty()){
                auto u = q.front(); q.pop();
                for(auto &&e : edges[u]) if(e.cap > e.f && l[e.v]<0)
                    l[e.v] = l[u]+1, q.push(e.v);
            }
            if (l[t] < 0) return flow;
            REP(u,V) its[u] = edges[u].begin();
            while ((f = augment(s, LLINF)) > 0) flow += f;
        }   }
};


void imc_dfs(FlowGraph &fg, int u, vb &cut) {
    cut[u] = true;
    for (auto &&e : fg[u]) {
        if (e.cap > e.f && !cut[e.v])
            imc_dfs(fg, e.v, cut);
    }
}
ll infer_minimum_cut(FlowGraph &fg, int s, vb &cut) {
    cut.assign(fg.size(), false);
    imc_dfs(fg, s, cut);
    ll cut_value = 0LL;
    for (size_t u = 0; u < fg.size(); ++u) {
        if (!cut[u]) continue;
        for (auto &&e : fg[u]) {
            if (cut[e.v]) continue;
            cut_value += e.cap;
            // The edge e from u to e.v is
            // in the minimum cut.
    }   }
    return cut_value;
}

// how to use:
// int main ()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cout.tie(nullptr);
//     ll n, m, s, t;
//     cin >> n >> m >> s >> t;

// ********************************************
// make the graf using flow graph data structure
// 
// ********************************************

//     FlowGraph graf(n);
//     for (int i = 0; i < m; i++) {
//         int u, v;
//         ll capa;
//         cin >> u >> v >> capa;
// ********************************************
//  can add one more variable for cost
//  ********************************************
//         
//         graf.add_edge(u, v, capa);
//     }

// ********************************************
//  run dinic from s to t with flowgraph graf
// ********************************************

//     Dinic mf(graf, s, t);
//     mf.run();

//     vector<bool> incl;
// ********************************************
//     I think infer_minimum_cut will return the maxflow cost
//     The cutset nodes that is together with index s will be shown at the vector of bool
//     If true, the vertex is together with the node s
// ********************************************
//     
//     infer_minimum_cut(graf, s, incl);

//     useti ans;
//     for (int i = 0; i < incl.size(); i++) {
//         if (incl[i]) {
//             ans.insert(i);
//         }
//     }

//     cout << ans.size() << endl;
//     for (auto x : ans) {
//         cout << x << endl;
//     }

//     return 0;
// }