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
  string x;

  cin >> N >> x;

  string astr = "";
  string bstr = "";
  string gstr = "";

  for (int i = 0; i < N; i++) {
    if (i%3 == 0)
      astr += 'A';
    else if (i%3 == 1)
      astr += 'B';
    else
      astr += 'C';
    if (i%4 == 0 || i%4 == 2)
      bstr += 'B';
    else if (i%4 == 1)
      bstr += 'A';
    else
      bstr += 'C';
    if (i%6 == 1 || i%6 == 0)
      gstr += 'C';
    else if (i%6 == 2 || i%6 == 3)
      gstr += 'A';
    else
      gstr += 'B';
  }

  int adrian = 0;
  int bruno = 0;
  int goram = 0;
  int maxi = 0;

  for (int i =0; i < N; i++) {
    if (astr[i] == x[i])
      adrian++;
    if (bstr[i] == x[i])
      bruno++;
    if (gstr[i] == x[i])
      goram++;
  }
  bool sudah = false;
  maxi = max(adrian, max(bruno, goram));
  if (maxi == adrian) {
    cout << maxi << endl;
    cout << "Adrian" << endl;
    sudah = true;
  }
  if (maxi == bruno) {
    if (!sudah)
      cout << maxi << endl;
    cout << "Bruno" << endl;
    sudah = true;
  }
  if (maxi == goram) {
    if (!sudah)
      cout << maxi << endl;
    cout << "Goran" << endl;
    sudah = true;
  }


  return 0;
}