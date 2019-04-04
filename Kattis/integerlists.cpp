#include <bits/stdc++.h> // entah ini WA kenapa

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

bool reversecompare(int a, int b)
{
  return a > b;
}

int main ()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  //variables
  ll N, T, x;
  string command;
  bool front, error;
  char dummy;

  cin >> N;
  for (ll i = 0; i < N; i++) {
    cin >> command >> T;

    //declaration of the deque
    deque<ll> mine;

    //declaration
    front = true;
    error = false;

    // input
    for (ll j = 0; j < T; j++) {
      cin >> dummy >> x;
      mine.push_back(x);
    }
    cin >> dummy; // for read the last ]

    if (T == 0) cin >> dummy;

    //read every command and do what it needs to be done
    for (ll j = 0 ; j < (ll)command.length(); j++) {

      //change the bool front from true to false or vice versa
      if (command[j] == 'R') {
        front = !front;
      }

      //if drop, depending whether front is true or false, drop front/back
      else if (command[j] == 'D') {
        if (mine.size() == 0) {
          error = true;
          break;
        }
        else if (front) {
          mine.pop_front();
        }
        else {
          mine.pop_back();
        }
      }
    }
    if (error) {
      cout << "error" << endl;
      continue;
    }

    //start printing
    cout << '[';
    ll dd = mine.size();

    // if front is true, print from front, else from back
    for (ll j = 0 ; j < dd; j++) {
      if (j != 0)
        cout << ',';
      if (front) {
        x = mine.front();
        mine.pop_front();  
      }
      else {
        x = mine.back();
        mine.pop_back();
      }
      cout << x;
    }
    cout << ']' << endl;
  }

  return 0;
}