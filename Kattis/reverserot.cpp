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

  int N, dummy;
  string x;
  string arr[28] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z", "_", "."};

  while(true) {
    string final = "";
    cin >> N;
    if (N == 0) break;
    cin >> x;
    

    for (int i = 0; i < x.length(); i++) {
      if (x[i] == '.') dummy = 27;
      else if (x[i] == '_') dummy = 26;
      else dummy = int(x[i])-65;

      dummy += N;
      dummy = dummy%28;
      final = arr[dummy] + final;
    }
    cout << final << endl;
  }

  return 0;
}