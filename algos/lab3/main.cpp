#include "Graph.h"

int main() {
    setlocale(LC_ALL, "rus");
    Graph g;
    g.loadExampleGraph();
    std::vector v = g.findVerticesAtKDistance(1, 12);
    for (size_t i = 0; i < v.size(); i++) {
        std::cout << v[i] << " ";
    }

    return 0;
}