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

  bool isunderattack(int colK, int rowK, int colQ, int rowQ) {
    if (rowQ!=rowK && colQ!=colK) {
      return false;
    }
    return true;
  }

int main ()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int K, Q, N;

  while (cin >> K >> Q >> N) {
    if (K == Q || K < 0 || K > 63 || Q < 0 || Q > 63) {
      cout << "Illegal state" << endl;
      continue;
    }
    int rowK = K/8;
    int rowQ = Q/8;
    int rowN = N/8;
    int colQ = Q%8;
    int colK = K%8;
    int colN = N%8;
  
    if (colQ != colN && rowQ != rowN) {
      cout << "Illegal move" << endl;
      continue;
    }

    // cout << K << " " << Q  << " " << N << endl;

    // cout << rowK << " " << colK << endl;
    // cout << rowQ << " " << colQ << endl;
    // cout << rowN << " " << colN << endl;

    // cout << "test" << endl;


    if (colQ == colN && colQ == colK && ((rowQ < rowK && rowK < rowN)||(rowQ > rowK && rowK > rowN))) {
      cout << "Illegal move" << endl;
      continue;
    }

    if (rowQ == rowN && rowQ == rowK && ((colQ < colK && colK < colN)||(colQ > colK && colK > colN))) {
      cout << "Illegal move" << endl;
      continue;
    }

    if (rowN == rowQ && colN == colQ) {
      cout << "Illegal move" << endl;
      continue;
    }

    if (rowN == rowK && colN == colK) {
      cout << "Illegal move" << endl;
      continue;
    }


    if ((abs(rowN-rowK)<2 && colN==colK) || (abs(colN-colK)<2 && rowN==rowK)) {
      cout << "Move not allowed" << endl;
      continue;
    }


    bool canmove = false;

    if (rowK != 0) {
      if (!isunderattack(colK, rowK-1, colN, rowN)) {
        canmove = true;
      }
      // if (colK != 0) {
      //   if (!isunderattack(colK-1, rowK-1, colN, rowN)) {
      //     canmove = true;
      //   }
      // }
      // if (colK != 7) {
      //   if (!isunderattack(colK+1, rowK-1, colN, rowN)) {
      //     canmove = true;
      //   }
      // }
    }

    if (colK!=0 && !isunderattack(colK-1, rowK, colN, rowN)) {
      canmove = true;
    }

    if (colK!=7 && !isunderattack(colK+1, rowK, colN, rowN)) {
      canmove = true;
    }

    if (rowK != 7) {
      if (!isunderattack(colK, rowK+1, colN, rowN)) {
        canmove = true;
      }
      // if (colK != 0) {
      //   if (!isunderattack(colK-1, rowK+1, colN, rowN)) {
      //     canmove = true;
      //   }
      // }
      // if (colK != 7) {
      //   if (!isunderattack(colK+1, rowK+1, colN, rowN)) {
      //     canmove = true;
      //   }
      // }
      // cout << "check" << endl;
    }
      if (canmove) {
        cout << "Continue" << endl;
      } else {
        cout << "Stop" << endl;
      }

  }

  return 0;
}