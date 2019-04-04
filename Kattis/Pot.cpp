#include <bits/stdc++.h>

using namespace std;

int N, final, i, x, power;

int main ()
{
	scanf("%d", &N);
	final = 0;
	for (i = 0; i<N; i++)
	{
		scanf("%d", &x);
		power = x % 10;
		x = x / 10;
		final = final+(pow(x, power));
	}
	printf("%d\n", final);
	return 0;
}