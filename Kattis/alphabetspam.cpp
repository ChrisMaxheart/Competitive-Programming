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

  int lowcaselobo, lowcaseupbo, upcaselobo, upcaseupbo;
  string x;
  double locase, upcase, sym, white, dummy;

  locase = 0;
  upcase = 0;
  sym = 0;
  white = 0;

  cin >> x;
  lowcaselobo = int('a');
  lowcaseupbo = int('z');
  upcaselobo = int('A');
  upcaseupbo = int ('Z');

  for (int i = 0 ; i < x.length(); i++) {
    dummy = int(x[i]);
    if (x[i] == '_') white++;
    else if (dummy >= lowcaselobo && dummy <= lowcaseupbo) locase++;
    else if (dummy >= upcaselobo && dummy <= upcaseupbo) upcase++;
    else sym++;
  }

  double total = locase+upcase+sym+white;

  cout << setprecision(8) << white/total << endl << locase/total << endl << upcase/total << endl << sym/total << endl;

  return 0;
}