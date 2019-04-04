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

        

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    int arr[100][100];

    arr[0][0] = 10000;

    int kri = 0;
    int knan = 99;
    int atas = 0;
    int bwah = 99;
    int hadap = 1;

    int curr = 0;
    int val = arr[0][0]-1;

    while(true) {
        if (val == 0) {
            break;
        }
        if (hadap == 1) {
            curr += 1;
            if (curr%100 == knan) {
                hadap = 2;
                atas++;
            }
        } else if (hadap == 2) {
            curr += 100;
            if (curr/100 == bwah) {
                hadap = 3;
                knan--;
            }
        } else if (hadap == 3) {
            curr -= 1;
            if (curr%100 == kri) {
                hadap = 4;
                bwah--;
            }
        } else {
            curr -= 100;
            if (curr / 100 == atas) {
                hadap = 1;
                kri++;
            }
        }
        arr[curr/100][curr%100] = val;
        val--;
    }

    // for (int i = 0; i < 100; i++) {
    //     for (int j = 0; j < 100; j++) {
    //         cout << arr[i][j] << " ";
    //     } cout << endl;
    // }

    vector<bool> sieve;

    for (int i = 0; i < 100005; i++) {
        sieve.pb(true);
    }

    sieve[0] = false;
    sieve[1] = false;

    for (int i = 2; i < 100005; i++) {
        if (sieve[i]) {
            for (int j = 2; j < 5003; j++) {
                if (i * j > 10000) {
                    break;
                }
                sieve[i*j] = false;
            }
        }
    }

    // for (int i = 0; i < 100; i++) {
    //     if (sieve[i]) {
    //         cout << 1 << " ";
    //     } else {
    //         cout << 0 << " ";
    //     }
    // }

    vAL AL;
    for (int i = 0; i < 10001; i++) {
        vi emp;
        AL.pb(emp);
    }

    for (int i = 0; i < 99; i++) {
        for (int j = 0; j < 100; j++) {
            if (!sieve[arr[i][j]] && !sieve[arr[i+1][j]]) {
                AL[arr[i][j]].pb(arr[i+1][j]);
                AL[arr[i+1][j]].pb(arr[i][j]);
            }
        }
    }

    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 99; j++) {
            if (!sieve[arr[i][j]] && !sieve[arr[i][j+1]]) {
                AL[arr[i][j]].pb(arr[i][j+1]);
                AL[arr[i][j+1]].pb(arr[i][j]);
            }
        }
    }

    int x, y;
    int counter = 0;
    while(cin >> x >> y) {
        counter++;
        cout << "Case " << counter << ": ";
        vi dist;
        for (int i = 0; i < 10001; i++) {
            dist.pb(INF);
        }

        pqdijk dijk;
        dijk.push(mp(0, x));

        while(dijk.size() > 0) {
            auto curr = dijk.top();
            dijk.pop();
            if (dist[curr.se] == INF) {
                // cout << curr.se << "&&" << curr.fi << endl;
                dist[curr.se] = curr.fi;
                for (auto z : AL[curr.se]) {
                    // cout << z << endl;
                    if (dist[z] == INF) {
                        dijk.push(mp(curr.fi+1, z));
                    }
                }
            }
        }

        // cout << x << " " << y <<": " << dist[y] << endl;

        if (dist[y] == INF) {
            cout << "impossible" << endl;
        } else {
            cout << dist[y] << endl;
        }
    }

    return 0;
}