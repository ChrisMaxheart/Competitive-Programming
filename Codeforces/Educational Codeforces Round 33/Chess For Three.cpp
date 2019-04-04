#include <bits/stdc++.h>

using namespace std;

int N, x, spec, i, dummy;
bool mungkin;
int arr[3];



int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    arr[0] = 1;
    arr[1] = 2;
    spec = 3;
    mungkin = true;
    for(i=0; i<N; i ++)
    {
        cin >> x;
        if (x == spec)
        {
            mungkin = false;
            break;
        }
        else
    	{
            dummy = spec;
            if (x==arr[0])
            {
                spec = arr[1];
                arr[1] = dummy;
            }
            else
            {
                spec = arr[0];
                arr[0] = dummy;
            }

        }
    }
    if (mungkin)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}