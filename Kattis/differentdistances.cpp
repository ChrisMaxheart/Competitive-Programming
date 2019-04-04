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

  double x1, y1, x2, y2, p;

  while(cin >> x1, x1) {
    cin >> y1 >> x2 >> y2 >> p;
    cout << setprecision(10) << pow((pow(abs(x1-x2), p) + pow(abs(y1-y2), p)), (1/p)) << endl;
  }  

  return 0;
}