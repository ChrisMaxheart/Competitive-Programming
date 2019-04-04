#include <bits/stdc++.h>

using namespace std;

int arr[1010];
int N, i, counts;
bool mini, maxi;

int main ()
{
	scanf("%d", &N);
	for (i = 0; i < N; i++) scanf("%d", &arr[i]);
	counts = 0;
	for (i= 1; i < N-1; i++)
	{
		mini = false;
		maxi = false;
		if ((arr[i]>arr[i+1]) &&(arr[i]>arr[i-1]))
			maxi = true;
		if ((arr[i]<arr[i+1]) &&(arr[i]<arr[i-1]))
			mini = true;
		if (mini^maxi) counts++; 
	}
	printf("%d\n", counts);
	return 0;
}