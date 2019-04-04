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

int score(int x, int y) {
  if ((x == 1 && y == 2) || (x == 2 && y == 1)) {
    return 1000;
  } else if (x == y) {
    return x * 100;
  } else {
    return 10*max(x, y) + min(x, y);
  }
}

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

  while (cin >> a >> b >> c >> d, a) {
    if (score(a, b) == score(c, d)) {
      cout << "Tie." << endl;
    } else if (score(a, b) > score(c,d)) {
      cout << "Player 1 wins." << endl;
    } else {
      cout << "Player 2 wins." << endl;
    }
  }

  return 0;
}