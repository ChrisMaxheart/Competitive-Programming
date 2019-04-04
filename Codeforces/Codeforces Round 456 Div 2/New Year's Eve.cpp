#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;

bool reversecompare(int a, int b)
{
    return a > b;
}

string dectobin(ll dec)
{
    ll counter, i;
    string final;
    final = "";
    counter = log2(dec); // ga boleh log2, bagi 2 biasa pake mod mod sampe abis, atau pake mod2 shift mod2 shift
    for (i = counter; i >= 0; i--)
    {
        if (dec >= pow(2, i))
        {
            dec -= pow(2, i);
            final += "1";
        }
        else
            final += "0";
    }
    return final;
}

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, k, dummy;
    string dum2;

    cin >> n >> k;

    if (k == 1)
        cout << n << endl;
    else
    {
        dum2 = dectobin(n);
        dummy = dum2.length()-1;
        dummy = pow(2, dummy);
        dummy --;
        cout << dummy << endl;
    } 

    return 0;
    
}