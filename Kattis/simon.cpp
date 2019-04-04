#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool reversecompare(int a, int b)
{
    return a > b;
}

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    string a, dummy;
    cin >> n;
    getline(cin, a);
    for (int i = 0; i <= n; i++)
    {
        getline(cin, a);
        dummy = "simon says";
        if (a.find(dummy) == 0)
        {
            a.erase(0, 10);
            if (a.length() > 1) {
              a.erase(0,1);
              cout << a << endl;  
            }
            else
              cout << endl;
            
        }
        else
          cout << endl;
    }

    return 0;
}