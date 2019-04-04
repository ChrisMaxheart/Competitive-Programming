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

  int N, T;
  int arr[1003];

  cin >> N;

  while(N--) {
    cin >> T;
    
    for (int i = 1; i <= T; i++)
      cin >> arr[i];
    for(int i = 2; i < T; i++)
      if (arr[i] != arr[i-1]+1 ) {
        cout << i << endl;
        break;
      }
  }

  return 0;
}