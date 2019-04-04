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

  while(T--) {
    int no = 1;
    int N;

    cin >> N;

    for (int i = 1; i < N; i++)
      no = 2*no + 1;

    cout << no << endl;
  }
  

  return 0;
}