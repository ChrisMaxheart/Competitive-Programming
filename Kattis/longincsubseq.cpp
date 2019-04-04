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

    vector<int> lis, idx, graf;


int main ()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;

  while(cin >> N) {

    for (int i = 0; i < N; i++) {
      graf.pb(-1);
    }

    
    for (int i = 0; i < N; i++) {
      int x;
      cin >> x;
      if(i == 0) {
        lis.pb(x);
        idx.pb(i);
      } else {

        // 2 special case kalo dia minimum or maximum
        if (lis[lis.size()-1] < x) {
          graf[i] = idx[lis.size()-1];
          lis.pb(x);
          idx.pb(i);
        } else if (lis[0] > x) {
          lis[0] = x;
          idx[0] = i;
        } else {

          // binary search
          int left = 0;
          int right = lis.size()-1;
          int mid = (left + right)/2;
          bool can = true;
          while(left <= right) {
            mid = (left+right)/2;
            if (lis[mid] == x) {
              can = false;
              break;
            } else if (lis[mid] < x) {
              left = mid + 1;
            } else {
              right = mid - 1;
            }
          }
          if (!can) {
            continue;
          }

          if (lis[mid] < x) {
            mid++;
          }
          lis[mid] = x;
          idx[mid] = i;
          // graf[idx[mid+1]] = i;
          int temp = idx[mid-1];
          graf[i] = temp;
        }
      }
    }

    // for (auto x : lis) {
    //   cout << x << " ";
    // } cout << endl;

    // for (auto x : idx) {
    //   cout << x << " ";
    // } cout << endl;

    // for (auto x : graf) {
    //   cout << x << " ";
    // } cout << endl;

    int curr = idx[lis.size()-1];

    cout << lis.size() << endl;

    si final;

    final.push(curr);

    while(graf[curr] != -1 && final.size() < N) {
      curr = graf[curr];
      final.push(curr);
    }

    while(final.size() > 0) {
      cout << final.top() << " ";
      final.pop();
    } cout << endl;

    lis.clear();
    graf.clear();
    idx.clear();
  }




  return 0;
}