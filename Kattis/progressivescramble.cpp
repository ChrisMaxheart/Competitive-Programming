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

  char table[27] = {' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

  Tloop {
    char chr, dum;
    string x;

    cin >> chr;

    getline(cin, x);

    x = x.substr(1, x.length()-1);

    int myarr[85];
    // cout << chr << x << endl;
    if (chr == 'd') {
      for (int j = 0; j < x.length(); j++) {
        for(int k = 0; k < 27; k++) {
          if (x[j] == table[k]) {
            myarr[j] = k;
            break;
          }
        }
      }
      for (int j = x.length()-1; j > 0; j--) {
        myarr[j] -= myarr[j-1];
        while(myarr[j] < 0) {
          myarr[j] += 27;
        }
      }
      for (int j = 0; j < x.length(); j++) {
        x[j] = table[myarr[j]];
      }
    } else {
      for (int j = 0; j < x.length(); j++) {
        int dummy;
        if (x[j] == ' ') {
          dummy = 0;
        } else {
          dummy = x[j] - 'a' + 1;
        }
        // cout << dummy << " ";
        if (j == 0) {
          myarr[j] = dummy;
        } else {
          myarr[j] = myarr[j-1] + dummy;
          myarr[j] = myarr[j] % 27;
        }
        x[j] = table[myarr[j]];
        // cout << x << endl;
      }
      // for (int j = 0; j < x.length(); j++)
      //   cout << myarr[j] << " ";
      // cout << endl;
    }
    cout << x << endl;
  }

  return 0;
}