#ifndef disjointset_hpp
#define disjointset_hpp
#include <iostream>
using namespace std;

class DisjointSet {
    private:
        int *par;
        int *size;
        int N;
        int numSets;
        void makeSet(int i);
    public:
        DisjointSet(int numStart = 7);
        DisjointSet(const DisjointSet& djs);
        ~DisjointSet();
        int find(int p);
        bool equal(int p, int q);
        void merge(int p, int q);
        DisjointSet& operator=(const DisjointSet& djs);
};

#endif