#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

bool reversecompare(int a, int b)
{
  return a > b;
}

int main ()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, x;
  bool bus[1050];
  bool inproc = false;
  bool extend = false;
  bool extendthree = false;
  for (int i = 0; i < 1002; i++)
    bus[i] = false;

  cin >> N;

  while(N--) {
    cin >> x;
    bus[x] = true;
    // cout << x;
  }

  for (int i = 0; i < 1002; i++) {
    if (bus[i]) {
      if (inproc) {
        if (extend) extendthree = true;
        extend = true;
        continue;
      }
      else {
        cout << i;
        inproc = true;
      }
    }
    else{
      if (inproc && extendthree) {
        cout << "-" <<i-1 << " ";        
      }
      else if (inproc) {
        cout << " ";
        if (extend) cout << i-1 << " ";
      } 
      inproc = false;
      extend = false;
      extendthree = false;
    }
  }
  cout << endl;

  return 0;
}