#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

class mycomp
{
  public:
  bool operator() (int a, int b) {
    return a > b; 
  }
};

bool reversecompare(int a, int b)
{
  return a > b;
}

int main ()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;

  cin >> T;

  while(T--) {
    int G, MG;
    cin >> G >> MG;
    priority_queue<int, vector<int>, mycomp> Gzilla;
    priority_queue<int> MGzilla;

    int x;
    while(G--) {
      cin >> x;
      Gzilla.push(x);
    }
    while (MG--) {
      cin >> x;
      MGzilla.push(x);
    }
    // while(Gzilla.size() > 0) {
    //   cout << Gzilla.top() << endl;
    //   Gzilla.pop();
    // }

    while(true) {
      if (Gzilla.size() == 0) {
        cout << "MechaGodzilla" << endl;
        break;
      } else if (MGzilla.size() == 0) {
        cout << "Godzilla" << endl;
        break;
      }

      if(Gzilla.top() < MGzilla.top()) {
        Gzilla.pop();
      } else {
        MGzilla.pop();
      }
    }

  }



  return 0;
}