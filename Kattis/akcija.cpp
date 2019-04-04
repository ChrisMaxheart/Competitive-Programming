#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

bool reversecompare(int a, int b)
{
  return a > b;
}

int price[100010]; 

int main ()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;

  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> price[i];
  }

  sort(price, price+N, reversecompare);

  ll total = 0;

  for (int i = 0; i < N; i++) {
    if ((i+1)%3) {
      total += price[i];
    }
  }

  cout << total << endl;   

  return 0;
}