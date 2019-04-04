#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool reversecompare(int a, int b)
{
  return a > b;
}

bool checki(int arr[])
{
  bool result = true;
  for (int i = 0; i < 5; i++)
    if (arr[i] != (i+1))
      result = false;
  return result;
}

int data[10];

int main ()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  for (int i = 0; i < 5; i++)
    cin >> data[i];

  for (int i = 0; i < 5; i++)
  {
    for (int j = 0; j < 4-i; j++)
      if (data[j] > data[j+1])
      {
        swap(data[j], data[j+1]);
        for (int k = 0; k < 5; k++)
          cout << data[k] << " ";
        cout << endl;
        if (checki(data))
          break;
      }
    if (checki(data))
      break;
  }

  return 0;
}