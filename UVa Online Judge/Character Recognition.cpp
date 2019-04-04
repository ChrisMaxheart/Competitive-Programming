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

  char dum, a, b, c;
  int N;

  cin >> N;

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < N; j++) {
      cin >> a >> b >> c >> dum;
      if (i == 3) {
        // cout << a << b << c  << endl;
        if (b == '*') {
          cout << 1;
        } else if (a == '*') {
          cout << 2;
        } else {
          cout << 3;
        }
      }
    }
  }
  cout << endl;

  return 0;
}