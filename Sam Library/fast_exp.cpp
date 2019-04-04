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