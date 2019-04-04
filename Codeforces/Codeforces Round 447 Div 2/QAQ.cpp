#include <bits/stdc++.h>

using namespace std;

string x;
vector<int> memoQ;
vector<int> memoA;
int leng, i, counta, qsize, asize, j, k;

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> x;
    leng = x.length();
    for(i=0; i<leng; i++)
    {
        if (x[i]==81) memoQ.push_back(i);
        else if (x[i]== 65) memoA.push_back(i);
    }
    counta = 0;
    qsize = memoQ.size();
    asize = memoA.size();
    for(i =0; i<qsize; i++)
    {
        for(j=0; j<asize; j++)
        {
            for(k=i+1; k<qsize; k++)
            {
                if ((memoA[j] > memoQ[i]) && (memoQ[k]>memoA[j])) counta++;
            }
        }
    }
    cout << counta << endl;
    return 0;
}