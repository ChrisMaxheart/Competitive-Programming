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

    int x;

    cin >> x;
    cout << 1-x << " ";
    cin >> x;
    cout << 1-x << " ";
    cin >> x;
    cout << 2-x << " ";    
    cin >> x;
    cout << 2-x << " ";
    cin >> x;
    cout << 2-x << " ";
    cin >> x;
    cout << 8-x << endl;

    return 0;
}