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

        int loc(int r, int c) {
            return 100 * r + c;
        }

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int r, c;

    while(cin >> r >> c, r || c) {
//        cout << r << " " << c << endl;
        vwAL AL;
        vAL pta;
        vi dist;
        vector<seti> histsave;
        for (int i = 0; i < r+2; i++) {
            string x;
            vi emp;
            if (i != 0 && i != r+1) {
                cin >> x;
            }
            for (int j = 0; j < c+2; j++) {
                if (i == 0 || i == r+1 || j == 0 || j == c+1) {
                    emp.pb(INF);
                } else {
                    int y = x[j-1]-'0';
                    emp.pb(y);
                }
            }
            pta.pb(emp);
        }

        for (int i = 0; i < loc(100, 100); i++) {
            vector<pii> emp;
            AL.pb(emp);
            dist.pb(INF);

            seti hist;
            histsave.pb(hist);
        }

        for (int i = 1; i < r+1; i++) {
            for (int j = 1; j < c+1; j++) {
                AL[loc(i,j)].pb(mp(loc(i, j-1), pta[i][j-1]));
                AL[loc(i,j-1)].pb(mp(loc(i, j), pta[i][j]));

                AL[loc(i,j)].pb(mp(loc(i-1, j-1), pta[i-1][j-1]));
                AL[loc(i-1,j-1)].pb(mp(loc(i, j), pta[i][j]));

                AL[loc(i,j)].pb(mp(loc(i-1, j), pta[i-1][j]));
                AL[loc(i-1,j)].pb(mp(loc(i, j), pta[i][j]));

                AL[loc(i,j)].pb(mp(loc(i-1, j+1), pta[i-1][j+1]));
                AL[loc(i-1,j+1)].pb(mp(loc(i, j), pta[i][j]));

                if (i == 1) {
                    AL[loc(97,97)].pb(mp(loc(i, j), pta[i][j]));
                }
                if (i == r) {
                    AL[loc(i,j)].pb(mp(loc(98,98), 0));
                }

            }
        }

//        for (auto x : AL[loc(1, 1)]) {
//            cout << x.fi/100 <<" " << x.fi%100 << " " << x.se << endl;
//        }
//        cout << "test" << endl;
        seti hist;
//        hist.insert(loc(97, 97));

        priority_queue< pair<int, pair<int, seti>> , vector<pair<int, pair<int, seti>>> , greater<pair<int, pair<int, seti>>> > dijk;

        dijk.push(mp(0, mp(loc(97,97), hist)));
//        cout << dist[103] << endl;
//        cout << AL.size() << endl;
//        cout << dist.size() << endl;
        while(dijk.size() > 0) {
            auto curr = dijk.top();
            dijk.pop();
//            cout << curr.fi << " " << curr.se.fi  << endl;
//            if (curr.se.fi > loc(98, 98)) {
//                cout << "error" << endl;
//                break;
//            }
            if (dist[curr.se.fi] == INF) {
                dist[curr.se.fi] = curr.fi;
                histsave[curr.se.fi] = curr.se.se;
//                cout << curr.se.fi/100 << " " << curr.se.fi%100 << endl;
                for (auto x : AL[curr.se.fi]) {
//                    if (x.fi > loc(98, 98)) {
//                        cout << "error2" << endl;
//                        break;
//                    }
//                    cout << x.fi/100 << " " << x.fi%100 << " " << dist[x.fi] << endl;
                    if (dist[x.fi] == INF) {
                        seti hist2 = curr.se.se;
                        if (curr.se.fi != loc(97, 97)) {
                            hist2.insert(curr.se.fi);
                        }
                        dijk.push(mp(curr.fi+x.se, mp(x.fi, hist2)));
                    }

                }
            }
        }

//        for (auto x : histsave[loc(98,98)]) {
//            cout << x << endl;
//        }

        for (auto x: histsave[loc(98,98)]) {
//            cout << x << endl;
//            cout << x/100 << " " << x%100 << endl;
            pta[x/100][x%100] = -1;
        }

        for (int i = 1; i < pta.size()-1; i++ ) {
            auto x = pta[i];
            for (int j = 1; j < pta[0].size()-1; j++) {
                auto y = x[j];
                if (y != -1) {

                    cout << y;
                }
                else {
                    cout << " ";
                }
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}