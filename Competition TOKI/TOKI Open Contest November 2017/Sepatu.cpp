#include <bits/stdc++.h>

using namespace std;

long long totalo, mungkin, i, N, K, counta, gcds;
long long jml[41000];
string sepatu;

int hcf(int n1, int n2)
{
    if (n2 != 0)
       return hcf(n2, n1 % n2);
    else 
       return n1;
}

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> K;
    N = N*2;
    cin >> sepatu;
    counta = 0;
    for (i=N-1; i>= 0; i--)
    {
        if (sepatu[i] == ')') counta++;
        jml[i] = counta; 
    }
    totalo = 0;
    for (i=0; i<N; i++)
    {
        if (i<= (N-K-1)) totalo = totalo + K;
        else totalo = totalo + (N-1-i);
    }
    mungkin = 0;
    for (i = 0; i<N; i++)
    {
        if (sepatu[i] == '(')
        {
            if (i < (N-K-2)) mungkin = mungkin + jml[i] - jml[i+K+1];
            else mungkin = mungkin + jml[i];
        }
        
    }
    gcds = hcf(totalo, mungkin);
    cout << mungkin/gcds << '/' << totalo/gcds << endl;
    return 0;
}