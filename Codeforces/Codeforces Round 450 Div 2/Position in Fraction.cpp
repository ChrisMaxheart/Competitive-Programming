#include <bits/stdc++.h>

using namespace std;

long long a, b, counter, dummy;
bool found;
int c;

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> a >> b >> c;
    found = false;
    counter = 0;
    while ((found == false) && (counter <= 1000000))
    {
        
        dummy = a/b;
        if ((dummy == c) && (counter != 0))
        {
            found = true;
            break;
        }
        else
        {
            a = a%b;
            a *= 10;
        }
        counter++;
    }
    if (found)
        cout << counter << endl;
    else
        cout << -1 << endl;
    return 0;
}