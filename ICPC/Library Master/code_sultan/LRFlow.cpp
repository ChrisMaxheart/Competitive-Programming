#include "Dinic.cpp"

//Construct : LRFlow(int N, int originalSource, int originalSink)
//Add Edge : LRFlow.addEdge(int from, int to, F lowerBound, F upperBound) []
//Solve: LRFlow.calcLRFlow()
// {{{ LR FLow<F=int, MF=DinicMaxFlow<F>>
template<typename F = int, typename MF = DinicMaxFlow<F>>
struct LRFlow {
  MF mf;
  F lowerBoundSum = 0;
  int n, realSource, realSink;

  LRFlow(int n, int src, int snk) : mf(n + 2), n(n + 2) {
    realSource = this->n - 2;
    realSink = this->n - 1;
    mf.addEdge(snk, src, mf.INF_FLOW);
  }

  void addEdge(int from, int to, F lowerBound, F upperBound) {
    assert(lowerBound <= upperBound);
    lowerBoundSum += lowerBound;
    mf.addEdge(from, to, upperBound - lowerBound);
    mf.addEdge(realSource, to, lowerBound);
    mf.addEdge(from, realSink, lowerBound);
  }

  pair<F, bool> calcLRFlow() {
    F maxFlow = mf.calcMaxFlow(realSource, realSink);
    return make_pair(maxFlow, maxFlow == lowerBoundSum);
  }
};
// }}}
