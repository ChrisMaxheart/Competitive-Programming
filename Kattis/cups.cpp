#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool reversecompare(int a, int b)
{
  return a > b;
}

struct cup
{
    string color;
    ll radius;
};

bool cupsort(cup a, cup b)
{
    return a.radius < b.radius;
}

int main ()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  string a, b;
  cup data[25];

  cin >> N;
  for (int i = 0; i < N; i++)
  {
    cin >> a >> b;
    if (int(a[0]) < 58)
    {
        data[i].color = b;
        data[i].radius = stoll(a, NULL, 10)/2;
    }
    else
    {
        data[i].color = a;
        data[i].radius = ((stoll(b, NULL, 10)));
    }    
  }
  stable_sort(data, data+N, cupsort);
  for (int i = 0; i < N; i++)
  {
    cout << data[i].color << endl;
  }


  return 0;
}