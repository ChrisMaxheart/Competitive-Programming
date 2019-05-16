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
#define SZ(S) S.size()
#define ALL(S) S.begin(), S.end()
template<typename T = int>
bool eulerianTour(const vector<vector<T>> &g, vi &tour) {
  int n = SZ(g);
  int edgeCount = 0;
  vi inDeg(n), outDeg(n);
  for (int i = 0; i < n; i++) {
    outDeg[i] = SZ(g[i]);
    for (auto &it : g[i]) {
      inDeg[it]++;
      edgeCount++;
    }
  }
  int out = -1, in = -1;
  for (int i = 0; i < n; i++) {
    if (inDeg[i] == outDeg[i] + 1) {
      if (out == -1) {
        out = i;
      } else {
        return false;
      }
    } else if (outDeg[i] == inDeg[i] + 1) {
      if (in == -1) {
        in = i;
      } else {
        return false;
      }
    } else if (outDeg[i] != inDeg[i]) {
      return false;
    }
  }
  // either zero or both
  if ((in != -1) ^ (out != -1)) {
    return false;
  }
  if (in == -1) {
    for (int i = 0; i < n; i++) {
      if (outDeg[i] != 0) {
        in = out = i;
        break;
      }
    }
    // empty graph?
    if (in == -1) {
      in = out = 0;
    }
  }
  tour.clear();
  stack<int> st;
  vi visit(n);
  vi ptr(n);
  st.push(in);
  while (!st.empty()) {
    int u = st.top();
    visit[u] = true;
    if (ptr[u] == SZ(g[u])) {
      tour.push_back(u);
      st.pop();
    } else {
      st.push(g[u][ptr[u]++]);
    }
  }
  reverse(ALL(tour));
  return SZ(tour) == edgeCount + 1;
}


int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    Tloop {
        map<pii, sets> idx;
        vector<vector<psi>> AL;
        for (int i = 0; i < 26; i++) {
            vector<psi> emp;
            AL.pb(emp);
        }
        Nloop {
            string x;
            cin >> x;
            int idx1 = x[0] - 'a';
            int idx2 = x[x.length() - 1] - 'a';
            idx[mp(idx1, idx2)].insert(x);
            AL[idx1].pb(mp(x,idx2));
        }
        for (int i = 0; i < AL.size(); i++) {
            sort(AL[i].begin(), AL[i].end());
        }

        vector<vi> newAL;
        for (auto x: AL) {
            vi emp;
            for (auto y: x) {
                emp.pb(y.se);
            }
            newAL.pb(emp);
        }
        vi ans;
        if (eulerianTour(newAL, ans)) {
            vs final;
            for (int i = 0; i < ans.size() - 1; i++) {
                int idx1 = ans[i];
                int idx2 = ans[i+1];

                string elem = *idx[mp(idx1, idx2)].begin();
                final.pb(elem);
                idx[mp(idx1, idx2)].erase(elem);
            }

            if (final.front().front() == final.back().back()) {
                vs finalans;
                for (int i = 0; i < final.size(); i++) {
                    string nani = "";
                    for (int j = i; j < final.size(); j++) {
                        if (j != i) {
                            nani += ".";
                        }
                        nani += final[j];
                    }

                    for (int j = 0; j < i; j++) {
                        nani += ".";
                        nani += final[j];
                    }
                    finalans.pb(nani);
                }
                sort(finalans.begin(), finalans.end());
                final = strsplit(finalans[0], '.');
            }

            assert(final[0] != final.back());

            for (int i = 0; i < final.size(); i++) {
                if (i!=0) {
                    cout << ".";
                }
                cout << final[i];
            }

        } else {
            cout << "***";
        }
        cout << endl;
    }

    return 0;
}