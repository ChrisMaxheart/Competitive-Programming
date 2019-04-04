#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <map>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

struct peduli
{
	long long idx, num;
};
int i, j, k, l;
int nAng;
long long lan[15];
peduli asl[15];
int trkhir;

bool cmp(peduli a, peduli b)
{
	return a.num< b.num;
}
int main()
{
	scanf("%d", &nAng );

	for ( i = 0; i <= nAng-1; i++)
	{
		scanf("%lld", &lan[i] );
	}

	asl[0].num = 0;
	trkhir = 0;
	for ( i = 1; i <= nAng-1; i++)
	{
		asl[(trkhir + 5) % nAng].num = asl[trkhir].num + lan[(trkhir+1)%nAng] - lan[trkhir];
		trkhir +=5;
		trkhir %=nAng;
	}

	for ( i = 0; i <= nAng-1; i++)
	{
		asl[i].idx = i;
	}

	sort(asl,asl+nAng,cmp);
	printf("%lld", asl[0].idx);
	for ( i =1; i <= 4; i++)
	{
		printf(" %lld", asl[i].idx);
	}

	printf("\n");
	return 0;
}