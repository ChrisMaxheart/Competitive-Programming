#include <bits/stdc++.h>

using namespace std;
  const double PI = acos(-1);
  #define INF 1E9
  #define endl '\n'
  #define pb push_back
  // A lot of typedefs
    typedef long long ll;

  // struct
    struct mystruct {
      int counter;
    };
  //custom hashing
    struct custom_hash {
      inline std::size_t operator()(const std::pair<int,int> & v) const {
          return v.first*31+v.second*7;
      }
    };
  // pq/set custom comparator, will get reversed (at least in pq)
    class mycomp {
      public:
      bool operator() (mystruct a, mystruct b) {
        return a.counter > b.counter; 
      }
    };
  // sort custom comparator
    bool customcompare(mystruct a, mystruct b) {
      return a.counter > b.counter;
    }
int main ()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}
