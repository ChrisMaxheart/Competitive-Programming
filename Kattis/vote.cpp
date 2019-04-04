#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

bool reversecompare(int a, int b)
{
  return a > b;
}

struct politician{
  int id;
  int vote;
};

bool newcompare(politician a, politician b) {
  return a.vote > b.vote;
}

int main ()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int T, N;

  cin >> T;

  while(T--) {
    cin >> N;

    politician voting[15];
    int total = 0;

    for(int i = 0; i < N; i++) {
      cin >> voting[i].vote;
      voting[i].id = i+1;
      total += voting[i].vote;
    }

    // cout << total << endl;

    sort(voting, voting+N, newcompare);

    // cout << voting[0].vote << endl;

    if (voting[0].vote == voting[1].vote) {
      cout << "no winner" << endl;
    } else if (voting[0].vote * 2 <= total) {
      cout << "minority winner " << voting[0].id << endl;
    } else {
      cout << "majority winner " << voting[0].id << endl;
    }

  }

  return 0;
}