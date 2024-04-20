#ifndef graph_hpp
#define graph_hpp

struct WeightedEdge {
    int v;
    int u;
    int wt;
    WeightedEdge* next;
    WeightedEdge(int from = 0, int to = 0,int weight = 0, WeightedEdge* n = nullptr) {
        v = from;
        u = to;
        wt = weight;
        next = n;
    }
    bool operator==(const WeightedEdge& we) const {
        return (v == we.v && u == we.u) || (v == we.u && u == we.v);
    }
    bool operator!=(const WeightedEdge& we) const {
        return !(*this==we);
    }
};

class edgeIterator {
    private:
        using link = WeightedEdge*;
        link curr;
    public:
        edgeIterator(link start = nullptr) : curr(start) { }
        WeightedEdge* get() {
            return curr;
        }
        bool end() {
            return curr == nullptr;
        }
        void next() {
            curr = curr->next;
        }
};

class Graph {
    private:
        using node = WeightedEdge;
        using link = node*;
        link *adjlist;
        link edgelist;
        int nv;
        int ne;
        link addToAdjList(int from, int to, int wt);
        link addToEdgeList(int from, int to, int wt);
        void init(int sz);
    public:
        Graph(int numvertex = 5);
        Graph(const Graph& g);
        void addEdge(int from, int to, int wt);
        bool hasEdge(int from, int to);
        int V() const;
        int E() const;
        edgeIterator adj(int vertex);
        void clear();
        Graph& operator=(const Graph& g);
        edgeIterator edges();
};

#endif