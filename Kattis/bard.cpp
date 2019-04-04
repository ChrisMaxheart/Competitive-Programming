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

  set<int> vil[105];

  int N, E;
  int bcome = 0;

  cin >> N >> E;

  while(E--) {
    int x;
    int arr[105];

    bool isbard = false;

    cin >> x;
    for (int i = 0; i < x; i++) {
      cin >> arr[i];
      if (arr[i] == 1) {
        isbard = true;
      }
    }

    if (isbard) {
      bcome++;
      for (int i = 0; i < x; i++) {
        if (arr[i] != 1) {
          int num = 100 + bcome;
          vil[arr[i]].insert(num);
        }
      }
    } else {
      for (int i = 0; i < x; i++) {
        for (int j = 0; j < x; j++) {
          if (i == j) {
            continue;
          }
          for (auto &z : vil[arr[i]]) {
            vil[arr[j]].insert(z);
          }
        }
      }
    }
  }
  
  int total = bcome;

  cout << 1 << endl;
  for (int i = 2; i <= N; i++) {
    // cout << "villager no" << i << endl;
    // for (auto &z : vil[i]) {
    //   cout << z << endl;
    // }
    // cout << "***************" << endl;
    if (vil[i].size() == total) {
      cout << i << endl;
    }
  }

  return 0;
}