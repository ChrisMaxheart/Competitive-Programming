#include <bits/stdc++.h>

using namespace std;

#define PI 3.14159265359
#define INF 1E9
#define Tloop int T; cin >> T; for(int i = 1; i < T+1; i++)
#define Nloop int N; cin >> N; for(int j = 0; j < N; j++)
#define printcase cout << "Case " << i << ": "

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

  int i = 0;
  string x;

  while(cin >> x, x != "#") {
    i++;
    printcase;
    if (x == "HELLO") {
      cout << "ENGLISH" << endl;
    } else if (x == "HOLA") {
      cout << "SPANISH" << endl;
    } else if (x == "HALLO") {
      cout << "GERMAN" << endl;
    } else if (x == "BONJOUR") {
      cout << "FRENCH" << endl;
    } else if (x == "CIAO") {
      cout << "ITALIAN" << endl;
    } else if (x == "ZDRAVSTVUJTE") {
      cout << "RUSSIAN" <<endl;
    } else {
      cout << "UNKNOWN" << endl;
    }
  }

  return 0;
}