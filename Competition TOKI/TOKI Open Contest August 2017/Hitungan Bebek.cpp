#include <bits/stdc++.h>

using namespace std;

struct segalanya
{
	long long nilai, posisi;
};

segalanya pohon[100010];
long long i, N, Q, Left, Right, store, lokasi, angka, urutan;

bool urut(segalanya a, segalanya b)
{
	return a.nilai < b.nilai;
}

int main ()
{
	scanf("%lld %lld", &N, &Q);
	for(i=1; i<=N; i++)
	{
		scanf("%lld", &pohon[i].nilai);
		pohon[i].posisi = i;
	}
	stable_sort(pohon, pohon+N+1, urut);
	pohon[N+1].nilai = 100001;
	for(i=0; i<Q; i++)
	{
		scanf("%lld %lld", &Left, &Right);
		lokasi = 0;
		angka = 1;
		urutan = Left;
		while (lokasi <= N)
		{
			lokasi++;
			if ((pohon[lokasi].nilai == angka) && (pohon[lokasi].posisi >= urutan))
			{
				angka++;
				if (pohon[lokasi].posisi > Right)
				{
					printf("%d\n", (angka-2));
					break;
				}
				urutan = pohon[lokasi].posisi;
			}
			else if (pohon[lokasi].nilai > angka)
			{
				printf("%d\n", (angka-1));
				break;
			}
		}
	}
	return 0;
}