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

  string x, curr;

  unordered_map<string, int> myMap;

  cin >> x;

  bool salah = false;


  for (int i = 0; i < x.length(); i+=3) {
    curr = "";
    curr += x[i];
    curr += x[i+1];
    curr += x[i+2];
    if (myMap[curr] != 0) {
      salah = true;
      break;
    } else {
      myMap[curr] = 1;
      string dummy = "";
      myMap[dummy + curr[0]]++;
    }
  }

  if (salah) {
    cout << "GRESKA" << endl;
  } else {
    cout << 13 - myMap["P"] << " " << 13 - myMap["K"] << " " << 13 - myMap["H"] << " " << 13 - myMap["T"] << endl;
  }


  return 0;
}