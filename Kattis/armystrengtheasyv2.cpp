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
    priority_queue<int> Gzilla;
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

    int gbest = Gzilla.top();
    int mbest = MGzilla.top();

    if (gbest < mbest) {
        cout << "MechaGodzilla" << endl;
    } else {
        cout << "Godzilla" << endl;
    }
  }


  return 0;
}