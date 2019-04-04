#include <bits/stdc++.h>

using namespace std;

int n, x, i, counter, z;
int bil[110];

int main ()
{
	scanf("%d %d", &n, &x);
	for (i=0; i<n; i++) 
		{
			scanf("%d", &z);
			bil[z]++;
		}
	counter = 0;
	for (i=0; i<=x; i++)
	{
		if ((bil[i]==0) && (i != x))
		{
			counter++;
			bil[i]++;
		}
	}
	if (bil[x] != 0)
	{
		bil[x]++;
		counter++;
	}
	printf("%d\n", counter);
	return 0;
}