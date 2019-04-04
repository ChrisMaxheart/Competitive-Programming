#include <bits/stdc++.h>

using namespace std;

#define PI 3.14159265359
#define INF 1E9
#define Tloop int T; cin >> T; for(int i = 1; i < T+1; i++)
#define Nloop int N; cin >> N; for(int j = 0; j < N; j++)
#define printcaseg cout << "Case #" << i << ": "
#define printcaseu cout << "Case " << i << ": "

// Disclaimer: all this typedef only used for competitive programming
//             will not use it in a proper other codes
typedef long long ll;
typedef unsigned long long ull;

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

  int total = 0;

  Tloop {
    double m, l, w, d;
    cin >> l >> w >> d >> m;
    bool can = true;
    if (((l > 56 || w > 45 || d > 25) && (l+w+d)>125) || m > 7) {
      can = false;
    }
    if (can) {
      cout << 1 << endl;
      total++;
    } else {
      cout << 0 << endl;
    }
  }
  cout << total << endl;

  return 0;
}