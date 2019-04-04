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
    int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;
    if ((a == 1 && b == 2 && c == 3 && d == 4 && e == 5) || (a == 2 && b == 3 && c == 4 && d == 5 && e == 6)) {
      cout << "Y" << endl;
    } else {
      cout << "N" << endl;
    }
  }  

  return 0;
}