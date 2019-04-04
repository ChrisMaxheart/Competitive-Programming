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

  int N, com;

  cin >> N >> com;

  stack<int> listcom; 

  int loc = 0;
  int i =0;

  for (int i = 0; i < com; i++) {
    string x;
    cin >> x;
    if (x != "undo") {
      int y;
      y = stoi(x, nullptr, 10);
      listcom.push(y);
    } else {
      int y;
      cin >> y;
      for (int j = 0; j < y; j++) {
        if(listcom.size() > 0) {
          listcom.pop();
        }
      }
    }
  }

  while(listcom.size() > 0) {
    int value = listcom.top();
    loc += value;
    listcom.pop();
  }

  while(loc < 0) {
    loc += N;
  }

  loc = loc % N;
  cout << loc << endl;

  return 0;
}