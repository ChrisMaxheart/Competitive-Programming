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

  int T;

  cin >> T;

  while (T--) {
    int no;

    cin >> no;
    cout << no << " ";

    ll num, den;
    char dummy;

    cin >> num >> dummy >> den;

    string seq = "";

    while(num != 1 || den != 1) {
      if (num > den) {
        seq = "1" + seq;
        num -= den;
      } else {
        seq = "0" + seq;
        den -= num;
      }
    }

    seq = "1" + seq;

    ll final = 0;

    for (int i = 0; i < seq.length(); i++) {
      if(seq[seq.length()-1-i] == '1') {
        final += pow(2,i);
      }
    }

    cout << final;

    cout << endl;
  }

  return 0;
}