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
  string names[20];
  int N;
  int counter = 0;
  while (true) {
    cin >> N;
    if (N == 0) break;
    counter++;
    cout << "SET " << counter << endl;
    for (int i = 0; i < N; i++)
      cin >> names[i];
    int i = 0;
    while (i < N) {
      cout << names[i] << endl;
      i += 2;
    }
    if (N %2) i = N-2;
    else i = N-1;
    while (i > 0) {
      cout << names[i] << endl;
      i -= 2;
    }
  }
  return 0;
}