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

//UFDS, 0 based
//how to use: UnionFind var(no_of_vertex)
//then just use var.func(param)
        class UnionFind {
        private:
            vi p, rank, setSize;
            int numSets;

        public:
            UnionFind(int N) {
                setSize.assign(N, 1);
                numSets = N;
                rank.assign(N,0);
                p.assign(N,0);
                for (int i = 0; i < N; i++) {
                    p[i] = i;
                }
            }
            int findSet(int i) {
                return (p[i] == i) ? i : (p[i] = findSet(p[i]));
            }
            bool isSameSet(int i, int j) {
                return findSet(i) == findSet(j);
            }
            void unionSet(int i, int j) {
                if(!isSameSet(i,j)) {
                    numSets--;
                    int x = findSet(i);
                    int y = findSet(j);
                    if (rank[x] > rank[y]) {
                        p[y] = x;
                        setSize[x] += setSize[y];
                    } else {
                        p[x] = y;
                        setSize[y] += setSize[x];
                        if(rank[x] == rank[y]) {
                            rank[y]++;
                        }
                    }
                }
            }
            int numDisjointSets() {
                return numSets;
            }
            int sizeOfSet(int i) {
                return setSize[findSet(i)];
            }
        };


int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    vector<pair<int, pii>> EL;
    vector<vi> AL;


    for (int i = 0; i < N; i++) {
        vi emp;
        AL.pb(emp);
        for (int j = 0; j < N; j++) {
            int x;
            cin >> x;
            if (i <= j) {
                continue;
            }
            EL.pb(mp(x, mp(i, j)));
        }
    }

    sort(EL.begin(), EL.end()); 

    UnionFind ufds(N);

    for (auto x : EL) {
        if (!ufds.isSameSet(x.se.fi, x.se.se)) {
            ufds.unionSet(x.se.fi, x.se.se);
            if(x.se.fi < x.se.se) {
                AL[x.se.fi].pb(x.se.se);
            } else {
                AL[x.se.se].pb(x.se.fi);
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (auto x : AL[i]) {
            cout << i+1 << " " << x+1 << endl;
        }
    }


    return 0;
}