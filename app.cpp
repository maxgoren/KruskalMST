#include "app.hpp"

int distance(Point a, Point b) {
    int dx = a.x - b.x;
    int dy = a.y - b.y;
    return sqrt(dx*dx+dy*dy);
}

App::App(int nv) {
    w = 75;
    h = 40;
    buildGraph(nv);
    showEdges = true;
}

void App::buildGraph(int nv) {
    verts.clear();
    for (int i = 0; i < nv; i++) {
        Point next;
        bool unique = false;
        do {
            next = Point((rand() % (w-10+1)+5) * 10, (rand() % (h-5+1)+3) * 10);
            unique = true;
            for (auto m : verts) {
                if (distance(next, m.pos()) < 100) {
                    unique = false;
                    break;
                }
            }
        } while (!unique);
        verts.push_back(Vertex(i, next));
    }
    G = Graph(nv);
    for (int i = 0; i < nv; i++) {
        for (int i = 0; i < nv; i++) {
            if (rand() % 2 == 0) {
                int q = rand() % nv;
                int k = rand() % nv;
                if (q != k) {
                    G.addEdge(q, k, distance(verts[q].pos(), verts[k].pos()));
                }
            }
        }
    }
}

void App::handleKeyStrokes(sf::Event event) {
    switch (event.key.code) {
        case sf::Keyboard::Q:
            window->close();
            break;
        case sf::Keyboard::E:
            showEdges = !showEdges;
            break;
        case sf::Keyboard::R:
            buildGraph(15);
            break;
        case sf::Keyboard::M:
            if (mstEdges.empty()) {
                Kruskal kmst(G);
                mstEdges = kmst.MST();
                showMST = true;
            } else {
                showMST != showMST;
            }
            break;
        default:
            break;
    }
}

void App::start() {
    window = new sf::RenderWindow(sf::VideoMode(750, 400), "meh");
    texture = new sf::RenderTexture();
    texture->create(750, 400);
    sf::Event userEvent;
    while (window->isOpen()) {
        while (window->pollEvent(userEvent)) {
            switch (userEvent.type) {
                case sf::Event::Closed:
                    window->close();
                    break;
                case sf::Event::KeyPressed:
                    handleKeyStrokes(userEvent);
                    break;
                default:
                    break;
            }
        }
        render();
    }
}

sf::VertexArray App::makeLine(Point from, Point to, sf::Color a, sf::Color b) {
    sf::VertexArray line(sf::LineStrip, 2);
    line[0].position = sf::Vector2f(from.x, from.y);
    line[1].position = sf::Vector2f(to.x, to.y);
    line[0].color = a;
    line[1].color = b;
    return line;
}

void App::drawGraph() {
    if (showEdges) {
        for (int i = 0; i < verts.size(); i++) {
            Point from = verts[i].pos();
            for (auto it = G.adj(i); !it.end(); it.next()) {
                sf::VertexArray line(sf::LineStrip, 2);
                Point to = verts[it.get()->u].pos();
                texture->draw(makeLine(from, to, sf::Color::Green, sf::Color::Green));
            }
        }
    }
    if (showMST) {
        for (pair<int,int> edge : mstEdges) {
            Point from = verts[edge.first].pos();
            Point to = verts[edge.second].pos();
            texture->draw(makeLine(from, to, sf::Color::Blue, sf::Color::Red));
        }
    }
    for (Vertex vert : verts) {
        sf::CircleShape circle(8);
        circle.setFillColor(sf::Color::Green);
        circle.setPosition(vert.pos().x, vert.pos().y);
        texture->draw(circle);
    }
    texture->display();
}

void App::render() {
    texture->clear(sf::Color::Black);
    drawGraph();
    texture->display();
    sf::Sprite sprite(texture->getTexture());
    window->draw(sprite);
    window->display();
}