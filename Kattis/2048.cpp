#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

bool reversecompare(int a, int b)
{
  return a > b;
}

int matrix[5][5];
int copymatrix[5][5];

void transmat() {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      copymatrix[i][j] = matrix[i][j];
    }
  }
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      matrix[j][i] = copymatrix[i][j];
    }
  }
  return;
}

void revmat() {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      copymatrix[i][j] = matrix[i][j];
    }
  }
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      matrix[i][3-j] = copymatrix[i][j];
    }
  }
  return;
}

void shiftleft() {
  for (int i = 0; i < 4; i++) {
    bool fuse = false;
    bool pass = false;
    for (int j = 1; j < 4; j++) {
      if (pass) {
        fuse = false;
        pass = false;
      }
      if (fuse) pass = true;
      for (int k = j; k >0; k--) {
        if (matrix[i][k-1] == 0) {
          swap(matrix[i][k], matrix[i][k-1]);
        }
        else if ((!fuse) && (matrix[i][k] == matrix[i][k-1]) && (matrix[i][k] != 0)) {
          matrix[i][k-1] *= 2;
          matrix[i][k] = 0;
          fuse = true;
        }
        else break;
      }
    }
  }
  return;
}

int main ()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int com;
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 4; j++)
      cin >> matrix[i][j];
  cin >> com;
  if (com == 0)
    shiftleft();
  else if (com == 1) {
    transmat();
    shiftleft();
    transmat();
  } else if (com == 2) {
    revmat();
    shiftleft();
    revmat();
  } else {
    transmat();
    revmat();
    shiftleft();
    revmat();
    transmat();
  }
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 4; j++) {
      cout << matrix[i][j];
      if (j == 3) cout << endl;
      else cout << ' ';
    }


  return 0;
}