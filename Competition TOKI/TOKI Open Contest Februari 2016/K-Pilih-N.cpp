#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
	int N, K; 
	long j, y;
	long x [1000];
	for(int i=0; i<1000; i++) x[i]=0;
	scanf("%d %d", &N, &K);
	if (K==1) printf("0\n");
	else
	{
		for (int i = 0; i<N; i++) scanf("%ld", &x[i]);
		sort(x, x+N);
		j=0;
		y=1000000001;
		while(x[j+K-1]<x[j]) K--;
		while(x[j+K-1]>=x[j])
		{
				if ((x[j+K-1]-x[j])<y) y=(x[j+K-1]-x[j]);
				j++;
				if (((x[j+K-1])==0) && ((x[j+K-2])!=0)) break;
		}
		printf("%ld\n", y);
		
	}
}