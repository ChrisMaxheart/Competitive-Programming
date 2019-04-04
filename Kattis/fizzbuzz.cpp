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

    int x, y, n;

    cin >> x >> y >> n;

    for (int i = 1; i <= n; i++)
    {
        if (i%x == 0)
            if (i%y == 0)
                cout << "FizzBuzz" << endl;
            else
                cout << "Fizz" << endl;
        else if (i%y == 0)
            cout << "Buzz" << endl;
        else
            cout << i << endl;
    }

    return 0;
}