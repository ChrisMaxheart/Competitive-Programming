#include <bits/stdc++.h>

using namespace std;

// defines
  #define PI 3.14159265359
  #define INF 1E9
  #define Tloop int T; cin >> T; for(int i = 1; i < T+1; i++)
  #define Nloop int N; cin >> N; for(int j = 0; j < N; j++)
  #define printcaseg cout << "Case #" << i << ": "
  #define printcaseu cout << "Case " << i << ": "

// A lot of typedefs
  typedef long long ll;
  typedef unsigned long long ull;
  typedef stack<int> si;
  typedef stack<long long> sll;
  typedef stack<string> ss;
  typedef stack<double> sd;
  typedef queue<int> qi;
  typedef queue<long long> qll;
  typedef queue<string> qs;
  typedef queue<double> qd;
  typedef deque<int> di;
  typedef deque<long long> dll;
  typedef deque<string> ds;
  typedef deque<double> dd;
  typedef priority_queue<int> pqi;
  typedef priority_queue<long long> pqll;
  typedef priority_queue<string> pqs;
  typedef priority_queue<double> pqd;
  typedef set<int> seti;
  typedef set<long long> setll;
  typedef set<string> sets;
  typedef set<double> setd;
  typedef map<int, string> mapis;
  typedef map<string, int> mapsi;
  typedef map<long long, string> maplls;
  typedef map<string, long long> mapsll;
  typedef map<int, int> mapii;
  typedef map<string, string> mapss;
  typedef map<long long, long long> mapllll;
  typedef map<long long, double> maplld;
  typedef map<double, long long> mapdll;
  typedef map<string, double> mapsd;
  typedef map<double, string> mapds;
  typedef map<int, double> mapid;
  typedef map<double, int> mapdi;
  typedef unordered_map<int, string> umapis;
  typedef unordered_map<string, int> umapsi;
  typedef unordered_map<long long, string> umaplls;
  typedef unordered_map<string, long long> umapsll;
  typedef unordered_map<int, int> umapii;
  typedef unordered_map<string, string> umapss;
  typedef unordered_map<long long, long long> umapllll;
  typedef unordered_map<long long, double> umaplld;
  typedef unordered_map<double, long long> umapdll;
  typedef unordered_map<string, double> umapsd;
  typedef unordered_map<double, string> umapds;
  typedef unordered_map<int, double> umapid;
  typedef unordered_map<double, int> umapdi;
  typedef vector<int> vi;
  typedef vector<long long> vll;
  typedef vector<string> vs;
  typedef vector<double> vd;
  typedef pair<int, int> pii;
  typedef pair<int, string> pis;
  typedef pair<long long, long long> pllll;
  typedef pair<long long, string> plls;
  typedef pair<double, string> pds;
  typedef pair<double, double> pdd;
  typedef pair<double, int> pdi;
  typedef pair<double, long long> pdll;

// struct
  struct mystruct {

  };

// pq/set custom comparator, will get reversed
  class mycomp {
    public:
    bool operator() (int a, int b) {
      return a > b; 
    }
  };

// sort custom comparator
  bool customcompare(int a, int b) {
    return a > b;
  }

void outshuffling(vi &deck) {
  int sz = deck.size();
  int firsth, secondh;
  if (sz%2) {
    firsth = (sz+1)/2;
  } else {
    firsth = sz/2;
  }
  secondh = sz - firsth;
  vi firstd, secondd;
  for (int i = 0; i < firsth; i++) {
    firstd.push_back(deck[i]);
  }
  for (int i = firsth; i < sz; i++) {
    secondd.push_back(deck[i]);
  }
  int counter = 0;
  for (int i = 1; i <= sz/2; i++) {
    deck[counter] = firstd[i-1];
    counter++;
    deck[counter] = secondd[i-1]; 
    counter++;
  }
  if (firstd.size() > secondd.size()) {
    deck[sz-1] = firstd[sz/2];
  }
  return;
}

void inshuffling(vi &deck) {
  int sz = deck.size();
  int firsth, secondh;
  if (sz%2) {
    firsth = (sz+1)/2;
  } else {
    firsth = sz/2;
  }
  secondh = sz - firsth;
  vi firstd, secondd;
  for (int i = 0; i < secondh; i++) {
    firstd.push_back(deck[i]);
  }
  for (int i = secondh; i < sz; i++) {
    secondd.push_back(deck[i]);
  }
  int counter = 0;
  for (int i = 1; i <= sz/2; i++) {
    deck[counter] = secondd[i-1];
    counter++;
    deck[counter] = firstd[i-1];
    counter++; 
  }
  if (firstd.size() < secondd.size()) {
    deck[sz-1] = secondd[sz/2];
  }
  return;
}

int main ()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  string x;

  cin >> N >> x;

  vi cards, duplicards;

  for (int i = 0; i<N; i++) {
    cards.push_back(i);
    duplicards.push_back(i);
  }

  // for (auto x : cards) {
  //   cout << x << " ";
  // }
  // cout << endl;

  // outshuffling(cards);
  // for (auto x : cards) {
  //   cout << x << " ";
  // }
  // cout << endl;  
  
  int counter = 0;

  if (x == "in") {
    while(true) {
      counter++;
      inshuffling(cards);
      if (cards == duplicards) {
        break;
      }
    }

  } else {
    while(true) {
      counter++;
      outshuffling(cards);
      if (cards == duplicards) {
        break;
      }
    }
  }

  cout << counter << endl;

  return 0;
}