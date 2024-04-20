#ifndef app_hpp
#define app_hpp
#include <iostream>
#include <vector>
#include <cmath>
#include <SFML/Graphics.hpp>
#include "graph.hpp"
#include "kruskal.hpp"
using namespace std;

struct Point {
    int x, y;
    Point(int X = 0, int Y = 0) : x(X), y(Y) { }
};

int distance(Point a, Point b);

struct Vertex {
    Point _pos;
    int id;
    Vertex(int _id = 0, Point _p = {0,0}) {
        id = _id;
        _pos = _p;
    }
    Point& pos() {
        return _pos;
    }
};

class App {
    private:
        int w;
        int h;
        sf::RenderWindow* window;
        sf::RenderTexture* texture;
        Graph G;
        vector<Vertex> verts;
        vector<pair<int,int>> mstEdges;
        bool showEdges;
        bool showMST;
        void handleKeyStrokes(sf::Event event);
        void drawGraph();
        void buildGraph(int nv);
        void render();
        sf::VertexArray makeLine(Point from, Point to, sf::Color a, sf::Color b);
    public:
        App(int nv = 15);
        void start();
};

#endif