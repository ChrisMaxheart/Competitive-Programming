#include <bits/stdc++.h>

using namespace std;

const double pi = 3.141592653589793;
long long N, L, A, B, i, v, t, counta;
double lnt;
double arr[100100];

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> L >> A >> B;
    lnt = 0.5 * pi * L*(A+B);
    for (i=0; i<N ; i++)
    {
        cin >> v >> t;
        arr[i] = t + (lnt/v);
    }
    counta = 0;
    for (i=1; i<N; i++)
        if (arr[i] < arr[0]) counta++;
    cout << counta+1 << endl;
    return 0;
}