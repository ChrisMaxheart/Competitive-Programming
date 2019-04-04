#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <map>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

int i, j, k, l;
long long ang[1500];
long long bd[1500];
int n, ambr;	
long long vmn;
int main()
{
	vmn = (long long)((double) 10e+18);
	scanf("%d%d", &n, &ambr );

	for ( i = 1; i <= n; i++)
	{
		scanf("%lld", &ang[i] );
	}

	sort(ang+1, ang+n+1);
	for ( i = 1; i <= n- ambr+1; i++)
	{
		vmn = min(vmn, abs(ang[i] - ang[i+ambr-1] ));
	}
	printf("%lld\n", vmn);

	return 0;
}