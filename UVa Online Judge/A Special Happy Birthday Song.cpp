#include <bits/stdc++.h>

using namespace std;

#define PI 3.14159265359
#define INF 1E9
#define Tloop int T; cin >> T; for(int i = 1; i < T+1; i++)
#define Nloop int N; cin >> N; for(int j = 0; j < N; j++)
#define printcaseg cout << "Case #" << i << ": "
#define printcaseu cout << "Case " << i << ": "

// Disclaimer: all this typedef only used for competitive programming
//             will not use it in a proper other codes
typedef long long ll;
typedef unsigned long long ull;

struct mystruct {

};

// pq bakal kebalik
class mycomp
{
  public:
  bool operator() (int a, int b) {
    return a > b; 
  }
};

bool customcompare(int a, int b) {
  return a > b;
}

int main ()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string text[] = {"Happy", "birthday", "to", "you", "Happy", "birthday", "to", "you", "Happy", "birthday", "to", "Rujia", "Happy", "birthday", "to", "you"};
  vector<string> member;
  string x;

  Nloop {
    cin >> x;
    member.push_back(x);
  }

  int counter = 0;
  int counter2 = 0;

  bool done = false;

  while(true) {
    cout << member[counter] << ": " << text[counter2] << endl;
    counter++;
    counter2++;
    if (counter == member.size()) {
      counter = 0;
      done = true;
    }
    if (counter2 == 16) {
      if (done) {
        break;
      } else {
        counter2 = 0;
      }
    }
  }

  return 0;
}