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

  cin >> N;

  int counter = 0;

  while(N--) {
    string x;

    cin >> x;

    bool win = true;

    for (int i = 0; i < x.length()-1; i++) {
      if (x[i] == 'C' && x[i+1] == 'D') {
        win = false;
      }
    } 
    if (win) {
      counter++;
    }
  }

  cout << counter << endl;

  return 0;
}