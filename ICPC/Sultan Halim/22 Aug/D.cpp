#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second

int main() {
    ll N;
    cin >> N;

    vi lst;
    for (ll i = 0; i < N; i++) {
        ll x;
        cin >> x;
        lst.pb(x);
    }

    ll money = 100;
    for (ll i = 1;i < N; i++) {
        if (lst[i] > lst[i-1]) {
            if (money/lst[i-1] > 100000) {
                money -= (lst[i-1]*100000);
                money += (lst[i]*100000);
            } else {
                ll share = money/lst[i-1];
                money -= (share * lst[i-1]);
                money += (share * lst[i]);
            }
        }
    }
    cout << money << endl;
}
