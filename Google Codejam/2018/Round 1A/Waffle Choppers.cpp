#include <bits/stdc++.h>

using namespace std;

#define PI 3.141592653
#define INF 1E9

// Disclaimer: all this typedef only used for competitive programming
//             will not use it in a proper other codes
typedef long long ll;
typedef unsigned long long ull;
typedef stack<int> si;
typedef stack<long long> sll;
typedef stack<string> ss;
typedef queue<int> qi;
typedef queue<long long> qll;
typedef queue<string> qs;
typedef priority_queue<int> pqi;
typedef priority_queue<long long> pqll;
typedef priority_queue<string> pqs;
typedef set<int> seti;
typedef set<long long> setll;
typedef set<string> sets;
typedef map<int, string> mapis;
typedef map<string, int> mapsi;
typedef map<long long, string> maplls;
typedef map<string, long long> mapsll;
typedef map<int, int> mapii;
typedef map<string, string> mapss;
typedef map<long long, long long> mapllll;
typedef unordered_map<int, string> umapis;
typedef unordered_map<string, int> umapsi;
typedef unordered_map<long long, string> umaplls;
typedef unordered_map<string, long long> umapsll;
typedef unordered_map<int, int> umapii;
typedef unordered_map<string, string> umapss;
typedef unordered_map<long long, long long> umapllll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef pair<string, int> psi;
typedef pair<long long, long long> pllll;
typedef pair<string, long long> psll;

struct mystruct {

};

// for pq, return kiri bakal lebih di atas
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

  int T;

  cin >> T;

  for (int i = 0; i < T; i++) {
    int R, C, H, V;

    vi vcut, hcut;

    vcut.push_back(0);
    hcut.push_back(0);

    cin >> R >> C >> H >> V;

    char waffle[105][105];

    int noofcc = 0;
    int frac = (H+1) * (V+1);

    int ccperfrac;

    bool possible = true;

    for (int j = 0; j < R; j++) {
      for (int k = 0; k < C; k++) {
        cin >> waffle[j][k];
        if (waffle[j][k] == '@') {
          noofcc++;
        }
      }
    }

    if (noofcc == 0) {
      cout << "Case #" << i+1 << ": POSSIBLE" << endl;
      continue;
    }

    if (noofcc % frac || noofcc % (H+1) || noofcc % (V+1)) {
      possible = false;
    }

    int counter = 0;
    int calc = 0;

    ccperfrac = noofcc / (H+1);

    for (int j = 0; j < R; j++) {
      if (!possible) {
        break;
      }
      for (int k = 0; k < C; k++) {
        if (waffle[j][k] == '@') {
          counter++;
        }
      }
      // cout << "BARIS ke " << j << " ada " << counter << endl;
      if (counter >= ccperfrac) {
        calc += (counter / ccperfrac);
        counter = counter % ccperfrac;
        if (counter != 0) {
          possible = false;
        }
        hcut.push_back(j+1);
      } 
    }

    // if (possible)
    //   cout << "sampe sini masi mungkin" << endl;

    if (calc != (V+1)) {
      possible = false;
    }

    // if (possible)
    //   cout << "sampe sini masi mungkin" << endl;

    counter = 0;
    calc = 0;

    ccperfrac = noofcc / (V+1);

    for (int j = 0; j < C; j++) {
      if (!possible) {
        break;
      }
      for (int k = 0; k < R; k++) {
        if (waffle[k][j] == '@') {
          counter++;
        }
      }
      // cout << "kolom ke " << j << " ada " << counter << endl;
      if (counter >= ccperfrac) {
        calc += (counter / ccperfrac);
        counter = counter % ccperfrac;
        if (counter != 0) {
          possible = false;
        }
        vcut.push_back(j+1);
        // cout << calc << endl;
      }
    }


    // if (possible)
    //   cout << "sampe sini masi mungkin" << endl;

    // cout << calc << endl;

    if (calc != (H+1)) {
      possible = false;
    }

    // if (possible)
      // cout << "sampe sini masi mungkin" << endl;
    
    counter = 0;

    ccperfrac = noofcc / ((H+1) * (V+1));

    // cout << ccperfrac << endl;
    

    // for (auto j : vcut) {
    //   cout << j << endl;
    // }

    for (int j = 0 ; j < hcut.size()-1; j++) {
      for (int k = 0; k < vcut.size()-1; k++) {
        for (int x = hcut[j]; x < hcut[j+1]; x++) {
          for (int y = vcut[j]; y < vcut[j+1]; y++) {
            if (waffle[x][y] == '@') {
              counter++;
            }
          }
        }
        if (counter != ccperfrac) {
          // cout << counter << "harusnya" << ccperfrac << endl;
          // cout << "kena deh" << endl;
          possible = false;
          break;
        }
        // cout << counter << endl;
        counter = 0;
      }
      if (!possible) {
        break;
      }
    }

    cout << "Case #" << i+1 << ": ";
    if (possible) {
      cout << "POSSIBLE" << endl;
    } else {
      cout << "IMPOSSIBLE" << endl;
    }

  }

  return 0;
}