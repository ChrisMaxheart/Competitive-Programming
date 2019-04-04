#include<bits/stdc++.h>
using namespace std;

bool pta[150][150];

int dr[] = {0, 1, 0, -1};
int dc[] = {1, 0, -1, 0};

void dfs(int r, int c) {
  if (!pta[r][c]) return;
  pta[r][c] = false;
  for (int i = -1; i <= 1; i++){ 
    for (int j = -1; j <= 1; j++) {
      dfs(r + i, c + j);
    }
  }
}

int main() {
  int row, col; scanf("%d%d", &row, &col);
  memset(pta, 0, sizeof pta);

    for (int i = 2; i < row + 2; i++) {
      for (int j = 2; j < col + 2; j++) {
        char c;
        scanf(" %c", &c);
        pta[i][j] = c != '.';
      }
    }

  int ans = 0;
  for (int i = 2; i < row + 2; i++) {
    for (int j = 2; j < col + 2; j++) {
      if (pta[i][j]) ans++;
      dfs(i, j);
    }
  }
  printf("%d\n", ans);
}