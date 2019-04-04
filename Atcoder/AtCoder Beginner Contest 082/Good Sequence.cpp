#include <bits/stdc++.h>

using namespace std;



int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long N, memo, counter, final;
    long long seq[100010];


    cin >> N;
    for(long long i = 0; i<N; i++)
        cin >> seq[i];
    stable_sort(seq, seq+N);
    memo = seq[0];
    counter = 0;
    final = 0;
    for (long long i = 0; i<N; i++)
    {
        if (seq[i] == memo)
            counter++;
        else
        {
            if (counter >= memo)
                final += (counter-memo);
            else
                final += counter;
            memo = seq[i];
            counter = 1;
        }
    }
    if (counter >= memo)
        final += (counter-memo);
    else
        final += counter;
    cout << final << endl;
    return 0;
}