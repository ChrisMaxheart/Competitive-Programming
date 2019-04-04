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
            return 2005 * r + c;
        }

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int m1;

    while (cin >> m1, m1) {
        vAL AL;
        vi dist;

        // source 2003, 2003 dest 2003, 2002
        for (int i = 0; i < loc(2001, 2004); i++) {
            vi emp;
            AL.pb(emp);
            dist.pb(INF);
        }

        for (int i = 1; i < 2002; i++) {
            for (int j = 1; j < 2002; j++) {
                auto curr = loc(i, j);
                auto nxt1 = loc(i-1, j);
                auto nxt2 = loc(i, j-1);
                AL[curr].pb(nxt1);
                AL[nxt1].pb(curr);
                AL[curr].pb(nxt2);
                AL[nxt2].pb(curr);
            }
        }

        int maxrow = -1;
        int minrow = 10000;
        int maxcol = -1;
        int mincol = 10000;
        auto src = loc(2001, 2002);
        auto dest = loc(2001, 2003);

        for (int i = 0; i < m1; i++) {
            int x, y;
            cin >> x >> y;
            x++;
            y++;
            maxrow = max(maxrow, x);
            minrow = min(minrow, x);
            maxcol = max(maxcol, y);
            mincol = min(mincol, y);
            auto curr = loc(x, y);
            AL[curr].pb(src);
            AL[src].pb(curr);
        }
        int m2;
        cin >> m2;
        for (int i = 0; i < m2; i++) {
            int x, y;
            cin >> x >> y;
            x++;
            y++;
            maxrow = max(maxrow, x);
            minrow = min(minrow, x);
            maxcol = max(maxcol, y);
            mincol = min(mincol, y);
            auto curr = loc(x, y);
            AL[curr].pb(dest);
            AL[dest].pb(curr);
        }

        queue<pii> bfs;

        bfs.push(mp(loc(2001, 2002), 0));

//        cout << mincol << " " << maxcol << " " << minrow << " " << maxrow << endl;
        while(bfs.size() > 0) {
            if (dist[loc(2001, 2003)] != INF) {
                break;
            }
            auto curr = bfs.front();
            bfs.pop();
            if (dist[curr.fi] == INF) {
                dist[curr.fi] = curr.se;
                for (auto x : AL[curr.fi]) {
                    int rw = x/2005;
                    int cl = x%2005;
//                    cout << rw <<" " << cl << endl;
                    if (x != loc(2001, 2003) && (rw < minrow || rw > maxrow || cl < mincol || cl > maxcol)) {
                        continue;
                    }
                    if (dist[x] == INF) {
                        bfs.push(mp(x, curr.se+1));
                    }
                }
            }
        }

        cout << dist[loc(2001, 2003)] - 2 << endl;
    }



    return 0;
}