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

  int final, N;

  cin >> N;

  final = 2;
  int counter = 1;

  while(N--) {
    final += counter;
    counter *= 2;
  }

  cout << final*final << endl;

  return 0;
}