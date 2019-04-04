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

  int x, dummy, N;

  cin >> N;

  while(N--) {
    cin >> x;
    dummy = x/400;
    if (dummy*400 < x)
      dummy++;
    cout << dummy << endl;  
  }
  

  return 0;
}