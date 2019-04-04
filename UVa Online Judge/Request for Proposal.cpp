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

struct proposal {
  int reqs = 0;
  double price;
  string name;
};

// pq bakal kebalik
class mycomp
{
  public:
  bool operator() (int a, int b) {
    return a > b; 
  }
};

bool customcompare(proposal a, proposal b) {
  if (a.reqs == b.reqs) {
    return a.price < b.price;
  } else {
    return a.reqs > b.reqs;
  }
}

int main ()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, p;
  int counter = 0;
  while(cin >> n >> p, n||p) {
    string req;
    if (counter) {
      cout << endl;
      counter++;
    } else {
      counter++;
    }
    getline(cin, req);
    for (int i = 0; i < n; i++) {
      getline(cin, req);
    }
    string x;
    double y;
    int z;
    vector<proposal> listprop;
    for (int i = 0; i < p; i++) {
      getline(cin, x);
      cin >> y >> z;
      proposal newproposal;
      newproposal.name = x;
      newproposal.price = y;
      newproposal.reqs = z;
      getline(cin, x);
      for (int j = 0; j < z; j++) {
        getline(cin, x);
        // if(requ[x]) {
        //   newproposal.reqs++;
        // }
      }
      listprop.push_back(newproposal);
    }
    stable_sort(listprop.begin(), listprop.end(), customcompare);
    cout << "RFP #" << counter << endl;
    cout << listprop[0].name << endl;
  }

  return 0;
}