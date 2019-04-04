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
    for (int i = 0; i <= n; i++)
    {
        getline(cin, a);
        dummy = "Simon says";
        if (a.find(dummy) == 0)
        {
            a.erase(0, 10);
            cout << a << endl;
        }
    }

    return 0;
}