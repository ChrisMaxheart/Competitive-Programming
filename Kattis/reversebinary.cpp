#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool reversecompare(int a, int b)
{
    return a > b;
}

string dectobin(ll dec)
{
    ll counter, i;
    string final;
    final = "";
    counter = log2(dec);
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

ll bintodec(string bin)
{
    ll final, dummy, i, counter;
    final = 0;
    counter = 0;
    for (i = bin.length()-1; i >= 0; i--)
    {
        if (bin[i] == '1')
        {
            final += pow(2, bin.length()-1-i);
        }
    }
    return final;
}

string reversenumber(string num)
{
    string final;
    ll i;
    final = "";
    for (i = num.length()-1; i >= 0; i--)
    {
        final += num[i];
    }
    return final;
}

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll x, dummy;
    string dum2;
    cin >> x;
    dum2 = dectobin(x);
    dum2 = reversenumber(dum2);
    dummy = bintodec(dum2);
    cout << dummy << endl;

    return 0;
}