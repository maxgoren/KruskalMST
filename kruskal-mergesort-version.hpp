#ifndef kruskal_hpp
#define kruskal_hpp
#include <vector>
#include "graph.hpp"
#include "disjointset.hpp"
using namespace std;

class Kruskal {
    private:
        vector<pair<int,int>> mstEdges;
        WeightedEdge* merge(WeightedEdge* a, WeightedEdge* b);
        WeightedEdge* mergesort(WeightedEdge* list);
        WeightedEdge* sortEdges(Graph& G);
    public:
        Kruskal(Graph& G);
        vector<pair<int,int>>& MST();
};

#endif