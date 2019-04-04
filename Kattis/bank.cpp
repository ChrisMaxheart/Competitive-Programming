#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

bool reversecompare(int a, int b)
{
  return a > b;
}

struct client{
  int duit;
  int waktu;
};

bool clisort(client a, client b) {
  return a.waktu > b.waktu;
}

int main ()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, T;
  client que[10010];


  cin >> N >> T;
  int dummy = N;

  while (N--) {
    int x, t;
    cin >> x >> t;
    que[N].duit = x;
    que[N].waktu = t;
  }

  sort(que, que+dummy, clisort);

  // for (int i = 0; i < dummy; i++) {
  //   cout << "orang ke " << i << " berduit " << que[i].duit << endl;
  // }

  ll sum = 0;

  for (int i = T-1; i >= 0; i--) {
    int idx, save;
    save = 0;
    for (int j = 0; j < dummy; j++) {
      if (que[j].waktu < i) {
        break;
      }
      if (que[j].duit >= save) {
        idx = j;
        save = que[j].duit;
      }
    }
    // cout << "pas waktu " << i;
    // cout << idx << "dan"<< save << endl;
    sum += save;
    if (save != 0)
      que[idx].duit = 0;
  }

  cout << sum << endl;

  return 0;
}