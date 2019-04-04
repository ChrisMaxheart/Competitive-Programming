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

  cin >> arr[0] >> arr[1] >> arr[2] >> arr[3];
  sort(arr, arr+4, reversecompare);

  cout << arr[1]*arr[3] << endl;

  return 0;
}