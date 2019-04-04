#include <bits/stdc++.h>

using namespace std;

int opentime[110][15];
long long profit [110][15];
int N, i, j; 
int mystoreopen[15];

long long dummys, maxi;
int counta, counter;

long long countprofit(int arr[])
{
    dummys = 0;
    for (i=1; i<=N; i++)
    {
        counta = 0;
        for (j=0; j<10; j++)
        {
            if ((arr[j] == 1) && (opentime[i][j]==1))
                counta++;
        }
        dummys = dummys + profit[i][counta];
    }
    return dummys;
}

long long forrecursion(int arr[], int no)
{
    int dummy1[15];
    int dummy2[15];
    int doublecheck;
    for (i=0; i<10; i++)
    {
        dummy1[i] = arr[i];
        dummy2[i] = arr[i];
    }
    dummy1[no] = 0;
    dummy2[no] = 1;
    if (no == 0)
    {
        doublecheck = 0;
        for (i=0; i<10; i++)
            if (dummy1[i] != 0) doublecheck++;
        if (doublecheck == 0)
            return countprofit(dummy2); 
        else
            return max(countprofit(dummy1), countprofit(dummy2));
    }
    else
        return max(forrecursion(dummy1, no-1), forrecursion(dummy2, no-1));
}

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (i=1; i<=N; i++)
        for (j=0; j<10; j++)
            cin >> opentime[i][j];
    for (i=1; i<=N; i++)
        for (j=0; j<11; j++)
            cin >> profit[i][j];
    maxi = forrecursion(mystoreopen, 9);
    cout << maxi;
    return 0;
}