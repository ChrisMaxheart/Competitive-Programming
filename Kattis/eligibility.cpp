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
  cin >> N;

  while (N--) {
    string name;
    int dummy, yos, yob, course;
    char dum;

    cin >> name >> yos >> dum >> dummy >> dum >> dummy >> yob >> dum >> dummy >> dum >> dummy >> course;
    cout << name << ' ';
    if ((yos >= 2010) || (yob >= 1991))
      cout << "eligible";
    else if (course > 40)
      cout << "ineligible";
    else cout << "coach petitions";
    cout << endl;

  }

  return 0;
}