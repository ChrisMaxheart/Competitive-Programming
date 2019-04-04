#include <bits/stdc++.h>

using namespace std;

long long final, finals, i, x, lt, result, res, j, k;
double ans;
long long pangkat (long long bil, long long pngkt)
{
    finals = bil;
    for (j = 1; j < pngkt; j++)
    {
        finals = finals * bil;
        finals = finals% 1000000007;
    }
    return finals;
}

long long kombin(long long atas, long long bawah)
{
    double dummy = atas;
    for (k =2 ;k<= bawah; k++)
        dummy = dummy/k;
    ans = dummy;
    for (k=1; k<bawah;k++)
    {
        ans = ans*(atas-k);
    }
    finals = ans;
    finals = finals % 1000000007;
    return finals;
}

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> x;
    final = pangkat(2,x);
    for (i = 1; i<=x ; i++)
    {
        if (i%2 == 0)
        {
            final = final + (pangkat(2,x-i) * kombin(x, i))%1000000007;
            final = final%1000000007;
        }
    }
    cout << (pangkat(3,x)+1)/2 << endl;
    return 0;
}