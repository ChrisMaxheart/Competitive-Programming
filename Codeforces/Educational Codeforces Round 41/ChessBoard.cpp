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

  int chessstart[4];
  int chesswrong[4];

  for (int i = 0; i < 4; i++)
    chesswrong[i] = 0;

  char x;

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < N; j++) {
      for (int k = 0; k < N; k++) {
        cin >> x;
        if (!j && !k) {
          chessstart[i] = x-48;
        } else {
          if ((j+k)%2) {
            // cout << x-48 << "pas" << j << "dan" << k << endl;
            if (x-48 == chessstart[i]) {
              // cout << x << "pas" << j << "dan" << k << endl;
              chesswrong[i]++;
            }
          } else {
            if (x-48 != chessstart[i]) {
              // cout << chessstart[i] << endl;
              // cout << x-48 << "pas" << j << "dan" << k << endl;
              chesswrong[i]++;
            }
          }
        }
      }
    }
  }  

  for (int i = 0; i < 4; i++) {
    // cout << chesswrong[i] << endl;
    if (chessstart[i]) {
      chessstart[i] = 0;
      chesswrong[i] = N*N - chesswrong[i];
    }
  }

  sort(chesswrong, chesswrong+4, reversecompare);
  chesswrong[0] = N*N - chesswrong[0];
  chesswrong[1] = N*N - chesswrong[1];

  ll ttl = 0;

  for (int i = 0; i < 4; i++) {
    ttl += chesswrong[i];
    // cout << chesswrong[i] << endl;
  }

  cout << ttl << endl;

  return 0;
}