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

  int N, M;

  cin >> N >> M;

  if (N > M) {
    cout << "Dr. Chaz needs " << N-M ;
    if (N-M == 1)
      cout <<" more piece of chicken!" << endl;
    else
      cout <<" more pieces of chicken!" << endl;
  }
  else {
    cout << "Dr. Chaz will have " << M-N ;
    if (M-N == 1)
      cout <<" piece of chicken left over!" << endl;
    else
      cout <<" pieces of chicken left over!" << endl;
  }


  return 0;
}