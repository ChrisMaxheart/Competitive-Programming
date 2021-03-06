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

int countmile(int x) {
  // if (x%30) {
    return (x/30 + 1)*10;
  // } else {
    // return x/30 * 10;
  // }
}

int countjuice(int x) {
  // if (x%60) {
    return (x/60 + 1)*15;
  // } else {
    // return x/60 * 15;
  // }
}

int main ()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Tloop {
    int mile = 0;
    int juice = 0;
    int x;
    Nloop {
      cin >> x;
      mile += countmile(x);
      juice += countjuice(x);
    }
    // cout << mile << " dan " << juice << endl;
    if (mile == juice) {
      printcaseu << "Mile Juice " << mile;
    } else if (mile < juice) {
      printcaseu << "Mile " << mile;
    } else {
      printcaseu << "Juice " << juice;
    }
    cout << endl;
  }

  return 0;
}