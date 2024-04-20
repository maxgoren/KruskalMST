#include "disjointset.hpp"

void DisjointSet::makeSet(int i) {
    par[i] = i;
    size[i] = 1;
}

DisjointSet::DisjointSet(int numStart) {
    numSets = numStart;
    N = numSets;
    par = new int[N];
    size = new int[N];
    for (int i = 0; i < N; i++) {
        makeSet(i);
    }
}

DisjointSet::DisjointSet(const DisjointSet& djs) {
    N = djs.N;
    par = new int[N];
    size = new int[N];
    for (int i = 0; i < N; i++) {
        par[i] = djs.par[i];
        size[i] = djs.size[i];
    }
}

DisjointSet::~DisjointSet() {
    delete [] par;
    delete [] size;
}

int DisjointSet::find(int p) {
    while (p != par[p]) {
        par[p] = par[par[p]];
        p = par[p];
    }
    return p;
}

bool DisjointSet::equal(int p, int q) {
    return find(p) == find(q);
} 

void DisjointSet::merge(int p, int q) {
    int rp = find(p);
    int rq = find(q);
    if (rp != rq) {
        if (size[rp] < size[rq])
            swap(rp, rq);
        par[rq] = rp;
        size[rp] += size[rq];
    }
}

DisjointSet& DisjointSet::operator=(const DisjointSet& djs) {
    N = djs.N;
    par = new int[N];
    size = new int[N];
    for (int i = 0; i < N; i++) {
        par[i] = djs.par[i];
        size[i] = djs.size[i];
    }
    return *this;
}