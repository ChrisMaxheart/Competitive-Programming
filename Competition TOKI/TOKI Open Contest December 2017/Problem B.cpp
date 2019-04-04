#include <bits/stdc++.h>
using namespace std;

// way[x][y]: banyak cara beli x-permen dgn y-manis
int way[50][1000];
int nPermen, nBeli, k, x;

int main() {

    // way[0][0] = 1 cukup obv., gabeli apa-apa itu suatu cara
    way[0][0] = 1;

    scanf("%d%d%d", &nPermen, &nBeli, &k);

    while(nPermen--) {
        scanf("%d", &x);

        // diseret dari kanan ke kiri
        // biar gabisa beli permen yang sama berkali"
        // (Intro to DP flying table)
        for (int i = nBeli; i > 0; i--)
            // at most total manis yang bakal lw beli cuma 10 x 50 = 500
            for (int j = x; j <= 500; j++)
                // banyaknya cara beli i-permen dgn j-manis,
                // ditambah dengan banyaknya cara beli (i-1)-permen (j-x)-manis
                // terus beli permen dengan manis x
                way[i][j] += way[i - 1][j - x];
    }

    // Bagian ini obvious
    int tot = 0, sol = 500;
    while (tot + way[nBeli][sol] < k)
        tot += way[nBeli][sol--];
    printf("%d\n", sol);

    // O(nBeli * nPermen * (nBeli * maxManisPerPermen))
    // O(nBeli^2 * nPermen * maxManisPerPermen)
}
