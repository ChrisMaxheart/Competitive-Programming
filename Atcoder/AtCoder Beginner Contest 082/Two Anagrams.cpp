#include <bits/stdc++.h>

using namespace std;


bool reversecompare(int a, int b)
{
    return a > b;
}

int lena, lenb;
int asa [105];
int asb [105];
string newa, newb, a, b;

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> a >> b;
    lena = a.length();
    lenb = b.length();
    for(int i = 0; i < lena; i++)
        asa[i] = int(a[i]);
    for(int i = 0; i < lenb; i++)
        asb[i] = int(b[i]);
    stable_sort(asa, asa+lena);
    stable_sort(asb, asb+lenb, reversecompare);
    newa = "";
    newb = "";
    for(int i = 0; i < lena; i++)
        newa += char(asa[i]);
    for(int i = 0; i < lenb; i++)
        newb += char(asb[i]);
    if(newa.compare(newb) < 0)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}