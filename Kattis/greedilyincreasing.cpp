#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

bool reversecompare(int a, int b)
{
  return a > b;
}

int arr[1000005];

int main ()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, x, counter, dummy;

  cin >> N;

  counter = 0;
  dummy = 0;

  while (N--) {
    cin >> x;
    if (x > dummy) {
      arr[counter] = x;
      dummy = x;
      counter++;
    }
  }

  cout << counter << endl;
  for (int i = 0; i < counter; i++) {
    if (i!= 0) cout << " ";
    cout << arr[i];
  }

  cout << endl;

  return 0;
}