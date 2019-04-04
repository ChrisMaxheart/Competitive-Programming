#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int, bool>>> AL; // the second elem is a bool, true = edge can still be used, false = not.

list<int> cyc;

void EulerTour(list<int>::iterator i, int u) {
    for (auto &v: AL[u]) {
        if (v.second) {
            v.second = false;
            for (auto &uu: AL[v.first]) {
                if (uu.first == u && uu.second) {
                    uu.second = false;
                    break;
                }
            }
            EulerTour(cyc.insert(i, u), v.first);
        }
    }
}

/*
    Usage sample
    In int main

    cyc.clear();
    EulerTour(cyc.begin(), A); // cyc contains an Euler tour starting at A
    for (auto &it: cyc) { // printing the answer
        cout << it << endl;
    }

 */