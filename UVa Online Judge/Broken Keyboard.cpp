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
  ll counter = 0;
  string x;
  while (cin >> x)
  {
    counter = 0;
    if (x == "")
      break;
    // cin >> x;
    deque<char> final;
    // final.push_back('a');
    auto ptr = final.begin(); // <<--- liat baik2 ahaha

    for(ll i = 0; i < x.length(); i++)
    {
      // cout << x[i];
      if (x[i] == '[')
      {
        counter = 0;
        ptr = final.begin();
      }
      else if (x[i] == ']')
      {
        counter = final.size();
        ptr = final.end();
      }
      else
      {
        // harusnya pas insertnya bisa ptr = final.insert(...) gitu jadi gaperlu initialize lagi
        ptr = final.begin()+counter;
        final.insert(ptr, x[i]);
        // cout  << "setelah" << x[i] << endl;
        counter++;
      }
    }
    // cout << final[7] << endl;
    for (ll i = 0; i < final.size(); i++)
      cout << final[i];
    cout << endl;    
  }


  return 0;
}
