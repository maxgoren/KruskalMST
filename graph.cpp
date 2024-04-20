#include "graph.hpp"

Graph::Graph(int numvertex) {
    init(numvertex);            
}

Graph::Graph(const Graph& g) {
    init(g.nv);
    for (link it = g.edgelist; it != nullptr; it = it->next) {
        addEdge(it->v, it->u, it->wt);
    }
}

void Graph::addEdge(int from, int to, int wt) {
    if (!hasEdge(from, to) && from != to) {
        adjlist[from] = addToAdjList(from, to, wt);
        adjlist[to] = addToAdjList(to, from, wt);
        edgelist = addToEdgeList(from, to, wt);
        ne++;
    }
}

bool Graph::hasEdge(int from, int to) {
    for (auto it = adjlist[from]; it != nullptr; it = it->next) {
        if (to == it->u)
            return true;
    }
    return false;
}

int Graph::V() const {
    return nv;
}

int Graph::E() const {
    return ne;
}

edgeIterator Graph::adj(int vertex) {
    return edgeIterator(adjlist[vertex]);
}

void Graph::clear() {
    for (int i = 0; i < nv; i++) {
        while (adjlist[i] != nullptr) {
            link t = adjlist[i];
            adjlist[i] = adjlist[i]->next;
            delete t;
        }
    }
    delete [] adjlist;
}

Graph& Graph::operator=(const Graph& g) {
    clear();
    init(g.V());
    for (link it = g.edgelist; it != nullptr; it = it->next) {
        addEdge(it->v, it->u, it->wt);
    }
    return *this;
}

edgeIterator Graph::edges() {
    return edgeIterator(edgelist);
}

WeightedEdge* Graph::addToAdjList(int from, int to, int wt) {
    link nn = new node(from, to, wt);
    nn->next = adjlist[from];
    return nn;
}

WeightedEdge* Graph::addToEdgeList(int from, int to, int wt) {
    WeightedEdge* edge = new WeightedEdge(from, to, wt);
    edge->next = edgelist;
    return edge;
}

void Graph::init(int sz) {
    nv = sz;
    edgelist = nullptr;
    adjlist = new link[nv];
    for (int i = 0; i < nv; i++)
        adjlist[i] = nullptr;
}