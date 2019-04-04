#include <bits/stdc++.h>

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

  int N, T, x, com, dummy;
  bool isstack, isqueue, ispri;
  

  while (cin >> N) {
    isstack = true;
    isqueue = true;
    ispri = true;
    stack<int> mystack;
    queue<int> myqueue;
    priority_queue<int> mypri;
    for (int i = 0; i < N; i++) {
      cin >> com >> x;
      if (com == 1) {
        mystack.push(x);
        myqueue.push(x);
        mypri.push(x);
      }
      else {
        if (myqueue.size() == 0)
          isqueue = false;
        else {
          dummy = myqueue.front();
          if (dummy != x)
            isqueue = false;
          myqueue.pop();
        }
        if (mystack.size() == 0)
          isstack = false;
        else {
          dummy = mystack.top();
          if (dummy != x)
            isstack = false;
          mystack.pop();
        }
        if (mypri.size() == 0)
          ispri = false;
        else {
          dummy = mypri.top();
          if (dummy != x)
            ispri = false;
          mypri.pop();
        }
      }
    }
   
    if (((isstack && isqueue) || (isqueue && ispri)) || (isstack && ispri))
      cout << "not sure" << endl;
    else if (isstack)
      cout << "stack" << endl;
    else if (isqueue)
      cout << "queue" << endl;
    else if (ispri)
      cout << "priority queue" << endl;
    else
      cout << "impossible" << endl;
  }


  return 0;
}