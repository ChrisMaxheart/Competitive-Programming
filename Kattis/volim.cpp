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

  int player, question;

  cin >> player >> question;

  int time = 210;

  for (int i = 0; i < question; i++) {
    int elaps;
    char ans;

    cin >> elaps >> ans;

    time -= elaps;
    if (time <= 0) {
      cout << player << endl;
      break;
    }

    if (ans == 'T') {
      player ++;
      if (player == 9) {
        player = 1;
      }
    }
  }

  return 0;
}