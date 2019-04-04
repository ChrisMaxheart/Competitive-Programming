#include <bits/stdc++.h>

using namespace std;



int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    int x, y, countx, county, cond, counta;
    int countxt [8010];
    int countyt [8010];
    long long totalx, totaly, deltax, deltay, temptotal;
    bool xfound, yfound, absolutefalse;

    cin >> s;
    cin >> x >> y;
    absolutefalse = false;
    counta = 0;
    countx = 0;
    county = 0;
    cond = 0;
    xfound = false;
    yfound = false;
    for(int i = 0; i< s.length();i++)
    {
        if(s[i] == 'T')
        {
            if (counta != 0)
            {
                if (cond == 0)
                {
                    countxt[countx] = counta;
                    countx++;
                }
                else
                {
                    countyt[county] = counta;
                    county++;
                }
                
            }
            cond = (cond+1)%2;
            counta = 0;
        }
        else
            counta++;
    }
    if (counta != 0)
    {
        if (cond == 0)
        {
            countxt[countx] = counta;
            countx++;
        }
        else
        {
            countyt[county] = counta;
            county++;
        }
        cond = (cond+1)%2;
        counta = 0;
    }    
    totalx = 0;
    totaly = 0;
    for(int i = 0; i < countx; i++)
        totalx += countxt[i];
    for(int i = 0; i < county; i++)
        totaly += countyt[i];
    deltax = (totalx - x);
    deltay = (totaly - y);
    if ((deltax%2 != 0)||(deltax < 0))
        absolutefalse = true;
    else
        deltax = deltax/2;
    if((deltay%2 != 0)||(deltay < 0))
        absolutefalse = true;
    else
        deltay = deltay/2;

    if (absolutefalse)
        cout << "No" << endl;
    else
    {
        if ((deltax == 0) && (deltay == 0))
            cout << "Yes" << endl;
        else
        {
            if(deltax ==0) xfound = true;
            else if (deltay == 0) yfound = true;
            for(int i = 1; i <= countx ; i++)
            {

                for(int j = 0; j < countx+1-i;j++)
                {
                    temptotal = 0;
                    for(int k = 0; k<i; k++)
                    {
                        temptotal += countxt[j+k];
                    }
                    if (temptotal == deltax)
                    {
                        xfound = true;
                        break;
                    }
                }
                if (xfound)
                    break;
            }

            for(int i = 1; i <= county ; i++)
            {

                for(int j = 0; j < county+1-i;j++)
                {
                    temptotal = 0;
                    for(int k = 0; k<i; k++)
                    {
                        temptotal += countyt[j+k];
                    }
                    if (temptotal == deltay)
                    {
                        yfound = true;
                        break;
                    }
                }
                if (yfound)
                    break;
            }

            if (xfound && yfound)
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
    }

    return 0;
}