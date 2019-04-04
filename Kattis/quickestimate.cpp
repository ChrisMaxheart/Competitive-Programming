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

    int N;
    string cost;

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> cost;
        cout << cost.length() << endl;
    }

    return 0;
}