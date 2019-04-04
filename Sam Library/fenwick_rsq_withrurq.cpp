#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

//Fenwick, 1-based iirc
#define LSOne(S) ((S)&(-S))
class FenwickTree {
private:
    vi ft;
    int n;

public:
    FenwickTree(int _n) : n(_n) {
        ft.assign(n+1, 0);
    }
    FenwickTree(const vector<int>& f) : n(f.size()-1) {
        ft.assign(n+1, 0);
        for(int i = 1; i <= n; i++) {
            ft[i] += f[i];
            if(i+LSOne(i) <= n) {
                ft[i+LSOne(i)] += ft[i];
            }
        }
    }
    int rsq(int j) {
        int sum = 0;
        for (; j; j-= LSOne(j)) {
            sum += ft[j];
        }
        return sum;
    }
    int rsq(int i, int j) {
        return rsq(j) - rsq(i-1);
    }
    void update(int i, int v) {
        for (; i <= n; i += LSOne(i)) {
            ft[i] += v;
        }
    }
};

//RURQ Fenwicktree, need the fenwick tree code also
class RURQFenwickTree {
private:
    int n;
    FenwickTree FTA, FTB;

public:
    RURQFenwickTree(int _n) : FTA(_n), FTB(_n), n(_n) { }
    void update(int l, int r, int v) {
        FTA.update(l, v);
        FTA.update(r+1, -v);
        FTB.update(l, (l-1) * v);
        FTB.update(r+1, -r*v);
    }
    int rsq(int j) {
        return FTA.rsq(j) * j - FTB.rsq(j);
    }
    int rsq(int i, int j) {
        return rsq(j) - rsq(i-1);
    }
};