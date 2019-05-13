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

    int T, F;
    cin >> T >> F;
    for(int count_ = 1; count_ < T+1; count_++) {
        bool testt = count_ == 40;
        // cerr << T;
        // return 0;
        int re = 0;
        vi lst;
        for (int i = 0; i < 120; i++) {
            lst.pb(0);
        }

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 119; j++) {
                if (i == 3 && j == 117) {
                    break;
                }
                int bil = 5 * j + i + 1;
                cout << bil << endl;
                cout << flush;

                string x;
                cin >> x;
                // if (count_ == 3) {
                //     cerr << re << " "; 
                // }
                // cerr << x << endl;
                re++;
                lst[j] += pow(10, (3-i)) * (x[0] - 'A');
                // if (lst[j] == 1043 && testt) {
                //     cerr << "<< "<< x << endl;
                // }
            }
        }
        // if (count_ == 3) {
        //     return 0;
        // }
        // return 0;

        vi ans;
        // cerr << "test ";

        for (int i = 0; i < 3; i++) {
            vi freq;

            for (int j = 0; j < 5; j++) {
                freq.pb(0);
                // cerr << 0 << " ";
            }
            // cerr << endl;
            for (int j = 0; j < 119; j++) {
                int mult = pow(10, 3-i);
                int bil = (lst[j] / mult) % 10;
                // cerr << lst[j] << " " << bil << " dan freq sebelum " << freq[bil] << endl;
                freq[bil]++;
            }

            // cerr << "masukike" << i << " ";
            for (int j = 0; j < 5; j++) {
                // cerr << "masukjke" << j << " " << freq[j] << " ";
                if (freq[j] == 23) {
                    // cerr << j << " ";
                    // return 0;
                    ans.pb(j);
                    // cerr << j << " ";
                    lst[119] += pow(10, (3- i)) * j;
                    break;
                }
            }
        }
        vi freq;

        for (int j = 0; j < 5; j++) {
            freq.pb(0);
        }

        for (int j = 0; j < 117; j++) {
            int mult = pow(10, 0);
            int bil = (lst[j] / mult) % 10;
            freq[bil]++;
        }

        useti pos;
        for (int j = 0; j < 5; j++) {
            if (freq[j] < 24) {
                pos.insert(j);
            }
        }
        // cerr << endl << pos.size() << endl;

        if (pos.size() == 1) {
            for (auto x : pos) {
                ans.pb(x);
            }
        } else {
            vi dum;
            for (auto x: pos) {
                bool found = false;
                for (auto y: ans) {
                    if (x == y) {
                        dum.pb(x);
                    }
                }
            }
            for (auto x : dum) {
                pos.erase(x);
            }

            // cerr << endl << pos.size() << endl;

            if (pos.size() == 1) {
                for (auto x : pos) {
                    ans.pb(x);
                }
            // return 0;
            } else {
                if (testt) {
                    for (auto x : pos) {
                        cerr << x << endl;
                    }
                    cerr << lst[117] << " " << lst[118] << " " << lst[119] << endl;
                }
                // if (testt) {
                //     cerr << lst[117] << " " << lst[118] << " " << lst[119] << endl;
                // }
                if (lst[118] == lst[119]) {
                    int temp = lst[118];
                    lst[118] = lst[117];
                    lst[117] = temp;
                    cout << 594 << endl;
                    cout << flush;
                } else {
                    cout << 589 << endl;
                    cout << flush;
                }
                re++;
                // cerr << re << " ";
                string x;
                cin >> x;
                if (testt) cerr << x << endl;
                // re++;
                int dumd = x[0]-'A';
                lst[117] += pow(10, 0) * (dumd);
                if(testt) cerr << freq[dumd] << endl;
                freq[dumd]++;
                if (freq[dumd] == 24) {
                    pos.erase(dumd);
                }


                if (pos.size() == 1) {
                    for (auto xx : pos) {
                        ans.pb(xx);
                    }
                } else {
                    for (auto xx: pos) {
                        int bil = lst[118];
                        bil += xx;
                        int can = 1;
                        mapii dummy;
                        for (int j = 0; j < 118; j++) {
                            // if (count_)
                            // cerr << lst[j] << endl;
                            if (testt)
                                dummy[lst[j]]++;
                            if (lst[j] == bil) {
                                can--;
                            }
                        }
                        if (testt){
                            // cerr << dummy.size() << endl;
                            for (auto x: dummy) {
                                cerr << x.fi << " " << x.se << endl;
                            }
                        }

                        bil -= xx;
                        bil /= 10;
                        while (bil > 0) {
                            if (bil % 10 == xx) {
                                can = 0;
                            }
                            bil /= 10;
                        }
                        if (testt) {
                            cerr << xx << " " << can << endl;
                        }
                        if (can == 0) {
                            ans.pb(xx);
                        }
                    }
                }
            }
        }
        // cerr << ans.size() << endl;
        // return 0;
        for (int i = 0; i < 5; i++) {
            bool can = true;
            for (auto x : ans) {
                if (i == x) {
                    can = false;
                }
            }
            if (can) {
                // cerr << i << endl;
                ans.pb(i);
            }
        }
        string fin = "";
        for (auto x : ans) {
            fin += (x+'A');
        }
        // cerr << fin << endl;
        // return 0;
        cout << fin << endl;
        cout << flush;
        string x;
        cin >> x;
        cerr << fin << " " << count_ << " " << x << endl;
        if (x != "Y") {
            return 0;
        }
        // if (count_ == 10) {
        //     return 0;
        // }
        // return 0;
    }

    return 0;
}