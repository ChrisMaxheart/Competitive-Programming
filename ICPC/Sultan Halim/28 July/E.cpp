#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define pb push_back
#define N 600

unordered_map<string, int> toId;
bool is[N][N];
bool has[N][N];
vi has_temp[N];

string h1[10005];
string h2[100];

int main() {
  int nP, nQ; scanf("%d%d", &nP, &nQ);
  int lastId = 0;
  int hStatementId = 0;
  for (int i = 0; i < nP; i++) {
    char a[500], b[500], c[500];
    scanf("%s%s%s", a, b, c); 
    if (toId[a] == 0) toId[a] = ++lastId;
    if (toId[c] == 0) toId[c] = ++lastId;
    if (b[0] == 'i')
      is[toId[a]][toId[c]] = true;
    if (b[0] == 'h') {
      has[toId[a]][toId[c]] = true;
    }
  }
  for (int i = 1; i <= lastId; ++i) {
    is[i][i] = true;
  }
  
  for (int k = 1; k <= lastId; k++)
  for (int i = 1; i <= lastId; i++)
  for (int j = 1; j <= lastId; j++)
    is[i][j] |= is[i][k] && is[k][j];

  for (int k = 1; k <= lastId; k++)
  for (int i = 1; i <= lastId; i++)
  for (int j = 1; j <= lastId; j++) {
    has[i][j] |= has[i][k] && has[k][j];
    has[i][j] |= has[i][k] && is[k][j];
    has[i][j] |= is[i][k] && has[k][j];
  }
  for (int i = 0; i < nQ; i++) {
    char a[500], b[500], c[500];
    scanf("%s%s%s", a, b, c);
    printf("Query %d: ", i + 1);
    if (b[0] == 'i')
      printf(is[toId[a]][toId[c]] ? "true\n" : "false\n");
    if (b[0] == 'h')
      printf(has[toId[a]][toId[c]] ? "true\n" : "false\n");
  }
}