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

  if (N < 6) {
    cout << -1 << endl;
  } else {
    for (int i = 0; i < N-7; i++) {
      cout << i+1 << " " << i+2 << endl;
    }
    if (N%2) {
      cout << N-6 << " " << N-4 << endl;
    } else if (N!=6) {
      cout << N-6 << " " << N-5 << endl;
    }
    cout << N-5 << " " << N-4 << endl;
    cout << N-4 << " " << N-3 << endl;
    cout << N-4 << " " << N-2 << endl;
    cout << N-3 << " " << N-1 << endl;
    cout << N-3 << " " << N << endl;
  }

  for (int i = 0; i < N-1; i++)
    cout << i+1 << " " << i+2 << endl;
  

  return 0;
}