void removeUndirectedEdge(vector<vi> &AL, int n1, int n2) {
    vi newlst;

    newlst.clear();
    for (auto x: AL[n1]) {
        if (x != n2) {
            newlst.pb(x);
        }
    }
    AL[n1] = newlst;

    newlst.clear();
    for (auto x: AL[n2]) {
        if (x != n1) {
            newlst.pb(x);
        }
    }
    AL[n2] = newlst;
}