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

  int D, M;

  int arr[15];

  int start = 3;

  arr[0] = 0;
  arr[1] = 31;
  arr[2] = 28;
  arr[3] = 31;
  arr[4] = 30;
  arr[5] = 31;
  arr[6] = 30;
  arr[7] = 31;
  arr[8] = 31;
  arr[9] = 30;
  arr[10] = 31;
  arr[11] = 30;
  arr[12] = 31;

  cin >> D >> M;

  for (int i = M; i > 1; i--) {
    start += arr[i-1];
  }

  start += (D-1);

  start = start % 7;

  if (start == 0) {
    cout << "Monday";
  } else if (start == 1) {
    cout << "Tuesday";
  } else if (start == 2) {
    cout << "Wednesday";
  } else if (start == 3) {
    cout << "Thursday";
  } else if (start == 4) {
    cout << "Friday";
  } else if (start == 5) {
    cout << "Saturday";
  } else {
    cout << "Sunday";
  }

  cout << endl;

  return 0;
}