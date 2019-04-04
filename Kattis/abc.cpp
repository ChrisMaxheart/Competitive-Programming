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

  int arr[5];
  char x;

  cin >> arr[0] >> arr[1] >> arr[2];
  sort(arr, arr+3);
  for (int i = 0; i < 3; i++) {
    cin >> x;
    if (x == 'A') cout << arr[0];
    else if (x == 'B') cout << arr[1];
    else cout << arr[2];
    if (i != 2) cout << ' ';
    else cout << endl;
  }

  return 0;
}