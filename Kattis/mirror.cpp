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

  int N, x, y;

  cin >> N;

  for (int i = 0; i < N; i++) {
    cout << "Test " << i+1 << endl;
    cin >> x >> y;
    stack<string> mystack;
    for (int j = 0; j < x ; j++) {
      string z;
      cin >> z;
      reverse(z.begin(), z.end());
      mystack.push(z);
    }
    for (int j = 0; j < x; j++) {
      cout << mystack.top() << endl;
      mystack.pop();
    }
  }

  return 0;
}