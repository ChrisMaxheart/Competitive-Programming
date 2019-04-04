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
    // cout << i << endl;
    ll tot;
    cin >> tot;

    int myarr[100010];

    for (int j = 0; j < 100005; j++) {
      myarr[j] = 0;
    }

    int dummy = 0;

    Nloop {
      // int x;
      cin >> myarr[j];
      dummy += myarr[j];
      // myarr[j]++;
    }

    if (100%tot == 0) {
      // cout << tot << endl;
      printcase << 100 << endl;
      continue;
    }

    int remaining = tot-dummy;

    int counter = 0;

    while(remaining) {
      ll deci = myarr[counter];
      deci *= 1000;
      deci = floor(deci/tot);
      if ((deci % 10) < 5) {
        remaining--;
        myarr[counter]++;
      } else {
        counter++;
      }
    }
    // cout << i << endl;
    int total = 0;

    for (int j = 0; j <= max(counter, N-1); j++) {
      // cout << myarr[j] << " ";
      ll deci = myarr[j];
      deci *= 1000;
      deci = floor(deci/tot);
      // cout << "with percentage " << deci << " "; 
      if (deci%10 >= 5) {
        deci += 10;
      }
      total += floor(deci / 10);
    }

    // cout << endl;
    printcase << total << endl;

  }

  return 0;
}