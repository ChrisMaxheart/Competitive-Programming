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

    int N, Q;
    cin >> N >> Q;
    
    FenwickTree ft1(N+2);
    FenwickTree ft2(N+2);
    FenwickTree ft3(N+2);
    FenwickTree ft4(N+2);
    FenwickTree ft5(N+2);
    FenwickTree ft6(N+2);
    
    int val1, val2, val3, val4, val5, val6;
    cin >> val1 >> val2 >> val3 >> val4 >> val5 >> val6;
    
    string x;
    cin >> x;
    for (int i = 0; i < x.length(); i++) {
        int idx = i + 1;
        if (x[i] == '1') {
            ft1.update(idx, 1);
        } else if (x[i] == '2') {
            ft2.update(idx, 1);
        } else if (x[i] == '3') {
            ft3.update(idx, 1);
        } else if (x[i] == '4') {
            ft4.update(idx, 1);
        } else if (x[i] == '5') {
            ft5.update(idx, 1);
        } else if (x[i] == '6') {
            ft6.update(idx, 1);
        }
    }
    
    for (int i = 0; i < Q; i++) {
        int com;
        cin >> com;
        int xx, y;
        cin >> xx >> y;
        if (com == 1) {
            ft1.update(xx, -ft1.rsq(xx,xx));
            ft2.update(xx, -ft2.rsq(xx,xx));
            ft3.update(xx, -ft3.rsq(xx,xx));
            ft4.update(xx, -ft4.rsq(xx,xx));
            ft5.update(xx, -ft5.rsq(xx,xx));
            ft6.update(xx, -ft6.rsq(xx,xx));
            
            if (y == 1) {
                ft1.update(xx, 1);
            } else if (y == 2) {
                ft2.update(xx, 1);
            } else if (y == 3) {
                ft3.update(xx, 1);
            } else if (y == 4) {
                ft4.update(xx, 1);
            } else if (y == 5) {
                ft5.update(xx, 1);
            } else if (y == 6) {
                ft6.update(xx, 1);
            }
        } else if (com == 2) {
            if (xx == 1) {
                val1 = y;
            } else if (xx == 2) {
                val2 = y;
            } else if (xx == 3) {
                val3 = y;
            } else if (xx == 4) {
                val4 = y;
            } else if (xx == 5) {
                val5 = y;
            } else if (xx == 6) {
                val6 = y;
            }
        } else {
            ll ttl = 0;
            ttl += ll(val1) * ll(ft1.rsq(xx, y));
            ttl += ll(val2) * ll(ft2.rsq(xx, y));
            ttl += ll(val3) * ll(ft3.rsq(xx, y));
            ttl += ll(val4) * ll(ft4.rsq(xx, y));
            ttl += ll(val5) * ll(ft5.rsq(xx, y));
            ttl += ll(val6) * ll(ft6.rsq(xx, y));
            cout << ttl << endl;
        }
    }

    return 0;
}