#include <bits/stdc++.h>

using namespace std;

// to minimize
    // defines
        const double PI = acos(-1);
        #define INF 1E9
        #define INFflow 1E8
        #define endl '\n'
        #define Tloop int T; cin >> T; for(int count_ = 1; count_ < T+1; count_++)
        #define Nloop int N; cin >> N; for(int count__ = 0; count__ < N; count__++)
        #define printcaseg cout << "Case #" << count_ << ": "
        #define printcaseu cout << "Case " << count_ << ": "
        #define MOD 1000000007
        #define LSOne(S) ((S)&(-S))
        #define pb push_back
        #define fi first
        #define se second
        #define eb emplace_back
        #define mp make_pair

    // A lot of typedefs
        typedef long long ll;
        typedef unsigned long long ull;
        typedef stack<int> si;
        typedef stack<long long> sll;
        typedef stack<string> ss;
        typedef stack<double> sd;
        typedef queue<int> qi;
        typedef queue<long long> qll;
        typedef queue<string> qs;
        typedef queue<double> qd;
        typedef deque<int> di;
        typedef deque<long long> dll;
        typedef deque<string> ds;
        typedef deque<double> dd;
        typedef priority_queue<int> pqi;
        typedef priority_queue<long long> pqll;
        typedef priority_queue<string> pqs;
        typedef priority_queue<double> pqd;
        typedef priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pqdijk;
        typedef set<int> seti;
        typedef set<long long> setll;
        typedef set<string> sets;
        typedef set<double> setd;
        typedef unordered_set<int> useti;
        typedef unordered_set<long long> usetll;
        typedef unordered_set<string> usets;
        typedef unordered_set<double> usetd;
        typedef map<int, string> mapis;
        typedef map<string, int> mapsi;
        typedef map<long long, string> maplls;
        typedef map<string, long long> mapsll;
        typedef map<int, int> mapii;
        typedef map<string, string> mapss;
        typedef map<long long, long long> mapllll;
        typedef map<long long, double> maplld;
        typedef map<double, long long> mapdll;
        typedef map<string, double> mapsd;
        typedef map<double, string> mapds;
        typedef map<int, double> mapid;
        typedef map<double, int> mapdi;
        typedef unordered_map<int, string> umapis;
        typedef unordered_map<string, int> umapsi;
        typedef unordered_map<long long, string> umaplls;
        typedef unordered_map<string, long long> umapsll;
        typedef unordered_map<int, int> umapii;
        typedef unordered_map<string, string> umapss;
        typedef unordered_map<long long, long long> umapllll;
        typedef unordered_map<long long, double> umaplld;
        typedef unordered_map<double, long long> umapdll;
        typedef unordered_map<string, double> umapsd;
        typedef unordered_map<double, string> umapds;
        typedef unordered_map<int, double> umapid;
        typedef unordered_map<double, int> umapdi;
        typedef vector<int> vi;
        typedef vector<long long> vll;
        typedef vector<string> vs;
        typedef vector<double> vd;
        typedef vector<vector<pair<int,int>>> vwAL;
        typedef vector<vector<int>> vAL;
        typedef pair<int, int> pii;
        typedef pair<int, string> pis;
        typedef pair<string, int> psi;
        typedef pair<long long, long long> pllll;
        typedef pair<long long, string> plls;
        typedef pair<double, string> pds;
        typedef pair<double, double> pdd;
        typedef pair<double, int> pdi;
        typedef pair<double, long long> pdll;

    // struct
        struct mystruct {
            int counter;
        };

    //custom hashing
        struct custom_hash {
            inline std::size_t operator()(const std::pair<int,int> & v) const {
                    return v.first*31+v.second*7;
            }
        };

    // pq/set custom comparator
        class mycomp {
            public:
            bool operator() (mystruct a, mystruct b) {
                return a.counter > b.counter;
            }
        };

    // sort custom comparator
        bool customcompare(mystruct a, mystruct b) {
            return a.counter > b.counter;
        }

        // string split
        vector<string> strsplit(string toSplit, char tok) {
            vector<string> ans;
            string token;
            istringstream iss(toSplit);
            while(getline(iss, token, tok)) {
                ans.pb(token);
            }
            return ans;
        }

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

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll n, m, s, t;
    cin >> n >> m >> s >> t;

    FlowGraph graf(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        ll capa;
        cin >> u >> v >> capa;
        graf.add_edge(u, v, capa);
    }

    Dinic mf(graf, s, t);
    mf.run();

    vector<bool> incl;
    infer_minimum_cut(graf, s, incl);

    useti ans;
    for (int i = 0; i < incl.size(); i++) {
        if (incl[i]) {
            ans.insert(i);
        }
    }

    cout << ans.size() << endl;
    for (auto x : ans) {
        cout << x << endl;
    }

    return 0;
}