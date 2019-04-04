#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool reversecompare(int a, int b)
{
  return a > b;
}

struct newchar
{
    char strng[20];
    char newstrng[20];
    string final = "";
};

bool newcompare(newchar a, newchar b)
{

    return a.final < b.final;
}

int main ()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int r, c, dummy;
  newchar x[20];

  while(true)
  {
    cin >> r >> c;
    // cout << r << c << endl;
    if (!(r||c))
    {
        return 0;
    }
    else
    {
        for (int i = 0; i < c; i++)
            x[i].final = "";
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                cin >> x[j].strng[i];
            }
        }
        for (int i = 0; i < c; i++)
        {
            for (int j = 0; j < r; j++)
            {
                if (int(x[i].strng[j]) < 96)
                    x[i].final += char(int(x[i].strng[j])+32);    
                else
                    x[i].final += x[i].strng[j];
            }
        }
        stable_sort(x, x+c, newcompare);
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                cout << x[j].strng[i];
            }
            cout << endl;
        } 
        cout << endl;
    }
  }

  return 0;
}