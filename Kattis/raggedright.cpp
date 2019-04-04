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

  int N = 0;
  string para[105];
  string x;
  ll largest = 0;

  while(getline(cin,x)) {
    para[N] = x;
    ll dummy = x.length();
    largest = max(largest, dummy);
    N++;
  }

  ll total = 0;

  for (int i = 0; i < N-1; i++) {
    total += (largest - para[i].length())*(largest - para[i].length());
  } 

  cout << total << endl;



  return 0;
}