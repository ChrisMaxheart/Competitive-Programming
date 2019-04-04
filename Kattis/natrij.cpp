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

int main ()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string start, end, token;

  cin >> start >> end;

  istringstream iss(start);

  vs starts, ends;

  while(getline(iss, token, ':')) {
    starts.push_back(token);
  }

  istringstream isss(end);

  while(getline(isss, token, ':')) {
    ends.push_back(token);
  }

  int startsecs = stoi(starts[0]) * 3600 + stoi(starts[1]) * 60 + stoi(starts[2]);
  int endsecs = stoi(ends[0]) * 3600 + stoi(ends[1]) * 60 + stoi(ends[2]);

  if (startsecs > endsecs) {
    startsecs -= (3600*24);
  }

  int dsecs = endsecs - startsecs;
  if (dsecs == 0) {
    cout << "24:00:00";
  } else {
    int dhours= dsecs/3600;
    dsecs = dsecs % 3600;
    int dmins = dsecs/60;
    dsecs = dsecs % 60;

    if (dhours == 0) {
      cout << "00";
    } else if (dhours < 10) {
      cout << "0" << dhours;
    } else {
      cout << dhours;
    }
    cout <<":";
    if (dmins == 0) {
      cout << "00";
    } else if (dmins < 10) {
      cout << "0" << dmins;
    } else {
      cout << dmins;
    }
    cout <<":";
    if (dsecs == 0) {
      cout << "00";
    } else if (dsecs < 10) {
      cout << "0" << dsecs;
    } else {
      cout << dsecs;
    }
  }
  cout << endl;

  return 0;
}