#include <bits/stdc++.h>

using namespace std;

string comnd;
int N, l, r, u, d, total, i;

int main ()
{
	cin >> N;
	cin >> comnd;
	l = 0;
	r = 0;
	u = 0;
	d = 0;
	total = 0;
	for (i =0; i<N; i++)
	{
		if (comnd[i] == 76) l++;
		else if (comnd[i] == 82) r++;
		else if (comnd[i] == 85) u++;
		else d++;
	}
	total = 2*(min(l, r) + min(u, d));
	cout << total << endl;
	return 0;
}