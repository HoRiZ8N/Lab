#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
#include <fstream>
#include <string>

#pragma once

using namespace std;

class Graph {
private:
    vector<vector<int>> adj;  // Список смежности (для каждой вершины хранит список смежных вершин)
    size_t vertices;          // Количество вершин в графе

public:
    Graph(size_t v = 0) : vertices(v), adj(v) {}

    size_t getVertexCount() const {
        return vertices;
    }

    // Добавляет новую вершину в граф
    void addVertex() {
        adj.push_back({});
        vertices++;
        cout << "Вершина " << vertices - 1 << " добавлена.\n";
    }

    // Добавляет ребро между вершинами u и v (неориентированный граф)
    void addEdge(int u, int v) {
        if (u < 0 || v < 0 || u >= vertices || v >= vertices) {
            cerr << "Ошибка: Недопустимые индексы вершин\n";
            return;
        }
        if (u == v) {
            cerr << "Ошибка: Петли не поддерживаются\n";
            return;
        }
        if (find(adj[u].begin(), adj[u].end(), v) != adj[u].end()) {
            cerr << "Ошибка: Ребро уже существует\n";
            return;
        }
        adj[u].push_back(v);
        adj[v].push_back(u);
        cout << "Ребро между " << u << " и " << v << " добавлено.\n";
    }

    void removeVertex(int u) {
        if (u < 0 || u >= vertices) {
            cerr << "Ошибка: Недопустимый индекс вершины\n";
            return;
        }

        // Удаляем все ребра, связанные с вершиной u
        for (auto& neighbors : adj) {
            neighbors.erase(remove(neighbors.begin(), neighbors.end(), u), neighbors.end());
            // Корректируем индексы вершин больше u
            for (auto& v : neighbors) {
                if (v > u) v--;
            }
        }

        // Удаляем саму вершину
        adj.erase(adj.begin() + u);
        vertices--;
        cout << "Вершина " << u << " удалена.\n";
    }

    // Выводит граф в виде списков смежности
    void printGraph() const {
        if (vertices == 0) {
            cout << "Граф пуст.\n";
            return;
        }
        cout << "Списки смежности графа:\n";
        for (size_t i = 0; i < vertices; ++i) {
            cout << "Вершина " << i << ": ";
            for (int v : adj[i]) {
                cout << v << " ";
            }
            cout << endl;
        }
    }

    // Обход в глубину (DFS)
    void dfs(int start, vector<bool>& visited) {
        if (start < 0 || start >= vertices) {
            cerr << "Ошибка: Недопустимая начальная вершина\n";
            return;
        }
        visited[start] = true;
        cout << start << " ";
        for (int neighbor : adj[start]) {
            if (!visited[neighbor]) {
                dfs(neighbor, visited);
            }
        }
    }

    // Обход в ширину (BFS)
    void bfs(int start) {
        if (start < 0 || start >= vertices) {
            cerr << "Ошибка: Недопустимая начальная вершина\n";
            return;
        }

        vector<bool> visited(vertices, false);
        queue<int> q;
        visited[start] = true;
        q.push(start);

        cout << "BFS обход начиная с вершины " << start << ": ";
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            cout << v << " ";
            for (int neighbor : adj[v]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        cout << endl;
    }

    // Находит кратчайшее расстояние между вершинами (BFS)
    int bfsDistance(int start, int end) {
        if (start < 0 || end < 0 || start >= vertices || end >= vertices) {
            cerr << "Ошибка: Недопустимые индексы вершин\n";
            return -1;
        }

        vector<int> distance(vertices, -1);
        queue<int> q;
        distance[start] = 0;
        q.push(start);

        while (!q.empty()) {
            int v = q.front();
            q.pop();
            if (v == end) return distance[v];

            for (int neighbor : adj[v]) {
                if (distance[neighbor] == -1) {
                    distance[neighbor] = distance[v] + 1;
                    q.push(neighbor);
                }
            }
        }
        return -1;  // Путь не найден
    }

    // Находит диаметр графа (максимальное расстояние между вершинами)
    int findDiameter() {
        if (vertices == 0) return 0;
        int diameter = 0;

        for (size_t i = 0; i < vertices; ++i) {
            vector<int> distance(vertices, -1);
            queue<int> q;
            distance[i] = 0;
            q.push(i);

            while (!q.empty()) {
                int v = q.front();
                q.pop();
                for (int neighbor : adj[v]) {
                    if (distance[neighbor] == -1) {
                        distance[neighbor] = distance[v] + 1;
                        q.push(neighbor);
                        diameter = max(diameter, distance[neighbor]);
                    }
                }
            }
        }
        return diameter;
    }

    // Находит путь между вершинами (BFS)
    vector<int> findPath(int start, int end) {
        if (start < 0 || end < 0 || start >= vertices || end >= vertices) {
            cerr << "Ошибка: Недопустимые индексы вершин\n";
            return {};
        }

        vector<int> parent(vertices, -1);
        queue<int> q;
        parent[start] = start;
        q.push(start);

        while (!q.empty()) {
            int v = q.front();
            q.pop();
            if (v == end) break;

            for (int neighbor : adj[v]) {
                if (parent[neighbor] == -1) {
                    parent[neighbor] = v;
                    q.push(neighbor);
                }
            }
        }

        if (parent[end] == -1) return {};  // Путь не найден

        vector<int> path;
        for (int v = end; v != start; v = parent[v]) {
            path.push_back(v);
        }
        path.push_back(start);
        reverse(path.begin(), path.end());
        return path;
    }

    // Загружает граф из файла
    void readGraphFromFile(const string& filename) {
        ifstream file(filename);
        if (!file) {
            cerr << "Ошибка открытия файла\n";
            return;
        }

        int v, e;
        file >> v >> e;
        if (v < 0 || e < 0) {
            cerr << "Ошибка: Недопустимые значения в файле\n";
            return;
        }

        vertices = v;
        adj.clear();
        adj.resize(v);

        for (int i = 0; i < e; ++i) {
            int u, v;
            file >> u >> v;
            if (u < 0 || v < 0 || u >= vertices || v >= vertices) {
                cerr << "Ошибка: Недопустимые индексы вершин в файле\n";
                adj.clear();
                vertices = 0;
                return;
            }
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        cout << "Граф загружен из файла: " << filename << endl;
    }

    // Загружает пример графа
    void loadExampleGraph() {
        vertices = 5;
        adj = {
            {1, 2},    // 0
            {0, 2, 3},  // 1
            {0, 1, 4},  // 2
            {1, 4},     // 3
            {2, 3}      // 4
        };
        cout << "Пример графа загружен\n";
    }

    vector<int> findVerticesAtKDistance(int start, int k) {
        if (start < 0 || start >= vertices) {
            cerr << "Ошибка: Недопустимая начальная вершина\n";
            return {};
        }
        if (k < 0) {
            cerr << "Ошибка: Длина пути не может быть отрицательной\n";
            return {};
        }

        queue<pair<int, int>> q; // Очередь: вершина и текущий уровень
        q.push({start, 0});
        vector<int> result;

        while (!q.empty()) {
            auto [currentVertex, currentLevel] = q.front();
            q.pop();

            if (currentLevel == k) {
                result.push_back(currentVertex);
            } else if (currentLevel < k) {
                for (int neighbor : adj[currentVertex]) {
                    q.push({neighbor, currentLevel + 1});
                }
            }
        }

        // Удаление дубликатов
        sort(result.begin(), result.end());
        auto last = unique(result.begin(), result.end());
        result.erase(last, result.end());

        return result;
    }
};

void showMenu() {
    cout << "\n=== Меню графа ===\n"
         << "1. Загрузить граф из файла\n"
         << "2. Вывести граф\n"
         << "3. Добавить вершину\n"
         << "4. Удалить вершину\n"
         << "5. Добавить ребро\n"
         << "6. Обход в глубину (DFS)\n"
         << "7. Обход в ширину (BFS)\n"
         << "8. Найти диаметр графа\n"
         << "9. Загрузить пример графа\n"
         << "10. Найти путь между вершинами\n"
         << "11. Найти вершины на расстоянии k\n"
         << "0. Выход\n"
         << "Выберите опцию: ";
}
