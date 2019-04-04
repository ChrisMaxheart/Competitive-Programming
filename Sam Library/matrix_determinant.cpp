#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

#define MOD 1000000007
vector<vi> val;
int n;

const ll mod = ll(MOD);

ll fastpow(ll base, ll exp) {
    if (exp == 1) {
        return base % mod;
    } else if (exp == 2) {
        return ((base % mod) * (base % mod)) % mod;
    } else {
        if (exp%2) {
            ll dum = fastpow(base, exp-1) % mod;
            ll dum2 = (base * dum) % mod;
            // cout << dum << " kali " << base << " samadengan " << dum2 << endl;
            return dum2;
        } else {
            ll dum = fastpow(base, exp/2) % mod;
            ll dum2 = (dum * dum) % mod;
            // cout << dum << " kali " << dum << " samadengan " << dum2 << endl;
            return dum2; 
        }
    }
}



int getDeterminant() {
    int ret = 1;
    for (int i = 0; i < n; ++i) {
        int piv = i;
        while(piv < n && !val[piv][i]) {
            piv++;
        }
        if (piv == n) {
            return 0;
        }
        if (piv != i) {
            swap(val[i], val[piv]);
            if (ret) {
                ret = (mod - ret);
            }
        }
        for (int j = i+1; j < n; j++) {
            if (val[j][i]) {
                int mtp = 1LL * val[i][j] * fastpow(ll(val[i][i]), mod-2)%mod;
                for (int k = i; k < n; k++) {
                    val[j][k] = (val[j][k] - 1LL * val[i][k] * mtp % mod + mod) % mod;
                }
            }
        }
        ret = (1LL * ret * val[i][i]) % mod;
    }
    return ret;
}