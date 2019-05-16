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
        typedef priority_queue<pair<int,pair<vector<int>, int>>, vector<pair<int,pair<vector<int>, int>>>, greater<pair<int,pair<vector<int>, int>>>> pqdijk2;
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

pii furthest(vector<vi> &AL, int fromNode) {
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
        if(dist[i] > maxi && dist[i] != INF) {
            idx = i;
            maxi = dist[i];
        }
        dist[i] = INF;
    }
    return mp(idx, maxi);
}

int diameter(vector<vi> &AL, int node = 0) {
    pii furthest1 = furthest(AL, node);
    pii furthest2 = furthest(AL, furthest1.fi);
    return furthest2.se;
}

vi getDiameterPath(vector<vi> &AL, int node = 0) {
    int furthestNode = furthest(AL, node).fi;
    // cout << node << " " << furthestNode << endl;

    vi dist;
    vAL lst;

    for (int i = 0; i < AL.size(); i++) {
        vi emp;
        lst.pb(emp);
        dist.pb(INF);
    }

    pqdijk2 dijk;
    vi initpath;
    initpath.pb(furthestNode);
    dijk.push(mp(0, mp(initpath, furthestNode)));
    while(dijk.size() > 0) {
        auto curr = dijk.top();
        dijk.pop();
        if (dist[curr.se.se] == INF) {
            dist[curr.se.se] = curr.fi;
            lst[curr.se.se] = curr.se.fi;
            for (auto x: AL[curr.se.se]) {
                if (dist[x] == INF) {
                    vi path = curr.se.fi;
                    path.pb(x);
                    dijk.push(mp(curr.fi+1, mp(path, x)));
                }
            }
        }
    }

    vi finalpath;
    int maxi = -1;

    bool debug = false;

    for(int i = 0; i < dist.size(); i++) {
        if (debug) {
            cout << "=====" << endl;
            cout << i << endl;
            cout << dist[i] << endl;
            for(auto x: lst[i]) {
                cout << x << " ";
            } cout << endl;
        }
        if (dist[i] > maxi && dist[i] != INF) {
            if (debug) {
                cout << "masuk" << endl;
            }
            maxi = dist[i];
            finalpath = lst[i];
        }
    }
    if (debug) {
        for (auto x : finalpath) {
            cout << x << " ";
        } cout << endl;
    }
    return finalpath;
}

void removeUndirectedEdge(vector<vi> &AL, int n1, int n2) {
    vi newlst;

    newlst.clear();
    for (auto x: AL[n1]) {
        if (x != n2) {
            newlst.pb(x);
        }
    }
    AL[n1] = newlst;

    newlst.clear();
    for (auto x: AL[n2]) {
        if (x != n1) {
            newlst.pb(x);
        }
    }
    AL[n2] = newlst;
}

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vAL AL;
    vi dist;
    vector<vi> lst;

    Nloop {
        vi emp;
        AL.pb(emp);
        lst.pb(emp);
        dist.pb(INF);
    }

    for (int i = 0; i < N-1; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        AL[x].pb(y);
        AL[y].pb(x);
    }

    vi finalpath = getDiameterPath(AL);

    // for (auto x: finalpath) {
    //     cout << x << " ";
    // } cout << endl;

    int idxcenter = finalpath.size() / 2;

    vector<pii> toremove, tojoin;


    for (int i = 0; i < finalpath.size()-1; i++) {
        int idx1 = i;
        int idx2 = i+1;
        toremove.eb(idx1, idx2);
    }

    // toremove = mp(9 , 0);
    // tojoin = mp(6 , 8);

    int idxmemo;
    int dia = INF;


    for (int i = 0; i < toremove.size(); i++) {
        toremove[i] = mp(finalpath[toremove[i].fi], finalpath[toremove[i].se]);

        removeUndirectedEdge(AL, toremove[i].fi, toremove[i].se);

        int d1 = diameter(AL, toremove[i].fi);
        int d2 = diameter(AL, toremove[i].se);

        int curr = max(max(d1, d2), 1 + int(ceil(double(max(d1,d2))/2.0) + ceil(double(min(d1,d2))/2.0)));
        // cout << toremove[i].fi << " " << toremove[i].se << endl;
        // cout << curr << endl;
        // cout << tojoin[i].fi << " " << tojoin[i].se << endl;
        // cout << "========" << endl;
        if (curr < dia) {
            dia = curr;
            idxmemo = i;
        }

        AL[toremove[i].fi].pb(toremove[i].se);
        AL[toremove[i].se].pb(toremove[i].fi);
    }

    int rm1 = toremove[idxmemo].fi;
    int rm2 = toremove[idxmemo].se;

    removeUndirectedEdge(AL, rm1, rm2);
    // vector<pii> tojoin;
    int idxmemo2;
    dia = INF;

    vi path1 = getDiameterPath(AL, rm1);
    vi path2 = getDiameterPath(AL, rm2);
    // cout << int(path1.size()) << " " << int(path2.size()) << " nani" << endl;
    tojoin.eb(path1[int(path1.size()) / 2], path2[int(path2.size()) / 2]);
    if (int(path1.size()) / 2 - 1 >= 0) {
        tojoin.eb(path1[int(path1.size()) / 2 - 1], path2[int(path2.size()) / 2]);
        // cout << "1 : ";
        // cout << int(path1.size()) / 2 - 1 << " " << int(path2.size()) / 2 << endl;
        if (int(path2.size()) / 2 - 1 >= 0) {
            tojoin.eb(path1[int(path1.size()) / 2 - 1], path2[int(path2.size()) / 2 - 1]);
        // cout << "2 : ";
        // cout << int(path1.size()) / 2 - 1 << " " << int(path2.size()) / 2 - 1 << endl;
        }
    }

    if (int(path2.size()) / 2 - 1 >= 0) {
        tojoin.eb(path1[int(path1.size()) / 2], path2[int(path2.size()) / 2 - 1]);
        // cout << "3 : ";
        // cout << int(path1.size()) / 2 << " " << int(path2.size()) / 2 - 1 << endl;
    }

    if (int(path1.size()) / 2 + 1 < int(path1.size())) {
        tojoin.eb(path1[int(path1.size()) / 2+ 1], path2[int(path2.size()) / 2]);
        // cout << "4 : ";
        // cout << int(path1.size()) / 2 + 1 << " " << int(path2.size()) / 2 << endl;
        if (int(path2.size()) / 2 + 1 < int(path2.size())) {
            tojoin.eb(path1[int(path1.size()) / 2 +1], path2[int(path2.size()) / 2+ 1]);
        // cout << "5 : ";
        // cout << int(path1.size()) / 2 + 1 << " " << int(path2.size()) / 2 +  1 << endl;
        }
    }

    if (int(path2.size()) / 2 + 1 < int(path2.size())) {
        tojoin.eb(path1[int(path1.size()) / 2], path2[int(path2.size()) / 2 +1]);
        // cout << "6 : ";
        // cout << int(path1.size()) / 2<< " " << int(path2.size()) / 2 +  1 << endl;
    }

    // cout << rm1 << " " << rm2 << endl;
    // for (auto x : path2) {
    //     cout << " ini isi path2 " << x << endl;
    // }
    // 
    // for (auto x: tojoin) {
    //     cout << " ini isi tojoin " << x.fi << " " << x.se << endl;
    // }

    for (int i = 0; i < tojoin.size(); i++) {
        int add1 = tojoin[i].fi;
        int add2 = tojoin[i].se;
        // cout << add1 << " " << add2 << endl;
        AL[add1].pb(add2);
        AL[add2].pb(add1);

        int curr = diameter(AL);
        if (dia > curr) {
            dia = curr;
            idxmemo2 = i;
        }

        removeUndirectedEdge(AL,add1, add2);
    }


    cout << dia << endl;
    cout << toremove[idxmemo].fi + 1 << " " << toremove[idxmemo].se + 1 << endl;
    cout << tojoin[idxmemo2].fi + 1 << " " << tojoin[idxmemo2].se + 1 << endl;
    return 0;
}