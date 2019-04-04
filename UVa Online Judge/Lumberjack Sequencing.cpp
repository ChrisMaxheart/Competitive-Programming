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

  cout << "Lumberjacks:" << endl;

  Tloop {
    int curr = 0;
    int curr2 = 105;
    bool can1 = true;
    bool can2 = true;
    int x;
    for (int j = 0; j < 10; j++) {
      cin >> x;
      if (x < curr) {
        can1 = false;
      }
      if (x > curr2) {
        can2 = false;
      }
      curr = x;
      curr2 = x;
    }
    if (can1 || can2) {
      cout << "Ordered" << endl;
    } else {
      cout << "Unordered" << endl;
    }
  }

  return 0;
}