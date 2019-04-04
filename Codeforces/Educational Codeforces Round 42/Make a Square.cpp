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

int mini = 20;
int initlength;
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

bool issquare(int num) {
  return sqrt(num) == floor(sqrt(num));
}

void recursivefind(string z) {
  int dummy = z.length();
  for (int i = 0; i < z.length(); i++) {
    if(z[i] == '0')
      dummy--;
    else
      break;
  }
  int newnum = stoi(z);
  if (newnum == 0) {
    return;
  } else if (issquare(newnum)) {
    mini = min(mini, initlength - dummy);
    // cout << newnum << endl;
    return;
  } else if (newnum < 10) {
    return;
  } else {
    for (int i = 0; i < z.length(); i++) {
      recursivefind(z.substr(0, i) + z.substr(i+1, z.length()-i-1));
    }
  }
}

int main ()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string x;
  int bil;

  cin >> x;

  initlength = x.length();

  recursivefind(x);

  if (mini == 20)
    cout << -1 << endl;
  else
    cout << mini << endl;

  return 0;
}