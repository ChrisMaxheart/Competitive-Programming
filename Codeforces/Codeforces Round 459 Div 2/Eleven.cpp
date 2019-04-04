#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool reversecompare(int a, int b)
{
  return a > b;
}

bool fibo[1010];

int main ()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  int fib1, fib2, fib3;
  for (int i = 0; i < 1002; i++)
    fibo[i] = false;

  fibo[0] = true;
  fibo[1] = true;
  fibo[2] = true;

  fib1 = 1;
  fib2 = 2;
  fib3 = 0;

  while(fib1 < 1010 && fib2<1010)
  {
    fib3 = fib1 + fib2;
    fibo[fib3] = true;
    fib1 = fib2;
    fib2 = fib3;
  }

  cin >> N;
  for (int i = 1; i <= N; i++)
  {
    if (fibo[i])
        cout << "O";
    else
        cout << "o";
  }
  cout << endl;


  return 0;
}