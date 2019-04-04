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

    int t, n, pointer;
    string dummy;

    string memo[101];
    cin >> t;
    for (int i = 0; i < t; i ++)
    {
        cin >> n;
        pointer = 1;
        for (int j = 0; j < n; j ++)
        {
            if (j == 0)
                cin >> memo[0];
            else
            {
                cin >> dummy;
                stable_sort(memo, memo+pointer);
                if (binary_search(memo, memo+pointer, dummy))
                    continue;
                else
                {
                    memo[pointer] = dummy;
                    pointer++;
                }
            }
        }
        cout << pointer << endl;
    }

    return 0;
}