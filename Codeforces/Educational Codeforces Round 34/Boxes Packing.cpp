#include <bits/stdc++.h>

using namespace std;

int N, counter, tempcount;
long long length[5050];
long long save;

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i =0; i<N; i++)
        cin >> length[i];
    length[N] = -1;
    stable_sort(length, length+N);
    counter = 1;
    save = 0;
    tempcount = 1;
    for (int i =1; i<=N; i++)
    {
        if (length[i] == length[i-1])
        {
            tempcount++;
        }
        else
        {
            counter = max(counter, tempcount);
            tempcount = 1;
        }
    }
    cout << counter << endl;
    return 0;
}