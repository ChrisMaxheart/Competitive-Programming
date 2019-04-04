#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

bool reversecompare(int a, int b)
{
  return a > b;
}

int lst1[5003];
int sorted1[5003];
int sorted2[5003];

int main ()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;

  while (true) {
    cin >> N;
    if (N == 0) break;
    for (int i = 0; i < N; i++) {
      cin >> lst1[i];
      sorted1[i] = lst1[i];
    }

    for (int i = 0; i < N; i++) {
      cin >> sorted2[i];
    }

    sort(sorted1, sorted1+N);
    sort(sorted2, sorted2+N);

    for(int i = 0; i < N; i++) {
      auto idx = lower_bound(sorted1, sorted1+N, lst1[i]);
      cout << sorted2[(idx-sorted1)] << endl;
    }

    cout << endl;

  }

  return 0;
}