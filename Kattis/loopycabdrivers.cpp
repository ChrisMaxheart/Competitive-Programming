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

#define UNVISITED  0
vector<vi> final;
vector<vector<pii>> AL;
vi dfs_num, dfs_low, S, visited; // dfs_num(UNVISITED); dfs_low, visited each has 0 for each node initially
int dfsNumberCounter = 0;
int numSCC = 0;

void emptyTarjan(int m) { // m = vertex total
    final.clear();
    dfs_num.clear();
    dfs_low.clear();
    visited.clear();
    S.clear();
    for (int i = 0; i < m; i++) {
        dfs_num.pb(0);
        dfs_low.pb(0);
        visited.pb(0);
    }
    dfsNumberCounter = 0;
}

// how to use, for every node, if dfs_num[node] == UNVISITED, run tarjan on that node
void tarjanSCC(int u) {
    dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
    S.pb(u);
    visited[u] = 1;
    for (auto &v : AL[u]) {
        if (dfs_num[v.fi] == UNVISITED) {
            tarjanSCC(v.fi);
        }
        if (visited[v.fi]) {
            dfs_low[u] = min(dfs_low[u], dfs_low[v.fi]);
        }
    }
    if(dfs_low[u] == dfs_num[u]) {
        vi emp;
        while(true) {
            int v = S.back();
            S.pop_back();
            visited[v] = 0;
            emp.pb(v);
            if (u == v) {
                break;
            }
        }
        final.pb(emp);
    }
}

void tarjanCheck() {
    int bug = 0;

    for (auto x : final) {
        for (auto y : x) {
            if (y == 0) {
                bug ++;
            }
        }
    }
    vector<vi> final2;
    if (bug > 1) {
        bool killed = false;
        for (auto x : final) {
            if (x.size() == 1 && x[0] == 0 && !killed) {
                killed = true;
            } else {
                vi emp;
                for (auto y : x) {
                    emp.pb(y);
                }
                final2.pb(emp);
            }
        }
        final = final2;
    }
    return;
}

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    umapsi idx;
    umapis revidx;

    int counter = 0;

    vi dari, untuk;

    Nloop {
        string x, y;
        cin >> x >> y;
        if (idx.find(x) == idx.end()) {
            idx[x] = counter;
            revidx[counter] = x;
            counter++;
        }
        if (idx.find(y) == idx.end()) {
            idx[y] = counter;
            revidx[counter] = y;
            counter++;

        }
        dari.pb(idx[x]);
        untuk.pb(idx[y]);
    }

    emptyTarjan(counter);
    for (int i = 0; i < counter; i++) {
        vector<pii> emp;
        AL.pb(emp);
    }

    for (int i = 0; i < dari.size(); i++) {
        int dr = dari[i];
        int utk = untuk[i];
        AL[dr].pb(mp(utk, 1));
    }

    for (int i = 0; i < counter; i++) {
        if(dfs_num[i] == UNVISITED) {
            tarjanSCC(i);
        }
    }
    tarjanCheck();
    vector<vs> ans;
    for (auto x : final) {
        vs emp;
        for (auto y: x) {
            emp.pb(revidx[y]);
        }
        ans.pb(emp);
    }
    for (int i = 0; i < ans.size(); i++) {
        sort(ans[i].begin(), ans[i].end());
    }
    sort(ans.begin(), ans.end());

    for (auto x : ans) {
        if (x.size() > 1) {
            cout << "okay";
            for (auto y : x) {
                cout << " " << y;
            }
            cout << endl;
        }
    }
    bool pertama = true;
    for (auto x : ans) {
        if (x.size() == 1) {
            if (pertama) {
                cout << "avoid";
                pertama = false;
            }
            cout << " " << x[0];
        }
    }
    if (!pertama) {
        cout << endl;
    }


    return 0;
}