#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <complex>
#include <list>
#include <array>
#include <set>
using namespace std;

typedef long double ld;
typedef complex<ld> Pnt;
typedef array<int, 2> Edge;
typedef array<int, 3> Tri;
typedef pair<Pnt, ld> Circ;
const ld oo = 1e9;
const ld eps = 1e-6;
int n;

Circ compute_circumcircle(Pnt a, Pnt b, Pnt c) {
  b -= a;
  c -= a;
  auto center = (b*norm(c)-c*norm(b)) / (b*conj(c)-c*conj(b));
  return {center+a, norm(center)};
}

vector<Tri> delaunay(vector<Pnt> pnts) {
  pnts.push_back({-oo, -oo});
  pnts.push_back({oo, -oo});
  pnts.push_back({oo, oo});
  pnts.push_back({-oo, oo});
  list<pair<Tri, Circ>> tcs;
  tcs.push_back({{n, n+1, n+2}, {0, 2*oo*oo}});
  tcs.push_back({{n+2, n+3, n}, {0, 2*oo*oo}});
  for (int i = 0; i < n; i++) {
    set<Edge> edges;
    for (auto it = begin(tcs); it != end(tcs); ) {
      auto circ = it->second;
      ld d = norm(pnts[i] - circ.first) - circ.second;
      if (d < -eps) {
        auto tri = it->first;
        auto j = *prev(end(tri));
        for (int k: tri) {
          auto ite = edges.find({k, j});
          if (ite == end(edges)) {
            edges.insert({j, k});
          } else {
            edges.erase(ite);
          }
          j = k;
        }
        it = tcs.erase(it);
      } else {
        it++;
      }
    }
    int j0 = (*begin(edges))[0];
    for (int j = j0; ; ) {
      int k = (*edges.lower_bound({j, 0}))[1];
      Circ circ = compute_circumcircle(pnts[i], pnts[j], pnts[k]);
      tcs.push_back({{i, j, k}, circ});
      j = k;
      if (j == j0) break;
    }
  }
  vector<Tri> tris;
  for (auto& tc: tcs) {
    auto& tri = tc.first;
    bool flag = false;
    for (int j: tri) {
      flag = flag || j >= n;
    }
    if (flag) continue;
    tris.push_back(tri);
  }
  return tris;
}
