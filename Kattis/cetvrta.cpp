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

    int x, y, x1, x2, y1, y2;

    x1 = 1001;
    x2 = 1001;
    y1 = 1001;
    y2 = 1001;


    for (int i = 0; i < 3; i++)
    {
        cin >> x >> y;
        if (x == x1)
            x1 = 1002;
        else if (x == x2)
            x2 = 1002;
        else if (x1 == 1001)
            x1 = x;
        else
            x2 = x;
        if (y == y1)
            y1 = 1002;
        else if (y == y2)
            y2 = 1002;
        else if (y1 == 1001)
            y1 = y;
        else
            y2 = y;
    }

    if (x1 != 1002)
        cout << x1 << " ";
    else
        cout << x2 << " ";
    if (y1 != 1002)
        cout << y1 << endl;
    else
        cout << y2 << endl;
    
    


    return 0;
}