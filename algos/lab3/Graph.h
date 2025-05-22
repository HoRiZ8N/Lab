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
    vector<vector<int>> adj;  // ������ ��������� (��� ������ ������� ������ ������ ������� ������)
    size_t vertices;          // ���������� ������ � �����

public:
    Graph(size_t v = 0) : vertices(v), adj(v) {}

    size_t getVertexCount() const {
        return vertices;
    }

    // ��������� ����� ������� � ����
    void addVertex() {
        adj.push_back({});
        vertices++;
        cout << "������� " << vertices - 1 << " ���������.\n";
    }

    // ��������� ����� ����� ��������� u � v (����������������� ����)
    void addEdge(int u, int v) {
        if (u < 0 || v < 0 || u >= vertices || v >= vertices) {
            cerr << "������: ������������ ������� ������\n";
            return;
        }
        if (u == v) {
            cerr << "������: ����� �� ��������������\n";
            return;
        }
        if (find(adj[u].begin(), adj[u].end(), v) != adj[u].end()) {
            cerr << "������: ����� ��� ����������\n";
            return;
        }
        adj[u].push_back(v);
        adj[v].push_back(u);
        cout << "����� ����� " << u << " � " << v << " ���������.\n";
    }

    void removeVertex(int u) {
        if (u < 0 || u >= vertices) {
            cerr << "������: ������������ ������ �������\n";
            return;
        }

        // ������� ��� �����, ��������� � �������� u
        for (auto& neighbors : adj) {
            neighbors.erase(remove(neighbors.begin(), neighbors.end(), u), neighbors.end());
            // ������������ ������� ������ ������ u
            for (auto& v : neighbors) {
                if (v > u) v--;
            }
        }

        // ������� ���� �������
        adj.erase(adj.begin() + u);
        vertices--;
        cout << "������� " << u << " �������.\n";
    }

    // ������� ���� � ���� ������� ���������
    void printGraph() const {
        if (vertices == 0) {
            cout << "���� ����.\n";
            return;
        }
        cout << "������ ��������� �����:\n";
        for (size_t i = 0; i < vertices; ++i) {
            cout << "������� " << i << ": ";
            for (int v : adj[i]) {
                cout << v << " ";
            }
            cout << endl;
        }
    }

    // ����� � ������� (DFS)
    void dfs(int start, vector<bool>& visited) {
        if (start < 0 || start >= vertices) {
            cerr << "������: ������������ ��������� �������\n";
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

    // ����� � ������ (BFS)
    void bfs(int start) {
        if (start < 0 || start >= vertices) {
            cerr << "������: ������������ ��������� �������\n";
            return;
        }

        vector<bool> visited(vertices, false);
        queue<int> q;
        visited[start] = true;
        q.push(start);

        cout << "BFS ����� ������� � ������� " << start << ": ";
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

    // ������� ���������� ���������� ����� ��������� (BFS)
    int bfsDistance(int start, int end) {
        if (start < 0 || end < 0 || start >= vertices || end >= vertices) {
            cerr << "������: ������������ ������� ������\n";
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
        return -1;  // ���� �� ������
    }

    // ������� ������� ����� (������������ ���������� ����� ���������)
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

    // ������� ���� ����� ��������� (BFS)
    vector<int> findPath(int start, int end) {
        if (start < 0 || end < 0 || start >= vertices || end >= vertices) {
            cerr << "������: ������������ ������� ������\n";
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

        if (parent[end] == -1) return {};  // ���� �� ������

        vector<int> path;
        for (int v = end; v != start; v = parent[v]) {
            path.push_back(v);
        }
        path.push_back(start);
        reverse(path.begin(), path.end());
        return path;
    }

    // ��������� ���� �� �����
    void readGraphFromFile(const string& filename) {
        ifstream file(filename);
        if (!file) {
            cerr << "������ �������� �����\n";
            return;
        }

        int v, e;
        file >> v >> e;
        if (v < 0 || e < 0) {
            cerr << "������: ������������ �������� � �����\n";
            return;
        }

        vertices = v;
        adj.clear();
        adj.resize(v);

        for (int i = 0; i < e; ++i) {
            int u, v;
            file >> u >> v;
            if (u < 0 || v < 0 || u >= vertices || v >= vertices) {
                cerr << "������: ������������ ������� ������ � �����\n";
                adj.clear();
                vertices = 0;
                return;
            }
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        cout << "���� �������� �� �����: " << filename << endl;
    }

    // ��������� ������ �����
    void loadExampleGraph() {
        vertices = 5;
        adj = {
            {1, 2},    // 0
            {0, 2, 3},  // 1
            {0, 1, 4},  // 2
            {1, 4},     // 3
            {2, 3}      // 4
        };
        cout << "������ ����� ��������\n";
    }

    vector<int> findVerticesAtKDistance(int start, int k) {
        if (start < 0 || start >= vertices) {
            cerr << "������: ������������ ��������� �������\n";
            return {};
        }
        if (k < 0) {
            cerr << "������: ����� ���� �� ����� ���� �������������\n";
            return {};
        }

        queue<pair<int, int>> q; // �������: ������� � ������� �������
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

        // �������� ����������
        sort(result.begin(), result.end());
        auto last = unique(result.begin(), result.end());
        result.erase(last, result.end());

        return result;
    }
};

void showMenu() {
    cout << "\n=== ���� ����� ===\n"
         << "1. ��������� ���� �� �����\n"
         << "2. ������� ����\n"
         << "3. �������� �������\n"
         << "4. ������� �������\n"
         << "5. �������� �����\n"
         << "6. ����� � ������� (DFS)\n"
         << "7. ����� � ������ (BFS)\n"
         << "8. ����� ������� �����\n"
         << "9. ��������� ������ �����\n"
         << "10. ����� ���� ����� ���������\n"
         << "11. ����� ������� �� ���������� k\n"
         << "0. �����\n"
         << "�������� �����: ";
}
