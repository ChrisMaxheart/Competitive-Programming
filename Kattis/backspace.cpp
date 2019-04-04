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

  deque<char> data;
  char temp;
  string inp, final;
  int sz;

  cin >> inp;
  sz = inp.length();
  for (int i = 0; i < sz; i++) 
  {
    // cout << inp[i] << endl;
    if (inp[i] == '<')
      data.pop_back();
    else
      data.push_back(inp[i]);
    // cout << "test" << data.back() << endl;
  }
  final = "";
  for (int i = 0; i < data.size(); i++)
  {
    temp = data[i];
    // data.pop_front();
    final += temp;
  }
  cout << final << endl;
  return 0;
}