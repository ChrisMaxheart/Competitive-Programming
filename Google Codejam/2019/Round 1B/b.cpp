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

    umapllll memo;
    memo[5] = pow(2, 5);
    memo[6] = pow(2, 6);
    memo[7] = pow(2, 7);
    memo[8] = pow(2, 8);
    memo[9] = pow(2, 9);
    memo[10] = pow(2, 10);
    memo[11] = pow(2, 11);
    memo[12] = pow(2, 12);
    memo[13] = pow(2, 13);
    memo[14] = pow(2, 14);
    memo[15] = pow(2, 15);
    memo[16] = pow(2, 16);
    memo[18] = pow(2, 18);
    memo[20] = pow(2, 20);
    memo[25] = pow(2, 25);
    memo[28] = pow(2, 28);
    memo[30] = pow(2, 30);
    memo[33] = pow(2, 33);
    memo[37] = pow(2, 37);
    memo[40] = pow(2, 40);
    memo[49] = pow(2, 49);
    memo[50] = pow(2, 50);
    memo[56] = pow(2, 56);
    bool xx = true;
    Tloop {
        if (xx) {
            int yy;
            cin >> yy;
            xx = false;
        }
        ll h1, h2;

        cout << 200 << endl;
        cout << flush;
        cin >> h1;

        ll d = h1 / memo[50];
        ll e = (h1 % memo[50]) / memo[40];
        ll f = (h1 % memo[40]) / memo[33];

        cout << 56 << endl;
        cout << flush;
        cin >> h2;
        h2 -= d * memo[14];
        // cerr << h2 << " ";
        h2 -= e * memo[11];
        // cerr << h2 << " ";
        h2 -= f * memo[9];
        // cerr << h2 << " ";
        ll a = h2 / memo[56];
        ll b = (h2 % memo[56]) / memo[28];
        ll c = (h2 % memo[28]) / memo[18];
        cout << a << " " << b << " " << c << " " << d << " " << e << " " << f << endl;
        cout << flush;
        int hasil;
        cin >> hasil;
        cerr << hasil << " ";
        if (hasil == 1) {
            continue;
        } else {
            return 0;
        }
    }
    return 0;
}