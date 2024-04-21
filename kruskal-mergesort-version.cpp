#include "kruskal.hpp"


WeightedEdge* Kruskal::merge(WeightedEdge* a, WeightedEdge* b) {
    WeightedEdge d; WeightedEdge* c = &d;
    while (a != nullptr && b != nullptr) {
        if (b->wt > a->wt) {
            c->next = a; a = a->next; c = c->next;
        } else {
            c->next = b; b = b->next; c = c->next;
        }
    }
    c->next = (a == nullptr) ? b:a;
    return d.next;
}

WeightedEdge* Kruskal::mergesort(WeightedEdge* h) {
    if (h == nullptr || h->next == nullptr)
        return h;
    WeightedEdge *fast = h->next->next, *slow = h;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    WeightedEdge *front = h, *back = slow->next;
    slow->next = nullptr;
    return merge(mergesort(front), mergesort(back));
}

WeightedEdge* Kruskal::sortEdges(Graph& G) {
    WeightedEdge* toSort = G.edges().get();
    return mergesort(toSort);
}

Kruskal::Kruskal(Graph& G) {
    DisjointSet djs(G.V());
    int i = 1;
    for (WeightedEdge* edge = sortEdges(G); edge != nullptr; edge = edge->next) {
        int from = edge->v, to = edge->u;
        if (!djs.equal(from, to)) {
            djs.merge(from, to);
            mstEdges.push_back(make_pair(from, to));
            if (mstEdges.size() == G.V()-1)
                return;
        }
    }
}

vector<pair<int,int>>& Kruskal::MST() {
    return mstEdges;
}