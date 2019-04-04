#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

bool reversecompare(int a, int b)
{
  return a > b;
}

int bruteforce(char x) {
  if (x == ' ') return 0;
  else if (x == 'a') 
    return 2;
  else if (x == 'b') 
    return 22;
  else if (x == 'c') 
    return 222;
  else if (x == 'd') 
    return 3;
  else if (x == 'e') 
    return 33;
  else if (x == 'f') 
    return 333;
  else if (x == 'g') 
    return 4;
  else if (x == 'h') 
    return 44;
  else if (x == 'i') 
    return 444;
  else if (x == 'j') 
    return 5;
  else if (x == 'k') 
    return 55;
  else if (x == 'l') 
    return 555;
  else if (x == 'm') 
    return 6;
  else if (x == 'n') 
    return 66;
  else if (x == 'o') 
    return 666;
  else if (x == 'p') 
    return 7;
  else if (x == 'q') 
    return 77;
  else if (x == 'r') 
    return 777;
  else if (x == 's') 
    return 7777;
  else if (x == 't') 
    return 8;
  else if (x == 'u') 
    return 88;
  else if (x == 'v') 
    return 888;
  else if (x == 'w') 
    return 9;
  else if (x == 'x') 
    return 99;
  else if (x == 'y') 
    return 999;
  else if (x == 'z') 
    return 9999;

}

int main ()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string x;
  int N, dummy, final;
  final = -1;


  cin >> N;
  getline(cin, x);
  for (int j = 0; j < N; j++) {
    final = 0;
    cout << "Case #" << j+1 << ": ";
    getline(cin, x);
    for (int i = 0; i < x.length(); i++) {
      dummy = bruteforce(x[i]);
      if ((final != 0 && (dummy%10 == final%10)) || (final == 0 && dummy == 0))
        cout << " ";
      cout << dummy;
      final = dummy;
    }
    cout << endl;
  }

  return 0;
}