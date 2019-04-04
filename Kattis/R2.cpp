#include <bits/stdc++.h>

using namespace std;

int bil1, mean, bil2 ;

int main ()
{
	scanf("%d %d", &bil1, &mean);
	bil2 = 2 * mean - bil1;
	printf("%d\n", bil2);
	return 0;
}