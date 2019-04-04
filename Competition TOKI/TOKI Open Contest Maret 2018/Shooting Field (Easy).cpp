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

  int field[104][104];

  int locx = 1;
  int locy = 1;

  int laserx = 1;
  int lasery = 1;

  int arah;

  for (int i = 0; i < 102; i++) {
    for (int j = 0; j < 102; j++) {
      field[i][j] = 0;
    }
  }

  int N, C, T, Q;

  cin >> N >> C >> T >> Q;

  int x, y;

  int type;

  while(C--) {
    cin >> x >> y >> type;
    if (type == 0) {
      field[x][y] = 1;
    } else {
      field[x][y] = 2;
    }
  }

  while(T--) {
    cin >> x >> y;
    field[x][y] = 10;
  }

  int com;

  while(Q--) {
    cin >> com;
    if (com == 1) {
      cin >> x >> y;
      locx = x;
      locy = y;
      laserx = x;
      lasery = y;
    } else if (com == 2) {
      cin >> x >> y;
      if (field[x][y] == 1) {
        field[x][y] = 2;
      } else {
        field[x][y] = 1;
      }
    } else if (com == 3) {
      cin >> x >> y;
      field[x][y] = 0;
      cin >> x >> y;
      field[x][y] = 10;
    } else {
      int z;
      cin >> z;

      laserx = locx;
      lasery = locy;

      double pts = 0;
      double energy = 1; 

      while(laserx > 0 && laserx <= N && lasery > 0 && lasery <= N) {
        // cout << laserx << " " << lasery << endl;
        if (z == 0) 
          laserx++;
        else if (z == 1)
          lasery++;
        else if (z == 2)
          laserx--;
        else if (z == 3)
          lasery--;

        if(field[laserx][lasery] == 1) {
          energy /= 2;
          if (z == 0) 
            z = 3;
          else if (z == 1)
            z = 2;
          else if (z == 2)
            z = 1;
          else if (z == 3)
            z = 0;
        } else if (field[laserx][lasery] == 2) {
          energy /= 2;
          if (z == 0) 
            z = 1;
          else if (z == 1)
            z = 0;
          else if (z == 2)
            z = 3;
          else if (z == 3)
            z = 2;
        } else if (field[laserx][lasery] == 10) {
          pts += energy;
        }
      }
      cout << setprecision(20) << pts << '\n';
    }
  }

  return 0;
}