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

  while(N--) {
    string x;
    cin >> x;
    int bilsq = sqrt(x.length());

    string final = "";

    for (int i = bilsq-1; i >= 0; i--) {
      for (int j = 0; j < bilsq; j++) {
        // cout << "lokasi" << j << "dan" << i << endl;
        final += x[(j*bilsq)+i];
        // cout << "isi" << data[j][i] << endl;
      }
    }
    cout << final << endl;
  }  

  return 0;
}