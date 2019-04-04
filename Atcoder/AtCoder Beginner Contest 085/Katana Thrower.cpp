#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool reversecompare(int a, int b)
{
    return a > b;
}

struct katana
{
    ll nom;
    ll wi;
    ll th;
};

bool bandingwi(katana a, katana b)
{
    return a.wi > b.wi;
}

bool bandingth(katana a, katana b)
{
    return a.th > b.th;
}

bool bandingthbalik(katana a, katana b)
{
    return a.th < b.th;
}


int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    katana pedang [100010];
    ll N, H, counta, counter;
    katana dummy;

    cin >> N >>H;

    for(int i = 0; i < N; i++)
    {
        pedang[i].nom = i;
        cin >> pedang[i].wi >> pedang[i].th;
    }

    stable_sort(pedang, pedang+N, bandingthbalik);
    stable_sort(pedang, pedang+N, bandingwi);

    dummy = pedang[0];
    counta = 0;
    counter = 0;

    stable_sort(pedang, pedang+N, bandingth);

    while(H > 0)
    {
        if (dummy.th >= H)
        {
            counta++;
            H -= dummy.th;
        }
        else
        {
            if (counter >= N)
            {
                H -= dummy.wi;
                counta++;
            }
            else if (pedang[counter].nom == dummy.nom)
            {
                counter++;
            }
            else if (dummy.wi >= pedang[counter].th)
            {
                H -= dummy.wi;
                counta++;
            }
            else
            {
                H -= pedang[counter].th;
                counter++;
                counta++;
            }
        }
    }

    cout << counta << endl;


    return 0;
}