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

  int W, P, x;
  bool location[105];
  bool length[105];

  cin >> W;
  for (int i = 0; i < 102; i++) {
    if ((i == 0) || (i == W)) location[i] = true;
    else location[i] = false;
    length[i] = false;
  }

  cin >> P;
  while (P--) {
    cin >> x;
    location[x] = true;
  }

  for (int i = 0; i <= W; i++) {
    for (int j = i+1; j <= W; j++) {
      if (location[i] && location[j])
        length[j-i] = true;
    }
  }

  for (int i = 0; i < 102; i++) {
    if (length[i]) cout << i << " ";
  }
  
  cout << endl;


  return 0;
}