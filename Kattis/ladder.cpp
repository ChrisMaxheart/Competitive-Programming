#include <bits/stdc++.h>

using namespace std;

#define PI 3.141592653

typedef long long ll;

bool reversecompare(int a, int b)
{
    return a > b;
}

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double height, angle, ans;
    int final;

    cin  >> height >> angle;
    ans = height/sin((angle/180) * PI);
    final = ceil(ans);
    cout << final << endl;

    return 0;
}