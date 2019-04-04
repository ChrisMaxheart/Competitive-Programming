#include <bits/stdc++.h>

using namespace std;

int h1, a1, c1, h2, a2, i, counter;
string order[100000];


int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> h1 >> a1 >> c1;
    cin >> h2 >> a2;
    counter = 0;
    while (h2 > 0)
    {
        
        if((h2 - a1 <= 0) ||(h1 - a2 > 0))
        {
            order[counter] = "STRIKE";
            h2 -= a1;
            h1 -= a2;
        }
        else
        {
            order[counter] = "HEAL";
            h1 += c1;
            h1 -= a2;
        }
        counter++;
    }
    cout << counter << endl;
    for (i=0; i<counter; i++)
        cout << order[i] << endl;
    return 0;
}