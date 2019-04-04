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

  int N, x, y;

  cin >> N;
  stack<int> apapun;

  for (int i = 0; i< N; i++)
  {
    cin >> x;
    x = x%2;
    if (apapun.size() == 0)
      apapun.push(x);
    else
    {
      y = apapun.top();
      if (x^y)
      {
        apapun.push(x);
      }
      else
      {
        apapun.pop();
      }
    }
  }
  cout << apapun.size() << endl;

  return 0;
}