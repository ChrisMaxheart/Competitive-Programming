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

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<pii> lst;

    int maxix = -INF - 1;
    int maxiy = - INF -1;
    int minix = INF + 1;
    int miniy = INF + 1;

    Nloop {
        int x, y;
        cin >> x >> y;
        maxix = max(maxix, x);
        minix = min(minix, x);
        maxiy = max(maxiy, y);
        miniy = min(miniy, y);
        lst.eb(x, y);
    }

    sort(lst.begin(), lst.end());

    

    bool can = true;

    vector<pair<pii, pii>> rct;

    map<int, seti> temp;
    for (auto x : lst) {
        temp[x.fi].insert(x.se);
    }

    vector<seti> lst2;

    umapii idx;

    int ctr = 0;

    for (auto x : temp) {
        lst2.pb(x.se);
        idx[ctr] = x.fi;
        ctr++;
    }

    int l = 0;
    int r = lst2.size() - 1;

    while(l < r) {
        seti uj1 = lst2[l];
        seti uj2 = lst2[r];
        bool kcil = true;
        while(true) {
            if (uj1.size() == 0) {
                l++;
                break;
            } else if (uj2.size() == 0) {
                r--;
                break;
            }

            auto prt = uj1.begin();
            auto trk = uj1.end();
            --trk;
            auto prt2 = uj2.begin();
            auto trk2 = uj2.end();
            --trk2;

            int pert1 = *prt;
            int trak1 = *trk;
            int pert2 = *prt2;
            int trak2 = *trk2;

            if (uj1.size() == 1 && uj2.size() == 1) {
                int xmin = min(idx[l], idx[r]);
                int xmax = max(idx[l], idx[r]);
                int ymin = min(pert1, pert2);
                int ymax = max(pert1, pert2);
                rct.eb(mp(xmin, xmax), mp(ymin, ymax));
                l++;
                r--;
                break;
            } else if (uj1.size() == 1) {
                if (pert1 < pert2) {
                    int xmin = min(idx[l], idx[r]);
                    int xmax = max(idx[l], idx[r]);
                    int ymin = min(pert1, trak2);
                    int ymax = max(pert1, trak2);
                    uj2.erase(trak2);
                    rct.eb(mp(xmin, xmax), mp(ymin, ymax));
                    l++;
                    break;
                } else if (pert1 > trak2) {
                    int xmin = min(idx[l], idx[r]);
                    int xmax = max(idx[l], idx[r]);
                    int ymin = min(pert1, pert2);
                    int ymax = max(pert1, pert2);
                    rct.eb(mp(xmin, xmax), mp(ymin, ymax));
                    uj2.erase(pert2);
                    l++;
                    break;
                } else {
                    can = false;
                    break;
                }
            }  else if (uj2.size() == 1) {
                if (pert2 < pert1) {
                    int xmin = min(idx[l], idx[r]);
                    int xmax = max(idx[l], idx[r]);
                    int ymin = min(trak1, pert2);
                    int ymax = max(trak1, pert2);
                    uj1.erase(trak1);
                    rct.eb(mp(xmin, xmax), mp(ymin, ymax));
                    r--;
                    break;
                } else if (pert1 > trak2) {
                    int xmin = min(idx[l], idx[r]);
                    int xmax = max(idx[l], idx[r]);
                    int ymin = min(pert1, pert2);
                    int ymax = max(pert1, pert2);
                    rct.eb(mp(xmin, xmax), mp(ymin, ymax));
                    uj1.erase(pert1);
                    r--;
                    break;
                } else {
                    can = false;
                    break;
                }
            } else {
                if (kcil) {
                    int xmin = min(idx[l], idx[r]);
                    int xmax = max(idx[l], idx[r]);
                    int ymin = min(pert1, trak2);
                    int ymax = max(pert1, trak2);
                    uj1.erase(pert1);
                    uj2.erase(trak2);
                    rct.eb(mp(xmin, xmax), mp(ymin, ymax));
                } else {
                    int xmin = min(idx[l], idx[r]);
                    int xmax = max(idx[l], idx[r]);
                    int ymin = min(trak1, pert2);
                    int ymax = max(trak1, pert2);
                    uj1.erase(trak1);
                    uj2.erase(pert2);
                    rct.eb(mp(xmin, xmax), mp(ymin, ymax));
                }
            }
            kcil = !kcil;
        }
        if (!can) {
            break;
        }
    }

    // vll luas;    

    for (auto rc: rct) {
        pii xlst = rc.fi;
        pii ylst = rc.se;
        int xmin = xlst.fi;
        int xmax = xlst.se;
        int ymin = ylst.fi;
        int ymax = ylst.se;
        // cout << xmin << " " << xmax << " " << ymin << " " << ymax << endl;
        if (ymin < miniy || ymax > maxiy) {
            can = false;
        }
        if (xmin == xmax || ymin == ymax) {
            can = false;
        }
        minix = max(minix, xmin);
        maxix = min(maxix, xmax);
        miniy = max(miniy, ymin);
        maxiy = min(maxiy, ymax);
        // luas.pb((ll(xmax)-ll(xmin)) * (ll(ymax)-ll(ymin)));
    }

    // for (int i = 0; i < luas.size() - 1; i++) {
    //     if (luas[i] < luas[i+1]) {
    //         can = false;
    //     }
    // }

    if (can) {
        cout << "YA" << endl;
    } else {
        cout << "TIDAK" << endl;
    }


    return 0;
}