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

    bool location[103];
    bool check;
    int N, M, a, b;


    for (int i = 0; i < 103; i++)
        location[i] = false;

    cin >> N >> M;
    for(int i = 0; i<N ; i++)
    {
        cin >> a >> b;
        for (int j = a; j<b; j++)
            location[j] = true;
    }

    check = true;

    for(int i = 0; i< M; i++)
        check = check && location[i];

    if (check == true)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}