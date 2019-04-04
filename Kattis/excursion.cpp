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

    // pq/set custom comparator, will get reversed
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

    ll counter0 = 0;
    ll counter1 = 0;
    ll counter2 = 0;

    vi lst0, lst1, lst2;

    ll curr0 = 0;
    ll curr1 = 0;
    ll curr2 = 0;

    string x;
    cin >> x;

    for (int i = 0; i < x.length(); i++) {
        if (x[i] == '0') {
            counter0++;
            lst0.pb(i);
        } else if (x[i] == '1') {
            counter1++;
            lst1.pb(i);
        } else {
            counter2++;
            lst2.pb(i);
        }
    }

    ll ttl = 0;
    curr1 += counter0;
    curr2 += counter0;
    curr2 += counter1;

    FenwickTree ft(x.length());

    int mv = 0;

    for (auto x : lst0) {
        ttl += abs(curr0 - x - ft.rsq(x+1) - mv);
        mv++;
//        cout << ttl << endl;
        curr0++;
        ft.update(x+1, -1);
    }

    for (auto x : lst1) {
        ttl += abs(curr1 - x - ft.rsq(x+1) - mv);
        mv++;
        curr1++;
        ft.update(x+1, -1);
    }

    for (auto x : lst2) {
        ttl += abs(curr2 - x - ft.rsq(x+1) - mv);
        mv++;
        curr2++;
        ft.update(x+1, -1);
    }

    cout << ttl << endl;

    return 0;
}