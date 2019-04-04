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


  mapllll mymap;

  int N;

  cin >> N;

  int arr[5];

  while(N--) {
    cin >> arr[0] >> arr[1] >> arr[2] >> arr[3] >> arr[4];
    sort(arr,arr+5);
    ll final = 0;
    for (int i = 0; i < 5; i++) {
      final = final*1000;
      final += arr[i];
    }
    mymap[final]++;
  }

  ll maxi = 0;
  
  ll ttl = 0;

  for (auto x: mymap) {
    maxi = max(maxi, x.second);
  }

  for (auto x: mymap) {
    if (x.second == maxi)
      ttl += x.second;
  }

  cout << ttl << endl;
  

  return 0;
}