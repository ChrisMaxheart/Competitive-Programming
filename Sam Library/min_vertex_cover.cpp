#include <bits/stdc++.h>
using namespace std;
vector<vi> memo; // first size is v, second is 2 (with flag)
vi leaf; // size v, 1 if leaf, 0 if not
vector<vi> children; // AL directed graph, parent point to children

int MVC(int v, int flag) {
    int ans = 0;
    if (memo[v][flag] != -1) {
        return memo[v][flag];
    } else if (leaf[v]) { // true if v is a leaf
        ans = flag;
    } else if (flag == 0) {
        ans = 0;
        for (int j = 0; j < children[v].size(); j++) {
            ans += MVC(children[v][j], 1);
        }
    } else if (flag == 1) {
        ans = 1;
        for (int j = 0; j < children[v].size(); j++) {
            ans += min(MVC(children[v][j], 1), MVC(children[v][j], 0))
        }
    }
    return memo[v][flag] = ans;
}