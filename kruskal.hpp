#ifndef kruskal_hpp
#define kruskal_hpp
#include <vector>
#include <queue>
#include "graph.hpp"
#include "disjointset.hpp"
using namespace std;

class CompEdge {
    public:
        bool operator()(WeightedEdge* lhs, WeightedEdge* rhs) {
            return lhs->wt > rhs->wt;
        }
};

class Kruskal {
    private:
        priority_queue<WeightedEdge*, vector<WeightedEdge*>, CompEdge> pq;
        vector<pair<int,int>> mstEdges;
        void sortEdges(Graph& G);
    public:
        Kruskal(Graph& G);
        vector<pair<int,int>>& MST();
};

#endif