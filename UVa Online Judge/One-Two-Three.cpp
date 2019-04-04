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

  Tloop {
    string x;
    cin >> x;
    if (x.length() == 5) {
      cout << 3 << endl;
    } else {
      int dum = 0;
      if (x[0] == 'o') {
        dum++;
      }
      if (x[1] == 'n') {
        dum++;
      }
      if (x[2] == 'e') {
        dum++;
      }
      if (dum >= 2) {
        cout << 1 << endl;
      } else {
        cout << 2 << endl;
      }
    }
  }

  return 0;
}