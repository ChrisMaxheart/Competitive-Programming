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

// how to check which edge is used:
// filter the edges in g parameter that have the cap nonzero
// If the cost is -initial cost, then this edge is used, else it is not used
// ===== end of Implementation =====


int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int m, n;
    cin >> m >> n;

    MinCostFlow mf(m * 2 + n + 2);
    int src = m * 2 + n;
    int sink = m * 2 + n + 1;   

    for (int i = 0; i < m; i++) {
        mf.add_edge(src, i, INFflow, 1000);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            mf.add_edge(j, m+j, 1, i+1);
        }
        mf.add_edge(m*2 + i, sink, 2, 0);
    }

    umapis nama;

    for (int i = 0; i < m; i++) {
        string x;
        cin >> x;
        nama[i] = x;
        Tloop {
            int y;
            cin >> y;
            y--;
            mf.add_edge(m + i, 2 * m + y, 1, 100);
        }
    }

    mf.min_cost_flow(src, sink, n*2);
    // cout << "source = " << src << endl;
    // cout << "sink = " << sink << endl;

    unordered_map<int, vs> duty;
    unordered_map<string, int> ctr;

    for (auto y: mf.g) {
        for (auto x: y) {
            if (x.cap && x.cost == -100) {
                string nam = nama[x.to - m];
                ctr[nam]++;
                duty[x.from-(2*m)+1].pb(nam);
            }
        }
    }

    int maxi = -1; 
    for (auto x : ctr) {
        maxi = max(maxi, x.se);
    }

    cout << maxi << endl;
    for (int i = 1; i <= n; i++) {
        cout << "Day " << i << ":";
        for (auto x: duty[i]) {
            cout << " " << x;
        }
        cout << endl;
    }

    return 0;
}