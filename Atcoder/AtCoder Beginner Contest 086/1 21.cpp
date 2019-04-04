#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool reversecompare(int a, int b)
{
    return a > b;
}

int noofdigit (int a)
{
    int counter = 0;
    if (a == 0)
        return 1;
    else
    {
        while (a > 0)
        {
            a /= 10;
            counter++;
        }
        return counter;
    }
}

int kuadrat [415];

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b, c;

    for (int i = 0; i < 400; i++)
        kuadrat[i] = i*i;

    cin >> a >> b;

    c = a * pow(10,(noofdigit(b))) + b;
    // cout << c << endl;
    if (binary_search(kuadrat, kuadrat + 399, c))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}