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

        
int locrc(int r, int c) {
    return 1000 * r + c;
}

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int r, c;
    cin >> r >> c;

    vi dist;

    unordered_map<int, vi> AL;

    for (int i = 0; i < 1000000; i++) {
        dist.pb(INF);
    }

    for (int i = 0; i < r + 18; i++) {
        string x;
        if (i >= 9 && i <= r + 8) {
            cin >> x;
        }
        for (int j = 0; j < c + 18; j++) {
            if (i < 9 || i > r + 8 || j < 9 || j > c + 8) {
                dist[locrc(i, j)] = -1;
            } else {
                int idx = j - 9;
                int val = x[idx] - '0';
                int id = locrc(i, j);
                int tar1 = locrc(i+val, j);
                int tar2 = locrc(i-val, j);
                int tar3 = locrc(i, j+val);
                int tar4 = locrc(i, j-val);

                AL[id].pb(tar1);
                AL[id].pb(tar2);
                AL[id].pb(tar3);
                AL[id].pb(tar4);
            }
        }
    }

    priority_queue<pii, vector<pii>, greater<pii>> dijk;

    dijk.push(mp(0, locrc(9, 9)));

    while(dijk.size() > 0) {
        auto curr = dijk.top();
        dijk.pop();
        if (dist[curr.se] == INF) {
            dist[curr.se] = curr.fi;
            for (auto x : AL[curr.se]) {
                if (dist[x] == INF) {
                    dijk.push(mp(curr.fi+1, x));
                }
            }
        }
    }


    // for (int i = 0; i < r; i++) {
    //     for (int j = 0; j < c; j++) {
    //         int valr = i+9;
    //         int valc = j+9;
    //         cout << dist[locrc(valr, valc)] << " ";
    //     }
    //     cout << endl;
    // }

    // for (int i = 0; i < r; i++) {
    //     for (int j = 0; j < c; j++) {
    //         int valr = i+9;
    //         int valc = j+9;
    //         cout << locrc(valr, valc) << " ";
    //     }
    //     cout << endl;
    // }

    int val = dist[locrc(9+r-1, 9+c-1)];
    // cout << locrc(9+r, 9+c) << endl;
    if(val == INF) {
        cout << -1 << endl;
    } else {
        cout << val << endl;
    }

    return 0;
}