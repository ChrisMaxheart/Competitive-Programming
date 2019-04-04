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
    double L, N;

    cin >> L >> N;

    double myarr[100010];

    for (int j = 0; j < 100002; j++) {
      myarr[j] = 0;
    }

    double done = 0;

    for (int j = 0; j < N; j++) {
      cin >> myarr[j];
      done += myarr[j];
    }

    double remain = L - done;

    int counter = 0;
    // cout << done << endl;
    // cout << L << endl;
    // cout << "check" << endl;
    // cout << remain << endl;

    while (remain) {
      double dummy;
      double deci = myarr[counter];

      deci *= 100;
      deci /= L;

      // cout << remain << endl;
      deci = modf(deci, &dummy);
      // cout << remain << "punya" << deci << endl;
      if (deci < 0.5) {
        // cout << deci << endl;
        myarr[counter]++;
        remain--;
      } else {
        counter++;
      }
      // cout << remain << endl;
    }

    int total = 0;

    for (int j = 0; j < max(counter+1, int(N)); j++) {
      double deci = myarr[j];
      double dummy;
      cout << myarr[j] << " ";
      deci *= 100;
      deci /= L;
      if (modf(deci, &dummy) >= 0.5) {
        total += 1;
      }
      total += dummy;
    }

    printcase << total << endl;

  }

  return 0;
}