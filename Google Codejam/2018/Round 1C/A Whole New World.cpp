#include <bits/stdc++.h>

using namespace std;

#define PI 3.14159265359
#define INF 1E9
#define Tloop int T; cin >> T; for(int i = 1; i < T+1; i++)
#define Nloop int N; cin >> N; for(int j = 0; j < N; j++)
#define printcase cout << "Case #" << i << ": "

// Disclaimer: all this typedef only used for competitive programming
//             will not use it in a proper other codes
typedef long long ll;
typedef unsigned long long ull;

struct mystruct {
  char val;
  string text;
  int dist;
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

set<char> myset[11];
map<string, set<char>> answer;

string final = "";
bool found = false;


void recurs(int depth, string text, int L) {
  for (auto z : myset[depth]) {
    if (found)
      return;
    string dummy = text;
    dummy += z;
    if (depth == L-1) {
      if(answer[text].find(z) == answer[text].end()) {
        found = true;
        final = dummy;
      }
    } else {
      recurs(depth+1, dummy, L);
    }
  }
}


int main ()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Tloop {
    int N, L;
    cin >> N >> L;
    found = false;
    final = "";
    for (int j = 0; j < 10; j++) {
      myset[j].clear();
    }
    answer.clear();
    string x;
    for (int j = 0; j < N; j++) {
      cin >> x;
      string final = "";
      for (int k = 0; k < x.length(); k++) {
        if (k == x.length()-1) {
          answer[final].insert(x[k]);
        } else {
          final += x[k];
        }
        myset[k].insert(x[k]);
      }
    }

    ll total = 1;

    for (int j = 0 ; j < L; j++) {
      // cout << myset[j].size() << endl;
      total *= myset[j].size();
      if (total > 2000) {
        break;
      }
    }

    if (N >= total) {
      printcase << "-" << endl;
      continue;
    }

    recurs(0, "", L);
    printcase << final << endl;
  }

  return 0;
}