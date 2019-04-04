#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

bool reversecompare(int a, int b)
{
  return a > b;
}

int mat[55][55];

int main ()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int H, W;
  int left, right, up, down, dummy;
  char x;
  cin >> H >> W;
  int counter = 0;

  for (int i = 1; i <= H; i++) 
    for (int j = 1; j <= W; j++) {
      cin >> x;
      if (x == '.')
        mat[i][j] = 0;
      else {
        mat[i][j] = -1;
        counter++;
      }
    }

  mat[1][1] = 1;

  for (int k = 0; k < (H*W); k++) {
    for (int i = 1; i <= H; i++)
      for (int j = 1; j <= W; j++) {
        dummy = mat[i][j];
        left = mat[i][j-1];
        if (left<1) left = 3000;
        right = mat[i][j+1];
        if (right<1) right = 3000;
        up = mat[i-1][j];
        if (up<1) up = 3000;
        down = mat[i+1][j];
        if (down<1) down = 3000;
        if (dummy == 0) mat[i][j] = 3001;
        mat[i][j] = min(mat[i][j], min(up+1, min(down+1, min(left+1, right+1))));
        if (mat[i][j] == 3001) 
          mat[i][j] = 0;
      }
  }
  dummy = (H*W)-mat[H][W]-counter;
  if (mat[H][W] > 0) cout << dummy << endl;
  else cout << -1 << endl;
  // for (int i = 1; i <= H; i++) {
  //   for (int j = 1; j <= W; j++)
  //     cout << mat[i][j];
  //   cout << endl;
  // }
  return 0;
}