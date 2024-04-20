#include "kruskal.hpp"

void Kruskal::sortEdges(Graph& G) {
    for (edgeIterator it = G.edges(); !it.end(); it.next()) {
        pq.push(it.get());
    }
}

Kruskal::Kruskal(Graph& G) {
    sortEdges(G);
    DisjointSet djs(G.V());
    while (!pq.empty()) {
        int from = pq.top()->v;
        int to = pq.top()->u;
        if (!djs.equal(from, to)) {
            djs.merge(from, to);
            mstEdges.push_back(make_pair(from, to));
        }
        pq.pop();
    }
}

vector<pair<int,int>>& Kruskal::MST() {
    return mstEdges;
}