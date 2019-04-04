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

  int graf[30][30];

  for(int i = 0; i < 27; i++) {
    for (int j = 0; j < 27; j++) {
      graf[i][j] = 10000;
    }
    graf[i][i] = 0;
  }


  int m, n;

  cin >> m >> n;

  while(m--) {
    char a, b;
    cin >> a >> b;
    a -= 'a';
    b -= 'a';
    graf[a][b] = 0;
  }

  for (int k = 0; k < 26; k++) {
    for (int i = 0; i < 26; i++) {
      for (int j = 0; j < 26; j++) {
        graf[i][j] = min(graf[i][j], graf[i][k]+graf[k][j]);
      }
    }
  }

  while(n--) {
    string a, b;

    cin >> a >> b;

    bool same;

    same = true;

    if (a.length() != b.length()) {
      same = false;
    } else {
      for (int i = 0; i < a.length(); i++) {
        if (graf [a[i] - 'a'] [b[i] - 'a'] != 0) {
          same = false;
        }
      }
    }
    if (same) {
      cout << "yes" << endl;
    } else {
      cout << "no" << endl;
    }

  }


  return 0;
}