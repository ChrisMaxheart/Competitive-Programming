#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

bool reversecompare(int a, int b)
{
  return a > b;
}

int awal1[2010];
int arr[2010];

int main ()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int counterawal1 = 0;

  int N;

  cin >> N;
  arr[N] = 1;
  for (int i = 0; i < N+1; i++) {
    cin>>arr[i];
    if (i == 0){
      if (arr[0] == 2) {
        awal1[counterawal1] = 0;
        counterawal1++;
      }
      else {
        awal1[counterawal1] = 0;
        counterawal1++;
      }
    }
    else {
      if ((arr[i] == 1) && (arr[i-1] == 2)) {
        awal1[counterawal1] = i;
        counterawal1++;
      }
      else if ((i == N) && (arr[i-1] ==1)) {
        awal1[counterawal1] = i;
        counterawal1++;
      }
    }
  }
  if (counterawal1 <= 2) 
    cout << N << endl;
  else {
    int maxi = 0;
    int dummy;
    for (int i = 2; i < counterawal1; i++) {
      dummy = awal1[i] - awal1[i-2];
      maxi = max(maxi, dummy);
    }
    cout << maxi << endl;
  }


  return 0;
}