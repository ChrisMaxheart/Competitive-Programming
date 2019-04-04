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
  ll val;
  int idx;
  bool done = false;
};

class mycomp
{
  public:
  bool operator() (mystruct a, mystruct b) {
    if (a.val == b.val)
      return a.idx > b.idx;
    else
      return a.val > b.val; 
  }
};

bool customcompare(mystruct a, mystruct b) {
  return a.idx < b.idx;
}

int main ()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  priority_queue<mystruct, vector<mystruct>, mycomp> mypq;

  int N;

  cin >> N;

  for (int i = 0; i < N; i++) {
    mystruct newnum;
    cin >> newnum.val;
    newnum.idx = i;
    mypq.push(newnum);
  }

  // cout << mypq.top().val << "and" << mypq.top().idx;

  vector<mystruct> final;

  while (mypq.size() != 0) {
    mystruct newnum = mypq.top();
    mypq.pop();

    // cout << newnum.val << " di index " << newnum.idx << " diambil awalnya" << endl;

    if (mypq.size() == 0) {
      final.push_back(newnum);
      break;
    }

    

    if(mypq.top().val == newnum.val) {
      // cout << mypq.top().val << " di index " << mypq.top().idx << " diakses" << endl;
      newnum.done = false;
      newnum.val *= 2;
      newnum.idx = max(newnum.idx, mypq.top().idx);
      // cout << newnum.val << " di index " << newnum.idx << " diambil" << endl;
      mypq.pop();
    }
    if (newnum.done) {
      // cout << newnum.val << " di index " << newnum.idx << endl;
      final.push_back(newnum);
    } else {
      // cout << newnum.val << " di index " << newnum.idx << endl;
      newnum.done = true;
      mypq.push(newnum);
    }
  }

  int counter = 0;

  sort(final.begin(), final.end(), customcompare);

  cout << final.size() << endl;

  for (auto x : final) {
    if (counter == 0) {
      cout << x.val;
      counter++;
    } else {
      cout << " " << x.val;
    }
  }

  cout << endl;


  return 0;
}