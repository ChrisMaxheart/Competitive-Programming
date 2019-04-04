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

  unordered_map<int, set<string>> imaps;
  unordered_map<string, int> smapi;

  while(cin >> x) {
    // cout << x << endl;
    if (x == "clear") {
      break;
    
    } else if (x == "def") {
      int z;
      string y;
      cin >> y >> z;
    
      if (smapi.count(y) == 1) {
        imaps[smapi[y]].erase(y);
    
      }
      smapi[y] = z;
      imaps[z].insert(y);
    
    } else {

      string y;
      char dum;
      getline(cin, y);

      y = y.substr(1, y.length()-1);
      // cout << y << endl;
      istringstream iss(y);


      string ne;
      char z;

      iss >> ne;

      bool dummy = true;
      // cout << z << "and" << y << endl;
      
      int ans = -100000;

      // cout << ne << endl;
      // cout << smapi[ne] << endl;
      if (smapi.count(ne) == 1) {
        ans = smapi[ne];  
      } else {
        dummy = false;
      }
      

      // cout << ans << endl;


      while(iss >> z) {
        // cout << z << endl;
        if (z == '=') {
          // cout << ans << endl;
          cout << y << " ";
          if (imaps[ans].size() == 0 || dummy == false) {
            cout << "unknown" << endl;
          } else {
            cout << *imaps[ans].begin() << endl;
          }
          break;
        } else {
          iss >> ne;

          // cout << ne << endl;

          if (dummy == false) {
            continue;
          }
          if (smapi.count(ne) == 1) {
            if (z == '+') {
              ans += smapi[ne];
            } else {
              ans -= smapi[ne];
            }           
          } else {
            dummy = false;
          }

        }
      }

    }
  }

  return 0;
}