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
    double r, n;

    cin >> r >> n;

    double maxi = r/n;
    double maxi1 = floor(maxi);
    double maxi2 = ceil(maxi);
    cout << maxi1 << endl;
    cout << maxi2 << endl;
    double ans1 = maxi1 / (maxi1+r) * pow(1-maxi1/(maxi1+r), n-1) * n;
    double ans2 = maxi2 / (maxi2+r) * pow(1-maxi2/(maxi2+r), n-1) * n;
}
