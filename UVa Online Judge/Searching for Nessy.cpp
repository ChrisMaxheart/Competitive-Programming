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
    int x, y;
    cin >> x >> y;
    x -= 2;
    y -= 2;
    ll total = 1;
    if (x%3 == 0) {
      total *= (x/3);
    } else {
      total *= (x/3 + 1);
    }
    if (y%3 == 0) {
      total *= (y/3);
    } else {
      total *= (y/3 + 1);
    }
    cout << total << endl;
  }

  return 0;
}