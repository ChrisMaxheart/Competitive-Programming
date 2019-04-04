#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool reversecompare(int a, int b)
{
    return a > b;
}

ll move(ll posisi, char command)
{
    if (int(command) == 78)
        return (posisi - 1000);
    else if (int(command) == 83)
        return (posisi + 1000);
    else if (int(command) == 69)
        return (posisi + 1);
    else if (int(command) == 87)
        return (posisi - 1);
    else if (int(command) == 84)
        return 9875;
}

bool validity(ll posisi, ll baris, ll kolom)
{
    if (posisi < 0)
        return false;
    else if (posisi%1000 > 200)
        return false;
    else if (posisi%1000 >= kolom)
        return false;
    else if (posisi/1000 >= baris)
        return false;
    else
        return true;
}

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll r, c, posisi, pointer, counter;
    bool correct;
    char peta [300][300];
    bool memo [400010];

    cin >> r >> c;
    for(ll i = 0; i < r; i++)
        for(ll j = 0; j < c; j++)
            cin >> peta[i][j];
    posisi = 0;
    correct = true;
    pointer = 0;
    counter = 0;
    for (int i = 0; i < 400000; i++)
        memo[i] = true;
    while (correct)
    {
        if (memo[posisi] == false)
        {
            cout << "Lost" << endl;
            correct = false;
        }
        memo[posisi] = false;
        posisi = move(posisi, peta[posisi/1000][posisi%1000]);
        if (posisi == 9875)
        {
            cout << counter << endl;
            break;
        }
        else
        {
            if (!validity(posisi, r, c))
            {
                correct = false;
                cout << "Out" << endl;
            }
        }
        counter++;

    }

    return 0;
}