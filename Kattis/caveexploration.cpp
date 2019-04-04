#include <bits/stdc++.h>

using namespace std;

// to minimize
    // defines
        const double PI = acos(-1);
        #define INF 1E9
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
        typedef pair<int, int> pii;
        typedef pair<int, string> pis;
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

    // pq/set custom comparator, will get reversed
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

    vector<vi> G;
    int V;

    struct UndirectedDfs {
        vector<int> low, num, parent;
        vector<bool> articulation;
        int counter, root, children;
        vector< pair<int,int> > bridges;
        vector<int> cuts;

        UndirectedDfs() : low(V, 0), num(V, -1), parent(V, 0), articulation(V, false), counter(0), children(0) {
            for(int i = 0; i < V; ++i) if (num[i] == -1) {
                root = i; children = 0;
                dfs(i);
                articulation[root] = (children > 1);
            }
            for(int i = 0; i < V; ++i)
                if (articulation[i]) cuts.push_back(i);
        }

        private:
        void dfs(int u) {
            low[u] = num[u] = counter++;
            for(int j = 0; j < G[u].size(); ++j) {
                int v = G[u][j];
                if (num[v] == -1) {
                    parent[v] = u;
                    if (u == root) 
                        children++;
                    dfs(v);
                    if (low[v] >= num[u])
                        articulation[u] = true;
                    if (low[v] > num[u]) 
                        bridges.push_back(make_pair(u, v));
                    low[u] = min(low[u], low[v]);
                } else if (v != parent[u])
                    low[u] = min(low[u], num[v]);
            }
        }
    };


vector<bool> visited;

void dfs(int x) {
    for (auto y : G[x]) {
        if (!visited[y]) {
            visited[y] = true;
            dfs(y);
        }
    }
    return;
}

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;

    cin >> N >> M;
    V = N;

    for (int i = 0; i < N; i++) {
        vi emp;
        G.pb(emp);
        visited.pb(false);
    }

    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        G[x].pb(y);
        G[y].pb(x);
    }

    UndirectedDfs cond;

    // for (auto x : cond.cuts) {
    //     cout << x << " ";
    // }
    //     cout << endl;

    // for (auto x : cond.bridges) {
    //     cout << x.fi << " " << x.se << endl;
    // }

    for (auto x : cond.bridges) {
        vi emp;
        for (auto y : G[x.fi]) {
            if (y != x.se) {
                emp.pb(y);
            }
        }
        G[x.fi] = emp;

        vi emp2;
        for (auto y : G[x.se]) {
            if (y != x.fi) {
                emp2.pb(y);
            }
        }
        G[x.se] = emp2;

    }

    // for (auto x : G) {
    //     for (auto y : x) {
    //         cout << y << " ";
    //     } cout << endl;
    // }

    visited[0] = true;
    dfs(0);

    int counter = 0;

    for (auto x : visited) {
        if (x) {
            counter++;
        }
    }

    cout << counter << endl;

    return 0;
}