#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

bool reversecompare(int a, int b)
{
  return a > b;
}

struct people {
  string name;
  ll rank;
};

bool compare1(people a, people b) {
  return a.name < b.name;
}

bool compare2(people a, people b) {
  return a.rank > b.rank;
}

int main ()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;

  cin >> T;

  while (T--) {
    int N;
    cin >> N;

    people lists[110];

    for (int i = 0; i < N; i ++) {
      string x;
      cin >> x;
      x = x.substr(0, x.length()-1);
      lists[i].name = x;

      cin >> x;
      istringstream iss(x);
      string rnk = "";
      while(getline(iss, x, '-')) {
        if (x == "upper") {
          rnk = "2" + rnk;
        } else if (x == "middle") {
          rnk = "1" + rnk;
        } else if (x == "lower") {
          rnk = "0" + rnk;
        }
      }

      while(rnk.length() < 10) {
        rnk += "1";
      }

      ll finrnk = stoll(rnk, nullptr, 0);

      lists[i].rank = finrnk;

      cin >> x;
    }

    sort(lists, lists+N, compare1);
    stable_sort(lists, lists+N, compare2);

    for (int i = 0; i < N; i++) {
      cout << lists[i].name << endl;
    }

    for (int i = 0; i < 30; i++) {
      cout << "=";
    }
    cout << endl;

  }

  return 0;
}