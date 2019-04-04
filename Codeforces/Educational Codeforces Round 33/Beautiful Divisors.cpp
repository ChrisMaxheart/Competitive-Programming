#include <bits/stdc++.h>

using namespace std;

int arr[10000];
int N, answer, i, k, result;

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    result = 0;
    k = 0;
    while(result <= 100000)
    {
        k++;
        result = (pow(2, k)-1) * pow(2, k-1);
        arr[k-1] = result;
    }
    cin >> N;
    answer = 1;
    for (i=k-1; i>=0; i--)
    {
        if (arr[i] <= N)
            if (N%arr[i] == 0)
            {
                answer = arr[i];
                break;
            }
    }
    cout << answer << endl;
    return 0;
}