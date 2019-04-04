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

  double H, U, F, D;

  while(cin >> H, H) {
    cin >> U >> D >> F;
    int day = 0;
    double dec = F/100 * U;
    double pos = H; 
    while(true) {
      day++;
      if (pos < U) {
        cout << "success on day " << day << endl;
        break;
      }
      pos -= max(U, 0.00);
      pos += D;
      U -= dec;
      // cout << "after day " << day << " remaining height " << pos << endl;
      if (pos > H) {
        cout << "failure on day " << day << endl;
        break;
      }
    }
  }

  return 0;
}