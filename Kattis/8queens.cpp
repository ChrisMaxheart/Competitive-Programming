#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

bool reversecompare(int a, int b)
{
  return a > b;
}

struct pos{
  int x, y;
};

double gradient(pos a, pos b) {
  double ax= a.x;
  double ay= a.y;
  double bx = b.x;
  double by = b.y;
  return ((ax-bx)/(ay-by));
}

int main ()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  pos arr[10];
  char x;

  for (int i = 0; i < 8; i++) {
    arr[i].x = -1;
    arr[i].y = -1;
  }
  int counter = 0;
  for (int i = 0; i < 8; i++)
    for (int j = 0; j < 8; j++) {
      cin >> x;
      if (x == '*') {
        arr[counter].x = i;
        arr[counter].y = j;
        counter++;
      }
    }
  bool valid = true;
  // cout << counter << endl;
  for (int i = 0; i < 8; i++)
    for (int j = i+1; j < 8; j++) {
      if ((arr[i].x == arr[j].x) || (arr[i].y == arr[j].y) || (gradient(arr[i], arr[j]) == 1) || (gradient(arr[i], arr[j]) == -1)) {
        valid = false;
        // cout << gradient(arr[i], arr[j]) << "caused" << "arr[i]" << arr[i].x << arr[i].y << "and" <<arr[j].x << arr[j].y << endl;
      } 
    }

  if (valid) cout << "valid" << endl;
  else cout << "invalid" << endl;

  return 0;
}