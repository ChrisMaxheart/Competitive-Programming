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

// tarjanSCC
    // there is bug, kalau idx 0 bukan anggota strongly connected component yang lebih dari satu anggota dan ada yang nunjuk ke idx 0, final answer mesti -1
    // ntar ada kemungkinan hasilnya ada 2 components scc yang 2 2 nya satu anggota, anggotanya 0, kalau rootnya bukan root scc dan ada yang nunjuk ke root
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

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    Tloop {
        int n, m;
        cin >> n >> m;

        emptyTarjan(n);
        AL.clear();

        for (int i = 0; i < n; i++) {
            vector<pii> emp;
            AL.pb(emp);

        }

        for (int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;
            x--;
            y--;
            AL[x].pb(mp(y, 1));
        }

        for (int i = 0; i < n; i++) {
            if (dfs_num[i] == UNVISITED) {
                tarjanSCC(i);
            }
        }

        // for (auto x : final) {
        //     for (auto y : x) {
        //         cout << y << " ";
        //     }
        //     cout << endl;
        // }

        int starto = 0;

        tarjanCheck();

        // cout << starto << endl;

        umapii dct;
        for (int i = starto; i < final.size(); i++) {
            for (auto x : final[i]) {
                dct[x] = i;
            }
        }

        vector<vi> AL2;

        vector<bool> haveincoming;

        for (int i = starto; i < final.size(); i++) {
            haveincoming.pb(false);
        }

        for (int i = starto; i < final.size(); i++) {
            for (auto x : final[i]) {
                for (auto y : AL[x]) {
                    if (dct[y.fi] != i) {
                        // cout << dct[y.fi] << endl;
                        haveincoming[dct[y.fi]] = true;
                    }
                }
            }
        }

        // cout << haveincoming.size() << endl;

        int counter = 0;

        for (auto x : haveincoming) {
            // cout << x << endl;
            if (!x) {
                counter++;
            }
        }

        cout << counter << endl;

    }

    return 0;
}