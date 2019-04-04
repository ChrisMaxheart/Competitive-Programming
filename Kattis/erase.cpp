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

  int N;
  string x1, x2;

  cin >> N >> x1 >> x2;

  if (N%2) {
    bool suc = true;
    for (int i = 0; i < x1.length(); i++)
      if (x1[i] == x2[i])
        suc = false;
    if (suc) 
      cout << "Deletion succeeded" << endl;
    else
      cout << "Deletion failed" << endl;
  } else {
    if (x1 == x2) 
      cout << "Deletion succeeded" << endl;
    else
      cout << "Deletion failed" << endl;
  }

  return 0;
}