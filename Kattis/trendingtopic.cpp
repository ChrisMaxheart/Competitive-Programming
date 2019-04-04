#include <bits/stdc++.h>

using namespace std;

// defines
  #define PI 3.14159265359
  #define INF 1E9
  #define Tloop int T; cin >> T; for(int count_ = 1; count_ < T+1; count_++)
  #define Nloop int N; cin >> N; for(int count__ = 0; count__ < N; count__++)
  #define printcaseg cout << "Case #" << count_ << ": "
  #define printcaseu cout << "Case " << count_ << ": "
  #define MOD (1E9 + 7)

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
    string word;
    int counter;
  };

// pq/set custom comparator, will get reversed
  class mycomp {
    public:
    bool operator() (int a, int b) {
      return a > b; 
    }
  };

// sort custom comparator
  bool customcompare(mystruct a, mystruct b) {
    if (a.counter == b.counter) {
      return a.word < b.word;
    }
    return a.counter > b.counter;
  }

int main ()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string words;

  deque<umapsi> daily;

  while (cin >> words) {
    if (words == "<text>") {
      if (daily.size() == 7) {
        daily.pop_front();
      }
      umapsi today;
      while(cin >> words, words != "</text>") {
        if (words.length() > 3) {
          today[words]++;
        }
      }
      daily.push_back(today);
    } else {
      int x;
      cin >> x >> words;
      umapsi compile;
      for (auto y : daily) {
        for (auto z : y) {
          compile[z.first] += z.second;
        }
      }
      vector<mystruct> myvect;
      for (auto y : compile) {
        mystruct newstruct;
        newstruct.word = y.first;
        newstruct.counter = y.second;
        myvect.push_back(newstruct);
      }
      sort(myvect.begin(), myvect.end(), customcompare);
      cout << "<top " << x << ">" << endl;
      int limit;
      if (myvect.size() > x) {
        for (int i = 0; i < x; i++) {
          auto y = myvect[i];
          cout << y.word << " " << y.counter << endl;
          if (i == (x-1)) {
            limit = y.counter;
          } 
        }
        for (int i = x; i < myvect.size(); i++) {
          auto y = myvect[i];
          if (y.counter == limit) {
            cout << y.word << " " << y.counter << endl;
          } else {
            break;
          }
        }
      } else {
        for (auto y : myvect) {
          cout << y.word << " " << y.counter << endl;
        }
      }
      cout << "</top>" << endl;
    }
  }

  return 0;
}