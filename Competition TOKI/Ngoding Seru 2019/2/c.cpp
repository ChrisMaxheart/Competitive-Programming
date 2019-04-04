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

    vAL AL;
    int N, Q;
    cin >> N >> Q;

    for (int i = 0; i < N; i++) {
        vi emp;
        AL.pb(emp);
    }

    vAL AM;
    for (int i = 0; i < N; i++) {
        vi emp;
        for (int j = 0; j < N; j++) {
            emp.pb(INF);
        }
        AM.pb(emp);
    }

    for (int i = 0; i < N-1; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        AL[x].pb(y);
        AL[y].pb(x);
    }

    // for (int i = 0; i < N; i++) {
    //     cout << "node " << i << endl;

    //     for (auto x : AL[i]) {
    //         cout << x << " ";
    //     } cout << endl;
    // }

    for (int i = 0; i < N; i++) {
        pqdijk dijk;
        dijk.push(mp(0, i));
        while(dijk.size() > 0) {
            auto curr = dijk.top();
            dijk.pop();
            if (AM[i][curr.se] == INF) {
                // cout << i << " and " << curr.se << " bernilai " << curr.fi << endl;
                AM[i][curr.se] = curr.fi;
                for (auto x : AL[curr.se]) {
                    // cout << x << " ";
                    if (AM[i][x] == INF) {
                        dijk.push(mp(curr.fi+1, x));
                    }
                }
                // cout << endl;
            }
        }
    }

    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < N; j++) {
    //         cout << AM[i][j] << " ";
    //     } cout << endl;
    // }

    useti isi;

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        if (x) {
            isi.insert(i);
        }
    }



    for (int i = 0; i < Q; i++) {
        int quer;
        cin >> quer;
        if (quer == 1) {
            ll cost = 0;
            vi anggota;
            for (auto x : isi) {
                anggota.pb(x);
            }

            for (int i = 0; i < anggota.size(); i++) {
                for (int j = i+1; j < anggota.size(); j++) {
                    int org1 = anggota[i];
                    int org2 = anggota[j];
                    cost += AM[org1][org2];
                }
            }

            cout << cost << endl;

        } else {
            int x;
            cin >> x;
            x--;
            if (isi.find(x) == isi.end()) {
                isi.insert(x);
            } else {
                isi.erase(x);
            }
        }
    }

    return 0;
}