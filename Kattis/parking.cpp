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

  int A, B, C, A1, A2, B1, B2, C1, C2;

  cin >> A >> B >> C >> A1 >> A2 >> B1 >> B2 >> C1 >> C2;

  int arr[105];

  for (int i = 0; i < 102; i ++) {
    arr[i] = 0;
  }

  for (int i = A1; i < A2; i++) {
    arr[i]++;
  }

  for (int i = B1; i < B2; i++) {
    arr[i]++;
  }

  for (int i = C1; i < C2; i++) {
    arr[i]++;
  }

  ll total = 0;

  for (int i = 0; i < 102; i++) {
    if (arr[i] == 1) {
      total += A;
    } else if (arr[i] == 2) {
      total += 2*B;
    } else if (arr[i] == 3) {
      total += 3*C;
    }
  }

  cout << total << endl;

  return 0;
}