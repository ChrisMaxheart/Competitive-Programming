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

  Tloop {
    string x;
    cin >> x;
    int lng = x.length()-1;
    if (x == "1" || x == "2" || x == "78") {
      cout << "+" << endl;
    } else if (x[lng] == '5' && x[lng-1] == '3') {
      cout << "-" << endl;
    } else if (x[0] == '9' && x[lng] == '4') {
      cout << "*" << endl;
    } else {
      cout << "?" << endl;
    }
  }

  return 0;
}