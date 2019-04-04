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

  int T;

  cin >> T;

  while (T--) {
    int N;
    cin >> N;

    int arr[105];
    int sarr[105];
    int sarr2[105];

    for (int i = 0; i < N; i++) {
      cin >> arr[i];
      sarr[i] = arr[i];
      sarr2[i] = arr[i];
    }

    sort(sarr, sarr+N);
    sort(sarr2, sarr2+N, reversecompare);

    bool arit = true;

    int diff = sarr[0]-sarr[1];

    for (int i = 1; i < N-1; i++) {
      if(sarr[i]-sarr[i+1] != diff) {
        arit = false;
      }
    }

    if (arit) {
      if (memcmp(arr, sarr, N*4) == 0 || memcmp(arr, sarr2, N*4) == 0) {
        cout << "arithmetic" << endl;
      } else {
        cout << "permuted arithmetic" << endl;
      }
    } else {
      cout << "non-arithmetic" << endl;
    }

  }  

  return 0;
}