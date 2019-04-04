#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

bool reversecompare(int a, int b)
{
  return a > b;
}

bool lengthcompare(string a, string b)
{
  return a.length() < b.length();
}

int main ()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int T, N;
  string x, final;

  cin >> T;

  while(T--) {
    bool valid = true;
    cin >> N;
    map<string, bool> mymap;
    string arr[10010];
    for (int i = 0; i < N; i++) cin >> arr[i];
    sort(arr, arr+N, lengthcompare);
    for (int i = 0; i < N; i++) {
      x = arr[i];
      if (i == 0) mymap[x] = true;
      else {
        final = "";
        for (int j = 0; j < x.length(); j++) {
          final += x[j];
          if (mymap[final]) valid = false;
        }
        mymap[x] = true;
      }
    }
    if (valid) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
  

  return 0;
}