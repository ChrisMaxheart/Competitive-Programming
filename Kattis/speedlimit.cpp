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
    int N, total, deltatime;
    int time[11];
    int speed[11];
    for (int i = 0; i < 10; i++)
    {
        cin >> N;
        if (N == -1)
            break;
        else
        {
            for (int j = 0; j < N; j++)
                cin >> speed[j] >> time[j];
            total = 0;
            for (int j = 0; j <N; j++)
            {
                if (j == 0)
                    deltatime = time[j];
                else
                    deltatime = time[j] - time[j-1];
                total += speed[j] * deltatime;
            }
            cout << total << " miles" << endl;
        }
    }

    return 0;
}