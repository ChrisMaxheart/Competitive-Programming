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

bool dptable[32010];

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

  dptable[0] = false;
  dptable[1] = false;

  vector<int> primelist;

  for (int i = 2; i < 32005; i++)
    dptable[i] = true;

  for (int i = 2; i < 32004; i++) {
    if (dptable[i]) {
      for (int j = 2; j < 32004; j++) {
        if (i * j > 32003)
          break;
        dptable[i*j] = false;
      }
    }
  }

  for (int i = 2; i < 32001; i++) {
    if (dptable[i]) {
      primelist.push_back(i);
    }
  }

  Tloop {
    vector<int> ans;

    int N;

    cin >> N;

    for (auto x : primelist) {
      if(x > N/2) {
        break;
      }
      if (dptable[N-x]) {
        ans.push_back(x);
      }
    }

    cout << N << " has " << ans.size() << " representation(s)" << endl;
    for (auto x : ans) {
      cout << x << "+" << N-x << endl;
    }
    cout << endl;
  }

  return 0;
}