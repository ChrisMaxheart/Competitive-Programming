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

    string x;
    int counter, final, dummy;

    cin >> x;
    counter = 2;
    final = 0;

    for (int i = 0; i < x.length(); i++)
    {
        counter++;
        counter = counter%3;
        dummy = int(x[i]);
        if (counter == 0)
            if (dummy != 80)
                final++;
            else
                continue;
        else if (counter == 1)
            if (dummy != 69)
                final++;
            else
                continue;
        else
            if(dummy != 82)
                final ++;
    }
    cout << final << endl;

    return 0;
}