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

  string x, y;

  cin >> x >> y;

  multiset<char> myset;
  char myarr[15];

  bool pass = true;

  for (int i  = 0; i < x.length(); i++) {
    myset.insert(x[i]);
    myarr[i] = x[i];
  }

  int counter = 0;

  for (int i = 0; i < y.length(); i++) {
    if (myset.find(y[i]) != myset.end()) {
      // cout << y[i] << endl;
      if (y[i] == myarr[counter]) {
        // cout << y[i] << "while i " << i << endl;
        int dummy = myset.count(y[i]);
        myset.erase(y[i]);
        for (int j = 0; j < dummy-1; j ++) {
          myset.insert(y[i]);
        }
        counter++;
      } else {
        pass = false;
        break;
      }
    } 
  }

  // cout << counter << endl;

  // cout << myset.size() << endl;
  // if (pass) {
  //   cout << "boolean true" << endl;
  // }

  if (pass && myset.size() == 0) {
    cout << "PASS" << endl;
  } else {
    cout << "FAIL" << endl;
  }

  return 0;
}