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

ll myarr[100010];

int main ()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

 int N, P;

 cin >> N >> P;


 for (int i = 0; i < N; i++) {
  cin >> myarr[i];
  myarr[i] -= P;
 }

 ll maxi, curr;

 curr = myarr[0];
 maxi = myarr[0];

 for (int i = 1; i < N; i++) {
  curr = max(curr+myarr[i], myarr[i]);
  maxi = max(maxi, curr);
 }

 cout << maxi << endl;

  return 0;
}