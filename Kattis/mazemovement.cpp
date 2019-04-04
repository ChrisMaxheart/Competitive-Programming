#include <bits/stdc++.h>

using namespace std;

// to minimize
    // defines
        const double PI = acos(-1);
        #define INF 1E15
        #define INFflow 1E14
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

ll gcd(ll a, ll b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}
template<typename F = ll>
struct DinicMaxFlow {
    struct Edge {
        ll to, rev, from;
        F flow, cap;
    };

    const F INF_FLOW = numeric_limits<F>::max() / 2;
    const ll INF_DIST = 1e15;

    ll source, sink;
    vector<vector<Edge>> graph;
    vector<ll> dist, ptr;

    DinicMaxFlow(ll N) : graph(N), dist(N), ptr(N) {}

    void addEdge(ll from, ll to, F cap) {
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
      queue<ll> q;
      dist[source] = 0;
      q.push(source);
      while (!q.empty()) {
        ll u = q.front();
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

    F dfs(ll u, F bottleneck) {
      if (u == sink || bottleneck == 0) {
        return bottleneck;
      }
      for (ll &i = ptr[u]; i < (graph[u].size()); i++) {
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

    F calcMaxFlow(const ll source, const ll sink) {
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

    umapii idx;

    int N;
    cin >> N;
    ll memomin, memomax;
    ll mini = INF;
    ll maxi = -1;

    for (ll i = 0; i < N; i++) {
        ll x;
        cin >> x;
        if (x < mini) {
            mini = x;
            memomin = i;
        }
        if (x > maxi) {
            maxi = x;
            memomax = i;
        }
        idx[i] = x;
    }

    DinicMaxFlow<ll> mf(N+2);
    ll src = N;
    ll snk = N+1;
    mf.addEdge(src, memomin, INFflow);
    mf.addEdge(memomax, snk, INFflow);

    for (ll i = 0; i < N; i++) {
        for (ll j = i+1; j < N; j++) {
            ll bili = idx[i];
            ll bilj = idx[j];
            ll gecede = gcd(bili, bilj);
            if (gecede > 1) {
                mf.addEdge(i, j, gecede);
                mf.addEdge(j, i, gecede);
            }
        }
    }
    cout << mf.calcMaxFlow(src, snk) << endl;

    return 0;
}