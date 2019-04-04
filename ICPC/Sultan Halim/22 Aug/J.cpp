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
    int x, y;
    cin >> x >> y;
    int ans = y - x;
    if (ans > 180) {
        ans -= 360;
    }
    if (ans <= -180) {
        ans += 360;
    }

    cout << ans << "\n";
}
