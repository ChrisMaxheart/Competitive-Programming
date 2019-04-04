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

  int N, x;

  cin >> N;
  for (int i = 0; i < N; i++) {
    int arr[1010];
    cin >> x;
    for (int j = 0; j<x; j++) {
      cin >> arr[j];
    }
    sort(arr, arr+x);
    int ptr = 0;
    while (ptr < x) {
      if (arr[ptr] == arr[ptr+1])
        ptr += 2;
      else {
        cout << "Case #" << i+1 << ": "; 
        cout << arr[ptr] << endl;
        ptr = x;
      }

    }
  }

  return 0;
}