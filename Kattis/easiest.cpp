#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool reversecompare(int a, int b)
{
    return a > b;
}

int digitscount(ll num)
{
    int final;
    final = 0;
    while (num > 0)
    {
        final += (num%10);
        num /= 10;
    }
    return final;
}

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    bool conti;
    int N, num;

    conti = true;

    while(conti)
    {
        cin >> num;
        if (num == 0)
        {
            conti = false;
        }
        else
        {
            N = digitscount(num);
            // cout << num << endl;
            // cout << N << endl;
            for (int i = 11; i < 101; i++)
                if (digitscount(num*i) == N)
                {
                    cout << i << endl;
                    break;
                }
        }
    }

    return 0;
}