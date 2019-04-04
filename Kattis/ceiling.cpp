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

  unordered_set<string> myset;

  int n, k;

  cin >> n >> k;

  while(n--) {
    int arr[25];
    string final[25];
    string dummy;

    //baca per angka

    for (int i = 0; i < k; i++) {
      cin >> arr[i];

      // kalau 0 langsung masukkin root
      if (i == 0) {
        final[0] = "ROOT";
      } else {

        // kalo engga bandingin sama root, lebih R kurang L
        if (arr[i] > arr[0]) {
          dummy = "R";
        } else {
          dummy = "L";
        }

        // terus liat dari index 1 ke index i-1, kalo ada yang sama dia bandingin sama yang sama
        for (int j = 1; j < i; j++) {
          if (dummy == final[j]) {
            if (arr[i] > arr[j]) {
              dummy += "R";
            } else {
              dummy += "L";
            }
          }
        }

        //masukkin stringnya
        final[i] = dummy;
      }
    }
    string last = "";
    sort(final, final+k);
    for (int i = 0 ; i < k; i++) {
      last += final[i];
    }
    myset.insert(last);
  }

  cout << myset.size() << endl;
  return 0;
}