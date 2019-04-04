#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool reversecompare(int a, int b)
{
  return a > b;
}

bool comparenew(string a, string b)
{
  if (a[0] == b[0])
    return a[1] < b[1];
  else
    return a[0] < b[0];
}

int main ()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  bool conti = true;
  int N;
  string data[211];

  while (conti)
  {
    cin >> N;
    if (N == 0)
    {
      conti = false;
      return 0;
    }
    else
    {
      for (int i = 0; i < N; i++)
        cin >> data[i];
      stable_sort(data, data+N, comparenew);
      for (int i = 0; i< N; i++)
        cout << data[i] << endl;
      cout << endl;
    }

  }

  return 0;
}