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

#define LSOne(S) ((S)&(-S))
class FenwickTree {
private:
    vi ft;
    int n;

public:
    FenwickTree(int _n) : n(_n) {
        ft.assign(n+1, 0);
    }
    FenwickTree(const vector<int>& f) : n(f.size()-1) {
        ft.assign(n+1, 0);
        for(int i = 1; i <= n; i++) {
            ft[i] += f[i];
            if(i+LSOne(i) <= n) {
                ft[i+LSOne(i)] += ft[i];
            }
        }
    }
    int rsq(int j) {
        int sum = 0;
        for (; j; j-= LSOne(j)) {
            sum += ft[j];
        }
        return sum;
    }
    int rsq(int i, int j) {
        return rsq(j) - rsq(i-1);
    }
    void update(int i, int v) {
        for (; i <= n; i += LSOne(i)) {
            ft[i] += v;
        }
    }
};

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll N;
    cin >> N;

    vi alst, blst, clst;

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        alst.pb(x);
    }

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        blst.pb(x);
    }

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        clst.pb(x);
    }

    umapii mapa, mapb;

    for (int i = 0; i < N; i++) {
        mapa[alst[i]] = i+1;
        mapb[blst[i]] = i+1;
    }

    ll inversb_a = 0;
    ll inversc_a = 0;
    ll inversc_b = 0;

    FenwickTree ftb_a(N+5);
    FenwickTree ftc_a(N+5);
    FenwickTree ftc_b(N+5);

    for (auto x: blst) {
        int bila = mapa[x];
        inversb_a += ll(ftb_a.rsq(bila));
        ftb_a.update(bila, 1);
    }

    for (auto x : clst) {
        int bila = mapa[x];
        int bilb = mapb[x];

        inversc_a += ll(ftc_a.rsq(bila));
        ftc_a.update(bila, 1);

        inversc_b += ll(ftc_b.rsq(bilb));
        ftc_b.update(bilb, 1);
    }

    ll ttl = N * (N-1);
    ttl /= 2;

    ll semua = inversb_a + inversc_b + inversc_a;
    semua -= ttl;
    semua /= 2;

    cout << semua << endl;

    return 0;
}