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

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N1, N2, M1, M2;

    cin >> N1 >> N2 >> M1 >> M2;

    vAL AL, AL2;
    vector<useti> dist, dist2;

    for (int i = 0; i < N1; i++) {
        vi emp;
        AL.pb(emp);

        useti emp2;
        dist.pb(emp2);
    }

    for (int i = 0; i < N2; i++) {
        vi emp;
        AL2.pb(emp);

        useti emp2;
        dist2.pb(emp2);
    }

    for (int i = 0; i < M1; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        AL[x].pb(y);
    }

    for (int i = 0; i < M2; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        AL2[x].pb(y);
    }

    pqdijk dijk;

    dijk.push(mp(0, 0));

    while(dijk.size() > 0) {
        auto curr = dijk.top();
        dijk.pop();
        if (dist[curr.se].find(curr.fi) == dist[curr.se].end()) {
            dist[curr.se].insert(curr.fi);
            for (auto x : AL[curr.se]) {
                int newdist = curr.fi + 1;
                if (dist[x].find(newdist) == dist[x].end()) {
                    dijk.push(mp(newdist, x));
                }
            }
        }
    }

    dijk.push(mp(0, 0));

    while(dijk.size() > 0) {
        auto curr = dijk.top();
        dijk.pop();
        if (dist2[curr.se].find(curr.fi) == dist2[curr.se].end()) {
            dist2[curr.se].insert(curr.fi);
            for (auto x : AL2[curr.se]) {
                int newdist = curr.fi + 1;
                if (dist2[x].find(newdist) == dist2[x].end()) {
                    dijk.push(mp(newdist, x));
                }
            }
        }
    }

    int Q;
    cin >> Q;
    useti final;

    for (auto x: dist[N1-1]) {
        for (auto y: dist2[N2-1]) {
            final.insert(x+y);
        }
    }
    for (int i = 0; i < Q; i++) {
        int x;
        cin >> x;
        if (final.find(x) == final.end()) {
            cout << "No" << endl;
        } else {
            cout << "Yes" << endl;
        }
    }
    return 0;
}