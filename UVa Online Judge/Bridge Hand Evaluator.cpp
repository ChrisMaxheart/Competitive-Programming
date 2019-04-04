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

int idx(string x) {
  char y = x[1];
  if (y == 'S') {
    return 0;
  } else if (y == 'H') {
    return 1;
  } else if (y == 'D') {
    return 2;
  } else {
    return 3;
  }
}

char suit (int x) {
  if (x == 0)
    return 'S';
  else if (x == 1)
    return 'H';
  else if (x == 2)
    return 'D';
  else
    return 'C';
}

// sort custom comparator
  bool customcompare(int a, int b) {
    return a > b;
  }

int main ()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string hand;

  while(getline(cin, hand)) {
    istringstream iss(hand);
    int total = 0;
    string card;
    umapsi suits[4];
    suits[idx(card)]["total"] = 0;
    suits[idx(card)]["stop"] = 0;
    for (int i = 0; i < 13; i++) {
      iss >> card;
      string dum = "";
      // cout << dum + card[0] << endl;
      suits[idx(card)][dum + card[0]] = 1;
      suits[idx(card)]["total"] ++;
    }
    for (int i = 0; i < 4; i++) {
      // cout << "suits " << suit(i) << endl;
      // cout << "ada as? " << suits[i]["A"] << endl;
      // cout << "ada king? " << suits[i]["K"] << endl;
      // cout << "ada queen? " << suits[i]["Q"] << endl;
      // cout << "ada jack? " << suits[i]["J"] << endl;
      if(suits[i]["A"]) {
        total += 4;
        suits[i]["stop"] = 1;
      }
      if(suits[i]["K"]) {
        total += 3;
        if (suits[i]["total"] == 1) {
          total--;
        } else {
          suits[i]["stop"] = 1;
        }
      } 
      if(suits[i]["Q"]) {
        total += 2;
        if (suits[i]["total"] < 3) {
          total--;
        } else {
          suits[i]["stop"] = 1;
        }
      }
      if(suits[i]["J"]) {
        total += 1;
        if (suits[i]["total"] < 4) {
          total--;
        }
      }
    }
    // cout << total << endl;
    bool checkstop = true;
    for (int i = 0; i < 4; i++) {
      if (suits[i]["stop"] == 0) {
        checkstop = false;
      }
    }
    if (total >= 16 && checkstop) {
      cout << "BID NO-TRUMP" << endl;
      continue;
    } else {
      for (int i = 0; i < 4; i++) {
        if (suits[i]["total"] <= 1) {
          total += 2;
        } else if (suits[i]["total"] == 2) {
          total++;
        }
      }

      if (total < 14) {
        cout << "PASS" << endl;
      } else {
        int maxi = 0;
        int memo = 0;
        for (int i = 0; i < 4; i++) {
          if (maxi < suits[i]["total"]) {
            memo = i;
            maxi = suits[i]["total"];
          }
        }
        cout << "BID " << suit(memo) << endl;
      }

    }
  }

  return 0;
}