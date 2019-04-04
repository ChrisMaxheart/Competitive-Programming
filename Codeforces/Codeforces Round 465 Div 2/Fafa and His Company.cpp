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

  int N, counter;

  counter = 0;
  cin >> N;

  for (int i = 1; i <N; i++) {
    if (N%i == 0)
      counter++;
  }

  cout << counter << endl;

  return 0;
}