#include <bits/stdc++.h>

using namespace std;

#define PI 3.141592653

typedef long long ll;
typedef unsigned long long ull;
typedef stack<int> si;
typedef stack<long long> sll;
typedef stack<string> ss;
typedef queue<int> qi;
typedef queue<long long> qll;
typedef queue<string> qs;
typedef priority_queue<int> pqi;
typedef priority_queue<long long> pqll;
typedef priority_queue<string> pqs;
typedef set<int> seti;
typedef set<long long> setll;
typedef set<string> sets;
typedef map<int, string> mapis;
typedef map<string, int> mapsi;
typedef map<long long, string> maplls;
typedef map<string, long long> mapsll;
typedef map<int, int> mapii;
typedef map<string, string> mapss;
typedef map<long long, long long> mapllll;
typedef unordered_map<int, string> umapis;
typedef unordered_map<string, int> umapsi;
typedef unordered_map<long long, string> umaplls;
typedef unordered_map<string, long long> umapsll;
typedef unordered_map<int, int> umapii;
typedef unordered_map<string, string> umapss;
typedef unordered_map<long long, long long> umapllll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<string> vs;

class mycomp
{
  public:
  bool operator() (int a, int b) {
    return a > b; 
  }
};

bool reversecompare(int a, int b) {
  return a > b;
}

int main ()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;

  cin >> N;

  for (int i = 0; i < N; i++) {
    ll shield;

    string x;
    cin >> shield >> x;

    vi sleft;
    vi sright;

    ll counter = 0;
    ll att = 1;
    ll ttldmg = 0;

    int nos = 0;

    for (int j = 0; j < x.length(); j++) {
      if (x[j] == 'S') {
        ttldmg += att;
        nos ++;
        counter++;
      } else {
        att *= 2;
        sleft.push_back(counter);
      }
    }

    for (int j = 0; j < sleft.size(); j++) {
      sright.push_back(counter-sleft[j]);
    }

    sleft.push_back(0);
    sright.push_back(0);

    // for (auto z : sright)
    //   cout << z << endl;

    bool can = true;
    ll nohack = 0;

    if (ttldmg <= shield) {
      nohack = 0;
    } else if (counter > shield) {
      can = false;
    } else {
      for (int j = sleft.size()-1; j >= 0; j--) {
        while(sright[j] > 0) {
          sright[j]--;
          ttldmg -= (1<<(j+1));
          ttldmg += (1<<j);
          nohack++;
          if (ttldmg <= shield) {
            break;
          }
        }
        if (ttldmg <= shield) {
          break;
        }
      }
    }

    cout << "Case #" << i+1 << ": ";
    if (can) {
      cout << nohack << endl;
    } else {
      cout << "IMPOSSIBLE" << endl;
    }

  }

  return 0;
}