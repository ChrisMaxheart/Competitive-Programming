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

  int arr[100010];
  int high[100010];
  int low[100010];

  int N;
  cin >> N;

  int highest, lowest;

  for (int i = 0; i < N; i++) {
    cin >> arr[i];
    if (i == 0) {
      highest = arr[i];
    } else {
      highest = max(highest, arr[i]);
    }

    high[i] = highest;
  }

  for (int i = N-1; i >= 0; i--) {
    if (i == N-1) {
      lowest = arr[i];
    } else {
      lowest = min(lowest, arr[i]);
    }
    low[i] = lowest;
  }

  int count = 0;

  for (int i = 0; i < N; i++) {
    if (high[i] == arr[i] && low[i] == arr[i]) {
      count++;
    }
  }

  cout << count << endl;

  return 0;
}