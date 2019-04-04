#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool reversecompare(int a, int b)
{
    return a > b;
}

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string moves;
    int posisi, i;

    cin >> moves;
    posisi = 1;
    for (i = 0; i < moves.length(); i++)
    {
        if (int(moves[i]) == 65)
        {
            if (posisi == 1)
                posisi = 2;
            else if (posisi == 2)
                posisi = 1;
        }
        else if (int(moves[i]) == 66)
        {
            if (posisi == 3)
                posisi = 2;
            else if (posisi == 2)
                posisi = 3;
        }
        else
        {
            if (posisi == 1)
                posisi = 3;
            else if (posisi == 3)
                posisi = 1;
        }
    }
    cout << posisi << endl;

    return 0;
}