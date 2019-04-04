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

struct hotel {
  int avail;
  int price;
};

// pq bakal kebalik
class mycomp
{
  public:
  bool operator() (int a, int b) {
    return a > b; 
  }
};

bool customcompare(hotel a, hotel b) {
  return a.price < b.price;
}

int main ()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  bool can = false;

  int part, budg, wk, hot;

  while(cin >> part >> budg >> hot >> wk) {
    can = false;
    hotel htlist[20];
    for (int i =0; i < hot; i++) {
      int dum = 0;
      int x;
      cin >> htlist[i].price;
      for (int j = 0; j < wk; j++) {
        cin >> x;
        dum = max(dum, x);
      }
      htlist[i].avail = dum; 
    }
    sort(htlist, htlist+hot, customcompare);
    for (int i = 0; i < hot; i++) {
      if(htlist[i].avail >= part && htlist[i].price*part <= budg) {
        can = true;
        cout << htlist[i].price*part << endl;
        break;
      }
    }
    if (can) {
      continue;
    } else {
      cout << "stay home" << endl;
    }
  }

  return 0;
}