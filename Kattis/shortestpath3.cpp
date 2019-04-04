#include <bits/stdc++.h>

using namespace std;

// to minimize
// defines
const double PI = acos(-1);
#define INF 2000000000000
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
typedef vector<vector<pair<ll,ll>>> vwAL;
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



int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll n, m, q, s;

    bool first = true;

    while(cin >> n >> m >> q >> s, n||m||q||s) {
        if (first) {
            first = false;
        } else {
            cout << endl;
        }

        vwAL AL;
        vll dist;
        vector<bool> lanjut;
        for (int i = 0; i < n; i++) {
            vector<pllll> emp;
            AL.pb(emp);
            lanjut.pb(false);
            dist.pb(INF);
        }

        for (int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            AL[u].pb(mp(v, w));
        }
        dist[s] = 0;

        for (int i = 0; i < n-1; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[j] != INF) {
                    for (auto x : AL[j]) {
                        if (dist[x.fi] > dist[j] + x.se) {
                            dist[x.fi] = dist[j] + x.se;
                        }
                    }
                }
            }
        }

        bool conti = true;

        while(conti) {
            conti = false;
            for (int i = 0; i < n; i++) {
                if (dist[i] == INF) {
                    continue;
                }
                for (auto x : AL[i]) {
                    if (dist[x.fi] > dist[i] + x.se && !lanjut[x.fi]) {
                        conti = true;
                        dist[x.fi] =  -INF;
                        lanjut[x.fi] = true;
                    }
                }
            }
        }

        for (int i = 0; i < q; i++) {
            int x;
            cin >> x;
            if (dist[x] == INF) {
                cout << "Impossible" << endl;
            } else if (lanjut[x]) {
                cout << "-Infinity" << endl;
            } else {
                cout << dist[x] << endl;
            }
        }
    }

    return 0;
}