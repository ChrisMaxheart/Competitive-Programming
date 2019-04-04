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

int findavail(int g, int dur, int curr) {
    if (g > curr || g+dur <= curr) {
        return 0;
    } else {
        return g + dur - curr;
    }
}    

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<unordered_map<int, int>> AL;
    vector<umapii> george;
    int V, E;
    cin >> V >> E;
    vi dist;

    for (int i = 0; i < V; i++) {
        umapii emp, emp2;
        AL.pb(emp);
        george.pb(emp2);
        dist.pb(INF);
    }

    int strt, trget, dt, g;
    cin >> strt >> trget >> dt >> g;
    strt--; trget--;

    vi glst;

    for (int i = 0; i < g; i++) {
        int x;
        cin >> x;
        glst.pb(x);
    }

    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        AL[u][v] = w;
        AL[v][u] = w;
        george[u][v] = -w;
        george[v][u] = -w;
    }

    int currg = 0;

    for (int i = 0; i < glst.size()-1; i++) {
        auto v1 = glst[i];
        auto v2 = glst[i+1];
        v1--;
        v2--;
        george[v1][v2] = currg;
        george[v2][v1] = currg;
        // cout << v1 << "&"<<v2 << " " << currg << endl;
        currg += AL[v1][v2];
    }

    pqdijk dijk;


    dijk.push(mp(dt, strt));

    while(dijk.size() > 0) {
        auto curr = dijk.top();
        dijk.pop();
        if (dist[curr.se] == INF) {
            dist[curr.se] = curr.fi;
            for (auto x : AL[curr.se]) {
                if (x.se == 0) {
                    continue;
                }
                // cout << gtime << endl;
                if (dist[x.fi] == INF) {
                    int gtime = findavail(george[x.fi][curr.se], x.se, curr.fi);
                    // cout << x.fi << " " <<  x.se << " + " << gtime << " + " << curr.fi << endl;
                    dijk.push(mp(x.se+gtime+curr.fi, x.fi));
                }
            }
        }
    }

    // for (auto x : dist) {
    //     cout << x << " ";
    // } cout << endl;

    cout << dist[trget] - dt << endl;

    return 0;
}