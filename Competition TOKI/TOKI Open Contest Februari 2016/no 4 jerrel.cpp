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
int nQ, pK, Ang;
int ctr;
int lel;
int main()
{
	scanf("%d", &nQ );

	while ( nQ-- )
	{
		ctr = 0;
		scanf("%d%d", &Ang, &pK );
		lel = Ang;
		for ( i = 2; i <= trunc(sqrt(lel)); i++)
		{
			while(Ang % i == 0)
			{
				ctr+=1;
				Ang /=i;
			}
		}	
		if ( Ang > 1 )
		{
			ctr+=1;
		}
		if ( ctr ==  pK )
		{
			printf("Ya\n");		
		}else
		{
			printf("Tidak\n");	
		}
	}
	return 0;
}