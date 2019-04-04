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

int prof[100010];
int awake[100010];
ll theowrite[100010];
ll difference[100010];
ll benefit[100010];

int main ()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;

  cin >> n >> k;

  for (int i = 0; i < n; i++)
    cin >> prof[i];

  for (int i = 0; i < n; i++)
    cin >> awake[i];

  for (int i = 0; i < n; i++) {
    theowrite[i] = prof[i] * awake[i];
    difference[i] = prof[i] - theowrite[i];
  }

  benefit[0] = 0;
  for (int i = 0; i < k; i++)
    benefit[0] += difference[i];

  for (int i = 1; i < n-k+1; i++) {
    benefit[i] = benefit[i-1] - difference[i-1];
    benefit[i] += difference[k+i-1];
  }

  ll maxi = -10000;
  int idx = 0;
  for (int i = 0; i < n; i++) {
    if (benefit[i] > maxi) {
      maxi = benefit[i];
      idx = i;
    }
  }

  for (int i = idx; i < idx+k; i++) {
    awake[i] = 1;
    theowrite[i] = prof[i];
  }

  ll ttl = 0;
  for (int i = 0; i < n; i++)
    ttl += theowrite[i];

  cout << ttl << endl;
  return 0;
}