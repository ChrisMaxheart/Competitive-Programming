#include <bits/stdc++.h>

using namespace std;

// defines
  #define PI 3.14159265359
  #define INF 1E9
  #define Tloop int T; cin >> T; for(int i = 1; i < T+1; i++)
  #define Nloop int N; cin >> N; for(int j = 0; j < N; j++)
  #define printcaseg cout << "Case #" << i << ": "
  #define printcaseu cout << "Case " << i << ": "

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

  };

// pq/set custom comparator, will get reversed
  class mycomp {
    public:
    bool operator() (int a, int b) {
      return a > b; 
    }
  };

// sort custom comparator
  bool customcompare(int a, int b) {
    return a > b;
  }

bool checkprincelose(vi prince, vi princess) {
  int win = 0;
  for (int i = 0; i <= 2; i++) {
    if (prince[i]>princess[i]) {
      win++;
    }
  }
  if (win >= 2) {
    return false;
  } else {
    return true;
  }
}

int main ()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int A, B, C, X, Y;
  // seti deck;

  while (cin >> A >> B >> C >> X >> Y, A || B || C || X || Y) {
    seti deck;
    deck.insert(A);
    deck.insert(B);
    deck.insert(C);
    deck.insert(X);
    deck.insert(Y);
    vi princess;
    vi prince;
    princess.push_back(A);
    princess.push_back(B);
    princess.push_back(C);
    prince.push_back(X);
    prince.push_back(Y);
    prince.push_back(0);
    // ini belom kelar, cek lagi besok
    // 
    for (int seed = 1; seed <= 52; seed++) {
      if (deck.find(seed) == deck.end()) {
        prince[2] = seed;
        bool princewin = true;
        sort(princess.begin(), princess.end());
        if (checkprincelose(prince, princess)) {
          // cout << "yak pangeran kalah" << endl;
          princewin = false;
        }
        while(next_permutation(princess.begin(), princess.end())) {
          // cout << princess[0] << " " << princess[1] << " " << princess[2] << endl;
          // cout << prince[0] << " " << prince[1] << " " << prince[2] << endl;
          if (checkprincelose(prince, princess)) {
            // cout << "yak pangeran kalah" << endl;
            princewin = false;
          }
        }
        if (princewin) {
          cout << seed << endl;
          break;
        }
      }
      if(seed == 52) {
        cout << -1 << endl;
      }
    }
  }

  return 0;
}