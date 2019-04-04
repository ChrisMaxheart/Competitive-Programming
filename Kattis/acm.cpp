#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

bool reversecompare(int a, int b)
{
  return a > b;
}

struct problem
{
  bool solved = false;
  int min = 0;
};

int main ()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int x, no;
  int ttotal, stotal;
  char y;
  string z;
  problem acm[30];
  while (cin >> x >> y >> z)
  {
    if (x == -1)
      break;
    no = int(y)-65;
    if (z == "wrong")
    {
      acm[no].min += 20;
    }
    else
    {
      acm[no].solved = true;
      acm[no].min += x;
    }
  }
  ttotal = 0;
  stotal = 0;
  for (int i = 0; i < 30; i++)
  {
    if (acm[i].solved)
    {
      stotal++;
      ttotal += acm[i].min;
    }
  }
  cout << stotal << " " << ttotal << endl;

  return 0;
}