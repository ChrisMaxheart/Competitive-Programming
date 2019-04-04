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

    int N, save;
    string message, final;
    int panjang;
    char dummy;

    cin >> N;

    while(N--)
    {
        cin >> message;
        panjang = message.length();
        for (int i = 1; i <101; i++)
            if (i*i >= panjang)
            {
                save = i;
                break;
            }
        while(message.length() != (save*save))
            message += "*";
        final = "";
        for (int i = 1; i <= save; i++)
            for (int j = 1; j<= save; j++)
            {
                dummy = message[(save*(save-j)) + (i-1)];
                if (dummy == '*')
                    continue;
                else
                    final += dummy;
            }
        cout << final << endl;

    }

    return 0;
}