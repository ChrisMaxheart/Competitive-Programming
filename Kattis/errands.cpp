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
        #define SZ(S) S.size()
        #define ALL(S) S.begin(), S.end()
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

#define MAX 12
int N;
int dist[MAX][MAX];
int dp[1 << MAX][MAX];
vi dporder[1 << MAX][MAX];

vi tsp(){
    // cout << "test" << endl;
    // 
    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < N; j++) {
    //         cout << dist[i][j] << " ";
    //     } cout << endl;
    // }
    for (int i = 0; i < (1 << MAX); i++) {
        for (int j = 0; j < MAX; j++) {
            dp[i][j] = INF;
            dporder[i][j].clear();
        }
    }
    dp[((1<<N) - 2)][0] = 0;
    // dporder[((1<<N) - 2)][0].pb(0);
    int i, j;
    for (int mask = ((1<<N) - 2); mask >= 0; mask-=2) {
        int rmask = mask ^ ((1 << N)-1);
        // cout << "========================" << endl;
        // cout << rmask << endl;
        // cout << mask << endl;
        while(int temp = LSOne(rmask)) {
            rmask -= temp;
            int idx = __builtin_ctz(temp);
            // cout << "------------------" << endl;
            // cout << dp[mask][idx] << endl;
            if (dp[mask][idx] == INF) {
                continue;
            }
            int dummask = mask;
            while(int temp2 = LSOne(dummask)) {
                dummask -= temp2;
                int idx2 = __builtin_ctz(temp2);
                int new_mask = mask ^ (1 << idx2);
                int cost = dp[mask][idx] + dist[idx][idx2];
                // cout << cost << " " << dp[new_mask][idx2] << endl;
                // cout << "newmask " << new_mask << endl;
                if (dp[new_mask][idx2] > cost) {
                    dp[new_mask][idx2] = min(dp[new_mask][idx2], cost);
                    dporder[new_mask][idx2] = dporder[mask][idx];
                    dporder[new_mask][idx2].pb(idx2);
                }
            }
        }
    }
    int final_mask = 0;
    int ans = INF;
    vi finallst;
    for (i = 1; i < N; ++i) {
        if (ans > dp[final_mask][i] + dist[i][0]) {   
            ans = min(ans, dp[final_mask][i] + dist[i][0] );
            finallst = dporder[final_mask][i];
        }
    }
    // cout << ans << endl;
    return finallst;
}


int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<vd> AM;
    vd distWork;
    umapsi dictmap;
    umapis rdictmap;

    vd xlst, ylst;

    int NMax;
    cin >> NMax;

    for (int i = 0; i < NMax; i++) {
        vd emp;
        for (int j = 0; j < NMax; j++) {
            emp.pb(INF);
        }
        AM.pb(emp);
    }


    int ctr = 0;
    for (int i = 0; i < NMax; i++) {
        string name;
        double x, y;
        cin >> name >> x >> y;
        rdictmap[ctr] = name;
        dictmap[name] = ctr;
        xlst.pb(x);
        ylst.pb(y);
        ctr++;
    }

    // for (auto x : dictmap) {
    //     cout << x.fi << " " << x.se << endl;
    // }

    for (int i = 0; i < NMax; i++) {
        for (int j = i; j < NMax; j++) {
            double dx = xlst[j] - xlst[i];
            double dy = ylst[j] - ylst[i];
            double jarak = sqrt(dx * dx + dy * dy);
            AM[i][j] = jarak;
            AM[j][i] = jarak;
        }
    }

    // for (auto x: AM) {
    //     for (auto y: x) {
    //         cout << y << " ";
    //     } cout << endl;
    // }

    distWork = AM[dictmap["work"]];

    string dummy;
    getline(cin, dummy);

    string lst;
    while(getline(cin, lst)) {
        istringstream iss(lst);
        vi needlst;
        string x;
        while(iss >> x) {
            // cout << x << " ";
            // cout << dictmap[x] << " " << endl;
            needlst.pb(dictmap[x]);
        } 
        // for (auto x: needlst) {
        //     cout << x << " ";
        // } cout << endl;
        N = needlst.size() + 1;
        // umapii newdictmap;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                int newi, newj;
                if (i == 0) {
                    newi = dictmap["home"];
                } else {
                    newi = needlst[i-1];
                }

                if (j == 0) {
                    newj = dictmap["work"];
                } else {
                    newj = needlst[j-1];
                }
                dist[i][j] = AM[newi][newj];
            }
        }

        vi order = tsp();
        reverse(order.begin(), order.end());
        for (auto x: order) {
            cout << rdictmap[needlst[x-1]] << " ";
        } cout << endl;

    }
    return 0;
}