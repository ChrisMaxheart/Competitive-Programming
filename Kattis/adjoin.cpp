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

pii furthest(vector<vi> AL, int fromNode) {
    vi dist;

    for (auto x: AL) {
        dist.pb(INF);
    }

    pqdijk dijk;
    dijk.push(mp(0, fromNode));
    while(dijk.size() > 0) {
        auto curr = dijk.top();
        dijk.pop();
        if (dist[curr.se] == INF) {
            dist[curr.se] = curr.fi;
            for (auto x: AL[curr.se]) {
                if (dist[x] == INF) {
                    dijk.push(mp(curr.fi+1, x));
                }
            }
        }
    }

    int idx = -1;
    int maxi = -1;

    for (int i = 0; i < AL.size(); i++) {
        if(dist[i] > maxi) {
            idx = i;
            maxi = dist[i];
        }
        dist[i] = INF;
    }
    return mp(idx, maxi);
}

int diameter(vector<vi> AL) {
    pii furthest1 = furthest(AL, 0);
    pii furthest2 = furthest(AL, furthest1.fi);
    return furthest2.se;
}

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

    int N, M;

    cin >> N >> M;

    vector<vi> AL;

    for (int i = 0; i < N; i++) {
        vi emp;
        AL.pb(emp);
    }

    UnionFind ufds(N);

    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        AL[x].pb(y);
        AL[y].pb(x);
        ufds.unionSet(x, y);
    }

    if (ufds.numDisjointSets() == 1) {
        cout << diameter(AL) << endl;
        return 0;
    } 

    vector<seti> lst;

    for (int i = 0; i < ufds.numDisjointSets(); i++) {
        seti emp;
        lst.pb(emp);
    }

    umapii idx;

    int ctr = 0;

    for (int i = 0; i < N; i++) {
        int dummy = ufds.findSet(i);
        if (idx.find(dummy) == idx.end()) {
            idx[dummy] = ctr;
            ctr++;
        }
        lst[idx[dummy]].insert(i);
    }

    vi dialst;

    for (auto x: lst) {
        umapii idx2;
        int ctr2 = 0;
        for (auto y: x) {
            if (idx2.find(y) == idx2.end()) {
                idx2[y] = ctr2;
                ctr2++;
            }
        }

        vector<vi> newAL;
        for (auto y: x) {
            newAL.pb(AL[y]);
        }

        for (int i = 0; i < newAL.size(); i++) {
            for (int j = 0; j < newAL[i].size(); j++) {
                newAL[i][j] = idx2[newAL[i][j]];
            }
        }
        // dialst.pb(diameter(newAL));
        dialst.pb(diameter(newAL));
        // dialst.pb(ceil(diameter(newAL) / 2));
    } 

    sort(dialst.begin(), dialst.end());

    while(dialst.size() > 1) {
        int left1 = dialst.back() / 2;
        int right1 = dialst.back() / 2;
        if (dialst.back() % 2) {
            left1++;
        }

        dialst.pop_back();

        int left2 = dialst.back() / 2;
        int right2 = dialst.back() / 2;
        if (dialst.back() % 2) {
            left2 ++;
        }
        dialst.pop_back();

        dialst.pb(max({left1+right1, left1+left2+1, left2+right2}));
    }

    cout << dialst[0] << endl;

    return 0;
}