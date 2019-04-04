#include<bits/stdc++.h>
using namespace std;

int main() {

    int N, k;
    
    cin >> N >> k;
    
    string x;
    
    deque<int> lst;
    
    getline(cin,x);
    getline(cin,x);
    
    istringstream iss(x);
    
    while(iss >> x) {
    if (x == "undo") {
      int y;
      iss >> y;
      while(y--)
        lst.pop_back();
    } else {
      lst.push_back(stoi(x));
    }
  }
  
  long long total = 0;
  
  while(lst.size() > 0) {
    total += lst.front();
    lst.pop_front();
  }
  
  total = total%N;
  while (total < 0) {
    total += N;
  }
  cout << total << endl;
  return 0;
}