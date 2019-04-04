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

  int n, k;

  cin >> n >> k;

  cout << "YES" << endl;

  char graf[5][103];

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 102; j++) {
      graf[i][j] = '.';
    }
  }

  int noofline, rem;

  noofline = k/(n-2);
  rem = k%(n-2);
  int counter = 0;

  while(noofline--) {
    counter++;
    for (int i = 1; i < n-1; i++) {
      graf[counter][i] = '#';
    }
  }

  if (rem%2) {
    rem--;
    graf[2][n/2] = '#';
  }

  counter = 1;
  while(rem) {
    rem -= 2;
    graf[2][counter] = '#';
    graf[2][n-1-counter] = '#';
    counter++;
  }

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < n; j++) {
      cout << graf[i][j];
    }
    cout << endl;
  }

  return 0;
}