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

  int mat[5][5];
  int sumrow[5];
  int sumcol[5];
  int dummy, dum2;

  for (int i = 0; i < 3; i++)
    for (int j = 0; j< 3; j ++)
      cin >> mat[i][j];

  for (int i = 0; i < 3; i++) {
    int dummy = 0;
    for (int j = 0; j< 3; j ++) {
      dummy += mat[i][j];
    } 
    sumrow[i] = dummy;
  }
  for (int i = 0; i < 3; i++) {
    int dummy = 0;
    for (int j = 0; j < 3; j ++) {
      dummy += mat[j][i];
    } 
    sumcol[i] = dummy;
  }

  bool isit = true;

  if (((sumrow[0]-sumrow[1])%3) || ((sumrow[1]-sumrow[2])%3) || ((sumrow[2]-sumrow[0])%3))
    isit = false;
  if (((sumcol[0]-sumcol[1])%3) || ((sumcol[1]-sumcol[2])%3) || ((sumcol[2]-sumcol[0])%3))
    isit = false;

  if (isit)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;

  return 0;
}