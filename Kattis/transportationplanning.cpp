#include <bits/stdc++.h>

using namespace std;

// to minimize
    // defines
        const double PI = acos(-1);
        #define INF 1E13
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
        typedef vector<long double> vd;
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
const long double prec = .000001;
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

    int N;
    while(cin >> N, N) {
        vd xlst, ylst;
        for (int i = 0; i < N; i++) {
            long double x, y;
            cin >> x >> y;
            xlst.pb(x);
            ylst.pb(y);
        }
        vd AM[110];
        vd dist[110];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                AM[i].pb(INF);
                dist[i].pb(INF);
            }
        }

        for (int i = 0; i < N; i++) {
            AM[i][i] = 0.0;
            dist[i][i] = 0.0;
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                dist[i][j] = sqrt(pow(xlst[i]-xlst[j], 2) + pow(ylst[i]-ylst[j], 2));
//                dist[j][i] = dist[i][j];
            }
        }

        int M;
        cin >> M;
        for (int i = 0; i < M; i++) {
            int n1, n2;
            cin >> n1 >> n2;
            AM[n1][n2] = dist[n1][n2];
            AM[n2][n1] = AM[n1][n2];
        }

        for (int k = 0; k < N; k++) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    AM[i][j] = min(AM[i][j], AM[i][k] + AM[k][j]);
                    AM[j][i] = AM[i][j];
                }
            }
        }

        long double ttlawal = 0.0;
        for (int i = 0; i < N; i++) {
            for (int j = i; j < N; j++) {
                ttlawal += AM[i][j];
            }
        }


        long double ttlbest = INF;
        int node1 = -1;
        int node2 = -1;
        for (int n1 = 0; n1 < N; n1++) {
            for (int n2 = 0; n2 < N; n2++) {
                vd newAM[110];

                for (auto x = 0; x < N; x++) {
                    for (auto y : AM[x]) {
                        newAM[x].pb(y);
                    }
                }

                newAM[n1][n2] = dist[n1][n2];
                newAM[n2][n1] = dist[n1][n2];

                for (int i = 0; i < N; i++) {
                    for (int j = 0; j < N; j++) {
                        newAM[i][j] = min(newAM[i][j], newAM[i][n1] + newAM[n1][n2] + newAM[n2][j]);
                        newAM[i][j] = min(newAM[i][j], newAM[i][n2] + newAM[n2][n1] + newAM[n1][j]);
                    }
                }

                long double curr = 0.0;
                for (int i = 0; i < N; i++) {
                    for (int j = i; j < N; j++) {
                        curr += newAM[i][j];
                    }
                }

                if (ttlbest-curr > prec) {
                    ttlbest = curr;
                    node1 = n1;
                    node2 = n2;
                }

            }
        }

        cout << fixed << setprecision(8);

        if (abs(ttlbest-ttlawal) < prec) {
            cout << "no addition reduces " << ttlbest << endl;
        } else {
            cout << "adding " << node1 << " " << node2 << " reduces " << ttlawal << " to " << ttlbest << endl;
        }
    }

    return 0;
}