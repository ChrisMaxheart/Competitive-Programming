#include <bits/stdc++.h>

using namespace std;

// defines
  #define PI 3.14159265359
  #define INF 1E9
  #define Tloop int T; cin >> T; for(int count_ = 1; count_ < T+1; count_++)
  #define Nloop int N; cin >> N; for(int count__ = 0; count__ < N; count__++)
  #define printcaseg cout << "Case #" << count_ << ": "
  #define printcaseu cout << "Case " << count_ << ": "

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

int main ()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int all1[35];
  int all0[35];
  int real[35];



  string x;
  int y, z;
  int N;
  while(cin >> N, N) {
    for (int i = 0; i < 34; i++) {
      all1[i] = 1;
      all0[i] = 0;
      real[i] = 2;
    }
    for (int i = 0; i < N; i++) {
      cin >> x;
      if (x == "CLEAR" || x == "SET") {
        cin >> y;
      } else {
        cin >> y >> z;
      }

      if (x == "CLEAR") {
        all1[y] = 0;
        all0[y] = 0;
        real[y] = 0; 
      } else if (x == "SET") {
        all1[y] = 1;
        all0[y] = 1;
        real[y] = 1;
      } else if (x == "OR") {
        int dum1, dum2;

        dum1 = real[y];
        dum2 = real[z];

        int res1, res2, res3, res4;

        if (dum1 == 2 && dum2 == 2) {
          res1 = all0[y] | all0[z];
          res2 = all0[y] | all1[z];
          res3 = all1[y] | all0[z];
          res4 = all1[y] | all1[z];
          if (res1 == res2 && res1 == res3 && res1 == res4) {
            real[y] = res1;
            all0[y] = res1;
            all1[y] = res1;
          } else {
            real[y] = 2;
            all1[y] = 1;
            all0[y] = 0;
          }
        } else if (dum1 == 2) {
          res1 = dum2 | all0[y];
          res2 = dum2 | all1[y];
          if (res1 == res2) {
            real[y] = res1;
            all0[y] = res1;
            all1[y] = res1;
          } else {
            real[y] = 2;
            all1[y] = 1;
            all0[y] = 0;
          }
        } else if (dum2 == 2) {
          res1 = dum1 | all0[z];
          res2 = dum1 | all1[z];
          if (res1 == res2) {
            real[y] = res1;
            all0[y] = res1;
            all1[y] = res1;
          } else {
            real[y] = 2;
            all1[y] = 1;
            all0[y] = 0;
          }
        } else {
          real[y] |= real[z];
          all0[y] = real[y];
          all1[y] = real[y];
        }
      } else {
        int dum1, dum2;

        dum1 = real[y];
        dum2 = real[z];

        int res1, res2, res3, res4;

        if (dum1 == 2 && dum2 == 2) {
          res1 = all0[y] & all0[z];
          res2 = all0[y] & all1[z];
          res3 = all1[y] & all0[z];
          res4 = all1[y] & all1[z];
          if (res1 == res2 && res1 == res3 && res1 == res4) {
            real[y] = res1;
            all0[y] = res1;
            all1[y] = res1;
          } else {
            real[y] = 2;
            all1[y] = 1;
            all0[y] = 0;
          }
        } else if (dum1 == 2) {
          res1 = dum2 & all0[y];
          res2 = dum2 & all1[y];
          if (res1 == res2) {
            real[y] = res1;
            all0[y] = res1;
            all1[y] = res1;
          } else {
            real[y] = 2;
            all1[y] = 1;
            all0[y] = 0;
          }
        } else if (dum2 == 2) {
          res1 = dum1 & all0[z];
          res2 = dum1 & all1[z];
          if (res1 == res2) {
            real[y] = res1;
            all0[y] = res1;
            all1[y] = res1;
          } else {
            real[y] = 2;
            all1[y] = 1;
            all0[y] = 0;
          }
        } else {
          real[y] &= real[z];
          all0[y] = real[y];
          all1[y] = real[y];
        }
      }

    }
    for (int i = 31; i >= 0; i--) {
      if (real[i] == 2) {
        cout << "?";
      } else {
        cout << real[i];
      }
    }
    cout << endl;
  }

  return 0;
}