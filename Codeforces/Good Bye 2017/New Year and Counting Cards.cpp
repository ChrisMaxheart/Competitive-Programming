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
    int counter;
    cin >> x;

    counter = 0;
    for(int i = 0; i < x.length(); i++)
    {
        if (int(x[i]) <= 57)
        {
            if (x[i]%2 != 0)
                counter++;
        }
            
        else
            if (int(x[i]) == 97)
                counter++;
            else if (int(x[i]) == 105)
                counter++;
            else if (int(x[i]) == 101)
                counter++;
            else if (int(x[i]) == 111)
                counter++;
            else if (int(x[i]) == 117)
                counter++;

    }
    cout << counter << endl;

    return 0;
}