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

    ll tree[100010];
    ll N, highest;

    cin >> N;
    for (int i = 0; i <N; i++)
        cin >> tree[i];
    stable_sort(tree, tree+N, reversecompare);
    highest = 0;
    for (int i = 0; i<N; i++)
        if (tree[i]+i > highest)
            highest = tree[i]+i;
    cout << highest +2 << endl;

    return 0;
}