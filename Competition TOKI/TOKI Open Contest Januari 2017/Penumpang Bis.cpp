#include <bits/stdc++.h>

using namespace std;

int N, i, masuk, keluar;
long long jumlah, lama, terlama;

int main ()
{
	scanf("%d", &N);
	jumlah = 0;
	for(i=0; i<N; i++)
	{
		scanf("%d %d", &masuk, &keluar);
		if (jumlah != 0) lama++;
		jumlah = jumlah - keluar;
		if (terlama < lama) terlama = lama;
		if (jumlah == 0) lama = 0;
		jumlah = jumlah + masuk;
	}
	terlama = terlama * 10;
	printf("%lld\n", terlama);
	return 0;
}