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

template<typename F = int>
struct DinicMaxFlow {
    struct Edge {
        int to, rev, from;
        F flow, cap;
    };

    const F INF_FLOW = numeric_limits<F>::max() / 2;
    const int INF_DIST = 1e9;

    int source, sink;
    vector<vector<Edge>> graph;
    vector<int> dist, ptr;

    DinicMaxFlow(int N) : graph(N), dist(N), ptr(N) {}

    void addEdge(int from, int to, F cap) {
      if (from == to) {
        return;
      }
      Edge e1 { to, (graph[to].size()), from, 0, cap };
      Edge e2 { from, (graph[from].size()), to, 0, 0 };
      graph[from].push_back(e1);
      graph[to].push_back(e2);
    }

    bool buildLevelGraph() {
      fill(begin(dist), end(dist), INF_DIST);
      queue<int> q;
      dist[source] = 0;
      q.push(source);
      while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (const auto &e : graph[u]) {
          if (e.flow < e.cap && dist[e.to] > dist[u] + 1) {
            dist[e.to] = dist[u] + 1;
            q.push(e.to);
          }
        }
      }
      return dist[sink] != INF_DIST;
    }

    F dfs(int u, F bottleneck) {
      if (u == sink || bottleneck == 0) {
        return bottleneck;
      }
      for (int &i = ptr[u]; i < (graph[u].size()); i++) {
        auto &e = graph[u][i];
        auto &b = graph[e.to][e.rev];
        if (dist[e.to] != dist[u] + 1 || e.flow >= e.cap) {
          continue;
        }
        F pushed = dfs(e.to, min(e.cap - e.flow, bottleneck));
        if (pushed > 0) {
          e.flow += pushed;
          b.flow -= pushed;
          return pushed;
        }
      }
      return 0;
    }

    F calcMaxFlow(const int source, const int sink) {
      this->source = source;
      this->sink = sink;
      F mf = 0;
      while (buildLevelGraph()) {
        fill(begin(ptr), end(ptr), 0);
        F pushed;
        while ((pushed = dfs(source, INF_FLOW))) {
          mf += pushed;
        }
      }
      return mf;
    }
};

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, q, s;
    int ttl = 0;
    cin >> n >> q >> s;
    vi pasangans, capaqueue;
    vector<vi> datagen;
    vi lim;
    for (int i = 0; i < s; i++) {
        int x;
        cin >> x;
        x--;
        pasangans.pb(x);
    }
    for (int i = 0; i < q; i++) {
        int x;
        cin >> x;
        capaqueue.pb(x);
    }


    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        lim.pb(x);
        vi emp;
        for (int j = 0; j < s; j++) {
            cin >> x;
            emp.pb(x);
            ttl += x;
        }
        datagen.pb(emp);
    }

    DinicMaxFlow<int> mf(s + 2 * q * n + n + 2);
    int src  = s + 2 * q * n + n;
    int snk = src + 1;

    // from source to sensor
    for (int i = 0; i < s; i++) {
        mf.addEdge(src, i, INFflow);
    }

    // from sensor to queue
    for (int i = 0; i < s; i++) {
        int trget = pasangans[i];
        for (int j = 0; j < n; j++) {
            int qtar = s + (trget * n + j);
            mf.addEdge(i, qtar, datagen[j][i]);
        }
    }

    // from queue to vertex capacity
    for (int i = 0; i < q; i++) {
        for (int j = 0; j < n; j++) {
            int qawal = s + (i * n + j);
            int qakhir = s + (q * n) + (i * n + j);
            mf.addEdge(qawal, qakhir, capaqueue[i]);
        }
    }

    // from vertex capa of queue to the next queue
    for (int i = 0; i < q; i++) {
        for (int j = 0; j < n-1; j++) {
            int qawal = s + (q * n) + (i * n + j);
            int qakhir = s + (i * n + (j+1));
            mf.addEdge(qawal, qakhir, INFflow);
        }
    }

    // from vertex capa of queue to earth
    for (int i = 0; i < q; i++) {
        for (int j = 0; j < n; j++) {
            int qawal = s + (q * n) + (i * n + j);
            int bumi = s + (2 * q * n) + j;
            mf.addEdge(qawal, bumi, INFflow);
        }
    }

    // from earth to sink
    for (int i = 0; i < n; i++) {
        int bumi = s + (2 * q * n) + i;
        mf.addEdge(bumi, snk, lim[i]);
    }

    bool can = true;

    int flw = mf.calcMaxFlow(src, snk);

    if (flw < ttl) {
        can = false;
    }

    if (can) {
        cout << "possible" << endl;
    } else {
        cout << "impossible" << endl;
    }

    return 0;
}