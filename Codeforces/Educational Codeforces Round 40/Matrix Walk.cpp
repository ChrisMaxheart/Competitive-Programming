#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

bool reversecompare(int a, int b)
{
  return a > b;
}

ll data[200010];

int main ()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll N;
  ll memo;
  ll possiblex = 0;

  bool benar = true;

  memo = 0;
  ll largest = 0;
  cin >> N;

  for (ll i = 0; i < N; i++) {
    if (!benar) {
      break;
    }
    cin >> data[i];
    if (i != 0) {
      if (data[i] == data[i-1]) {
        benar = false;
      }
      if (!possiblex && abs(data[i]-data[i-1])!= 1) {
        possiblex = abs(data[i]-data[i-1]);
      } else if (possiblex && abs(data[i]-data[i-1])!= 1) {
        if (possiblex != abs(data[i]-data[i-1])) {
          benar = false;
        }
      }
    }
    largest = max(largest, data[i]);
  }

  if (possiblex == 0) {
    possiblex = 1;
  } else {
    for (ll i = 1; i < N; i++) {
      if (abs(data[i]-data[i-1])== 1 && min(data[i], data[i-1])%possiblex == 0) {
        benar = false;
        break;
      }
    }
  }


  if (benar) {
    ll possibley = largest/possiblex;
    if (possibley != 1000000000) {
      possibley++;
    }
    cout << "YES" << endl;
    cout << possibley << " " << possiblex<< endl;
  } else {
    cout << "NO" << endl;
  }

  return 0;
}