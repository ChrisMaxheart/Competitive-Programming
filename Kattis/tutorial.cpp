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

struct mystruct {

};

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


// log nya kena masalah

int main ()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int m, n, t;

  cin >> m >> n >> t;

  if (t == 1) {
    ll dummy = 1;
    for (int i = 2; i <= n; i++) {
      dummy *= i;
      if (dummy > m)
        break;
    }
    if (dummy > m) {
      cout << "TLE" << endl;
    } else {
      cout << "AC" << endl;
    }
  } else if (t == 2) {
    ll dummy = 1;
    for (int i = 0; i < n; i++) {
      dummy = dummy << 1;
      if (dummy > m)
        break;
    }
    // cout << dummy << endl;
    if (dummy > m) {
      cout << "TLE" << endl;
    } else {
      cout << "AC" << endl;
    }
  } else if (t == 3) {
    ll dummy = n;

    for (int i = 1; i < 4; i++) {
      if (dummy > m)
        break;
      else
        dummy *= n;
    }
    if (dummy > m) {
      cout << "TLE" << endl;
    } else {
      cout << "AC" << endl;
    }
  } else if (t == 4) {
    ll dummy = n;

    for (int i = 1; i < 3; i++) {
      if (dummy > m)
        break;
      else
        dummy *= n;
    }
    if (dummy > m) {
      // cout << log(m) << "and" << log(n)*3 << endl;
      cout << "TLE" << endl;
    } else {
      cout << "AC" << endl;
    }
  } else if (t == 5) {
    ll dummy = n;

    for (int i = 1; i < 2; i++) {
      if (dummy > m)
        break;
      else
        dummy *= n;
    }
    if (dummy > m) {
      cout << "TLE" << endl;
    } else {
      cout << "AC" << endl;
    } 
  } else if (t == 6) {
    double dummy = n * log (n) / log(2);
    if (m < dummy) {
      cout << "TLE" << endl;
    } else {
      cout << "AC" << endl;
    } 
  } else {
    if (m < n) {
      cout << "TLE" << endl;
    } else {
      cout << "AC" << endl;
    }
  }

  return 0;
}