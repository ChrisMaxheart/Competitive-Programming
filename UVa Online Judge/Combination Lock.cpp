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

  int a, b, c, d;

  while (cin >> a >> b >> c >> d, a||b||c||d) {
    int total = 120;
    if (b-a < 0) {
      total += (a-b);
    } else {
      total += (40 + a-b);
    }
    if (b-c < 0) {
      total += (c-b);
    } else {
      total += (40 + c-b);
    }

    if (d-c < 0) {
      total += (c-d);
    } else {
      total += (40 + c-d);
    }
    total *= 9;
    cout << total << endl;
  }

  return 0;
}