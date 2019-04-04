#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

    int permen [55];
    int manis [20];
    int pointer, N, K, P;

bool reversecompare(int a, int b)
{
    return a > b;
}

void recurs(int level, int totalmanis, int starting)
{
    int dummy;
    if (level == 0)
    {
        manis[pointer] = totalmanis;
        pointer++;
        if (pointer >= 11) // jadi dia ga perlu banyak2 space buat tingkat manisnya, 10 cukup, tadinya aku compile error :(
        {
            stable_sort(manis, manis+pointer, reversecompare);
            pointer --;
        }
    }
    else if (starting >= min(K+P, N)) // ini buat buang permen termanis ke K+P and setelahnya, karena cuma butuh permen termanis ke K+P, gabutuh banyak2 max
    {
        dummy = 0; // sebenernya ini cuma buat buang tempat lol, gaada gunanya ini, maksudnya suruh stop aja tanpa melakukan apapun
    }
    else
    {
        for (int i = starting; i<N; i++) // brute force segala kemungkinan manis
            recurs(level-1, totalmanis+permen[i], i+1);
    }
}

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int  i;


    cin >> N >> K >> P;
    for (i=0 ; i<N; i++) // jelas
        cin >> permen[i];
    stable_sort(permen, permen+N, reversecompare);
    pointer = 0;
    recurs(K, 0, 0);
    stable_sort(manis, manis+pointer, reversecompare); 
    cout << manis[P-1] << endl;

    return 0;
}