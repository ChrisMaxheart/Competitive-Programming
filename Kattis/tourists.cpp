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


#define MAXN 400000                           // adjust this value as needed
#define L2_N 19        // 2^14 = 16384 > 10000, adjust this value as needed

// class RMQ {                                          // Range Minimum Query
// private:
//   int i, j, k, x, y, P2[L2_N], L2[(1<<L2_N)+10], _A[MAXN], SpT[L2_N][MAXN];
// public:
//   RMQ(int n, int A[]) {    // constructor as well as pre-processing routine
//     // speed up powers of 2 and logarithmic computations
//     memset(L2, 0, sizeof L2);
//     for (i = 0; i <= L2_N; i++) {
//       P2[i] = (1<<i);
//       L2[(1<<i)] = i;
//     }
//     L2[0] = L2[1] = 0;
//     for (i = 2; i < (1<<L2_N); i++)
//       if (L2[i] == 0)
//         L2[i] = L2[i-1];

//     // initialization
//     for (j = 0; j < n; j++) {
//       _A[j] = A[j];
//       SpT[0][j] = j;                             // RMQ of sub array [j..j]
//     }

//     // the two nested loops below have overall time complexity = O(n log n)
//     for (i = 1; (1<<i) <= n; i++)     // for each i s.t. 2^i <= n, O(log n)
//       for (j = 0; j+(1<<i)-1 < n; j++) {          // for each valid j, O(n)
//         x = SpT[i-1][j];                             // covers [j..j+2^i-1]
//         y = SpT[i-1][j+(1<<(i-1))];      // covers [j+(1<<(i-1))..j+(1<<i)]
//         SpT[i][j] = _A[x] <= _A[y] ? x : y;
//       }
//   }

//   int query(int i, int j) {
//     // cout << i << " " << j << endl;
//     k = L2[j-i+1];                                        // 2^k <= (j-i+1)
//     x = SpT[k][i];                                   // covers [i..i+2^k-1]
//     y = SpT[k][j-P2[k]+1];                           // covers [j-2^k+1..j]
//     // printf("%k = %d, i = %d, modj = %d, x = %d, y = %d\n", k, i, j-P2[k]+1, x, y);
//     return _A[x] <= _A[y] ? x : y;
//   }
// };

class RMQ {
private:
    int _A[MAXN], SpT[MAXN][L2_N];
public:
    RMQ(int n, int A[]) {
        for (int i = 0; i < n; i++) {
            _A[i] = A[i];
            SpT[i][0] = i;
        }

        for (int j = 1; (1 << j) <= n; j++) {
            for (int i = 0; i + (1 << j) - 1 < n; i++) {
                if (_A[SpT[i][j-1]] < _A[SpT[i + (1 << (j-1))][j-1]]) {
                    SpT[i][j] = SpT[i][j-1];
                } else {
                    SpT[i][j] = SpT[i + (1 << (j-1))][j-1];
                }
            }
        }
    }

    int query(int i, int j) {
        int k = (int)floor(log((double)j-i+1) / log(2.0));
        if (_A[SpT[i][k]] <= _A[SpT[j - (1 << k) + 1][k]]) {
            return SpT[i][k];
        } else {
            return SpT[j - (1 << k) + 1][k];
        }
    }
};


// Root at index 0
class LCA {
private:
    vector<vi> children;
    vi L, E, H;
    int idx;
    int arr[MAXN];
    RMQ sptable = RMQ(3, arr);

    void dfs(int cur, int depth) {
        H[cur] = idx;
        E[idx] = cur;
        L[idx++] = depth;
        for (auto &nxt : children[cur]) {
            dfs(nxt, depth+1);
            E[idx] = cur;                              // backtrack to current node
            L[idx++] = depth;
        }
    }

public:
    LCA(int n) {
        for (int i = 0; i < n; i++) {
            L.pb(-1);
            L.pb(-1);
            E.pb(-1);
            E.pb(-1);
            H.pb(-1);
            vi emp;
            children.pb(emp);
        }
        idx = 0;
    }

    void addChild(int parent, int child) {
        children[parent].pb(child);
    }

    // call this to start the LCA system
    void finishAddChildren() {
        dfs(0, 0);
        int n = L.size();
        int A[n];
        for (int i = 0; i < n; i++) {
            A[i] = L[i];
        }
        sptable = RMQ(n, A);
    }

    // l and r is inclusive
    int findLCA(int a, int b) {
        int l = H[a];
        int r = H[b];

        int left = min(l, r);
        int right = max(l, r);

        int rmq = sptable.query(left, right);
        return E[rmq];
    }

    int findDistance(int a, int b) {
        int lca = findLCA(a, b);
        a = H[a];
        lca = H[lca];
        b = H[b];
        return (L[a] - L[lca]) + (L[b] - L[lca]);
    }
};

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    LCA lca(N);

    vector<vi> AL;

    for (int i = 0; i < N; i++) {
        vi emp;
        AL.pb(emp);
    }

    for (int i = 0; i < N-1; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        AL[x].pb(y);
        AL[y].pb(x);
    }

    useti visited;
    qi bfs;

    bfs.push(0);

    while(bfs.size() > 0) {
        auto curr = bfs.front();
        bfs.pop();
        if (visited.find(curr) == visited.end()) {
            visited.insert(curr);
            for (auto x : AL[curr]) {
                if (visited.find(x) != visited.end()) {
                    continue;
                }
                bfs.push(x);
                lca.addChild(curr, x);
            }
        }
    }
    lca.finishAddChildren();
    // cout << lca.findLCA(4, 6) << endl;
    ll ttl = 0;

    for (int i = 0; i < N; i++) {
        int idx = i + 1;
        for (int j = 2; j <= N / idx; j++) {
            int idx2 = idx * j;
            // cout << idx << " to " << idx2 << " = " << lca.findDistance(idx-1, idx2-1) << endl;
            ttl += lca.findDistance(idx-1, idx2-1);
            ttl++;
        }
    }

    cout << ttl << endl;

    return 0;
}