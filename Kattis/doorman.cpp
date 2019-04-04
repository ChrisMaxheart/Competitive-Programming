#include <bits/stdc++.h>

using namespace std;

#define PI 3.141592653
#define INF 1E9
#define Tloop int T; cin >> T; for(int i = 1; i < T+1; i++)
#define Nloop int N; cin >> N; for(int j = 0; j < N; j++)
#define printcase cout << "Case #" << i << ": "

// Disclaimer: all this typedef only used for competitive programming
//             will not use it in a proper other codes
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

struct mystruct {

};

// pq bakal kebalik
class mycomp
{
  public:
  bool operator() (int a, int b) {
    return a > b; 
  }
};

bool customcompare(int a, int b) {
  return a > b;
}

int main ()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  string x;

  cin >> N >> x;

  int counter = 0;
  int dummy = 0;
  int memo = 0;
  // cout << N << endl << x << endl;
  for (int i = 0; i < x.length(); i++) {
    // cout << counter << endl;
    if(x[i] == 'W') {
      counter++;
    } else {
      counter--;
    }
    // cout << counter << endl;
    if (abs(counter) > N && i != x.length()-1) {
      char temp = x[i];
      x[i] = x[i+1];
      x[i+1] = temp;
      counter = memo;
    }
    if (counter == memo) {
      if(x[i] == 'W') {
        counter++;
      } else {
        counter--;
      }
    }
    if (abs(counter) > N) {
      counter = memo;
      break;
    }
    memo = counter;
    dummy++;
    // cout << dummy << endl;
  }

  cout << dummy << endl;

  return 0;
}