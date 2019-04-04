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

int lis(vi arr) {
    int len = arr.size();
    vi temp;

    for (int i = 0; i < len; ++i) {
            temp.pb(1);
            for (int j = 0; j < i; ++j) {
                if (arr[j] < arr[i]) {
                    temp[i] = max(temp[i], temp[j] + 1);
                }
            }
    }

    int ans = 1;
    for (int i = 0; i < len; ++i) {
        ans = max(ans, temp[i]);
    }

    return ans;
}

int main() {
    vector<string> lst;
    lst.pb("c");
    lst.pb("h");
    lst.pb("s");
    lst.pb("d");
    sort(lst.begin(), lst.end());
    map<string, int> mymap, mymap2;
    for (int i = 1; i <= 10; i++) {
        string x = "";
        x += ('0'+i);
        mymap[x] = i;
    }
    mymap["T"] = 10;
    mymap["J"] = 11;
    mymap["Q"] = 12;
    mymap["K"] = 13;
    mymap["A"] = 14;
    for (auto x : mymap) {
        mymap2[x.first] = 15 - x.second;
    }
    //for (auto x : mymap) {
    //    cout << x.first << " " << x.second << endl;
    //}
    //cout << mymap["8"] << endl;
    vector<string> inp;
    int N;
    cin >> N;
    //cout << N << endl;
    for (int i = 0; i < N; i++) {
        string x;
        cin >> x;
        inp.pb(x);
    }
    int mini = 1E9;
    do {
        for (int i = 0; i < 4; i++) {
            mymap[lst[i]] = i * 100;
            mymap2[lst[i]] = i * 100;
        }
        for (int q = 0; q < 16; q++) {
                vi inp2;
                for (int i = 0; i < N; i++) {
                    char xx = inp[i][0];
                    char yy = inp[i][1];
                    string x = "";
                    string y = "";
                    x += xx;
                    y += yy;
                    int curri = mymap[y];
                    if (y == "s") {
                        if (q % 2) {
                            curri += mymap2[x];
                        } else {
                            curri += mymap[x];
                        }
                    } else if (y == "d") {
                        if (1 << 1 & q) {
                            curri += mymap2[x];
                        } else {
                            curri += mymap[x];
                        }
                    } else if (y == "h") {
                        if (1 << 2 & q) {
                            curri += mymap2[x];
                        } else {
                            curri += mymap[x];
                        }
                    } else {
                        if (1 << 3 & q) {
                            curri += mymap2[x];
                        } else {
                            curri += mymap[x];
                        }
                    }
                    inp2.pb(curri);
                }
                int counter = 0;
                int swit = 0;
                swit = N - lis(inp2);
                mini = min(mini, swit);
        }
    } while (next_permutation(lst.begin(), lst.end()));
    cout << mini << endl;
    return 0;
}
