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

    int modlst[45];
    int x, counter, i;
    for (i = 0; i < 42; i++)
        modlst[i] = 0;

    for(i = 0; i <10; i++)
    {
        cin >> x;
        modlst[x%42]++;
    }
    counter = 0;
    for(i = 0 ; i < 42; i++)
        if(modlst[i]!=0)
            counter++;
    cout << counter << endl;

    return 0;
}