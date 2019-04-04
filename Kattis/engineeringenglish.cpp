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

  string x;

  set<string> storewords;

  while(getline(cin, x)) {
    istringstream iss(x);
    string word;
    while(iss >> word) {
      string newword;
      newword = word;
      word = "";
      for (int i = 0; i < newword.length(); i++)
        word += tolower(newword[i]);
      if (storewords.find(word) == storewords.end()) {
        storewords.insert(word);
        cout << newword << " ";
      } else {
        cout << ". ";
      }
    }
    cout << endl;
  } 

  return 0;
}