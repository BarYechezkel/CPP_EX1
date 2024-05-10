#include "Algorithms.hpp"
#include "Graph.hpp"
#include <queue>
#include <limits>
using namespace ariel;
using namespace std;

const int white = 0;
const int gray = 1;
const int black = 2;
const size_t null = std::numeric_limits<size_t>::max();
const int infinity = std::numeric_limits<int>::max();;

void BFS(Graph g, int start, int end);
void bellman_ford(Graph g , int start);


int Algorithms::isConnected(Graph g) {
    // Implement the logic to check if the graph is connected
    // and return the result as an int
    return 0;
}

string Algorithms::shortestPath(Graph g, int start, int end) {
    BFS(g, start, end);
    bellman_ford(g, start);
    
    return "";
}

int Algorithms::isContainsCycle(Graph g) {
    // Implement the logic to check if the graph contains a cycle
    // and return the result as an int
    return 0;
}

bool Algorithms::isBipartite(Graph g) {
    // Implement the logic to check if the graph is bipartite
    // and return the result as a bool
    return false;
}

bool Algorithms::negativeCycle(Graph g) {
    // Implement the logic to check if the graph contains a negative cycle
    // and return the result as a bool
    return false;
}

// void BFS(Graph g, int start, int end) {
//     class vertex {
//     public:
//         int value;
//         int color;
//         int distance;
//         int parent;
//     };
//     vector<vector<vertex>> adj(g.matrix.size(), vector<vertex>(g.matrix.size()));
//     for (size_t i = 0; i < g.matrix.size(); i++) {
//         for (size_t j = 0; j < g.matrix.size(); j++) {
//             adj[i][j].value = g.matrix[i][j];
//         }
//     }
   
//    for (size_t i = 0; i < adj.size(); i++) {
//         for (size_t j = 0; j < adj.size(); j++) {
//             adj[i][j].color = white;
//             adj[i][j].distance = infinity;
//             adj[i][j].parent = null;
//         }
//     }
//     if (start < 0) {
//     // Handle error
// }

//     size_t start_i = static_cast<size_t>(start);

//     adj[start_i][start_i].color = gray;
//     adj[start_i][start_i].distance = 0;
//     adj[start_i][start_i].parent = null;
//     queue<int> q;
//     q.push(start);
//     while (!q.empty()) {
//         int u = q.front();
//         q.pop();
//         for (size_t i = 0; i < adj.size(); i++) {
//             vertex &v = adj[u][i];
//             if (v.color == white) {
//                 v.color = gray;
//                 v.distance = adj[u][u].distance + 1;
//                 v.parent = u;
//                 q.push(v.value);
//             }
//         }
//         adj[u][u].color = black;
//     }
//     vector<vertex> arr;
//     arr.push_back(adj[end][end]);
//     while (arr.back().parent != null) {
//         arr.push_back(adj[arr.back().parent][arr.back().parent]);
//     }
//     cout << "The shortest path is: ";
//     for (int i = arr.size() - 1; i >= 0; i--) {
//         cout << arr[i].value << " ";
//     }
// }

struct vertex {
    int color;
    int distance;
    size_t parent;
};

void BFS(Graph g, int start, int end) {
    if (start < 0 || start >= g.matrix.size()) {
        // Handle error: Invalid start vertex
        return;
    }

    std::vector<vertex> adj(g.matrix.size());
    for (size_t i = 0; i < g.matrix.size(); i++) {
        adj[i].color = white;
        adj[i].distance = infinity;
        adj[i].parent = null;
    }

    size_t start_i = static_cast<size_t>(start);

    adj[start_i].color = gray;
    adj[start_i].distance = 0;
    adj[start_i].parent = null;

    std::queue<size_t> q;
    q.push(start_i);

    while (!q.empty()) {
        size_t u = q.front();
        q.pop();

        for (size_t i = 0; i < g.matrix.size(); i++) {
            if (g.matrix[u][i] != 0 && adj[i].color == white) {
                adj[i].color = gray;
                adj[i].distance = adj[u].distance + 1;
                adj[i].parent = u;
                q.push(i);
            }
        }

        adj[u].color = black;
    }
    cout << "\nThe shortest path is: ";
size_t end_i = static_cast<size_t>(end);
    while (end_i != null) {
        if(adj[end_i].parent == null){
            cout << "there is no path between " << start << " and " << end << endl;
        }
        std::cout << end_i << " ";
        end_i = adj[end_i].parent;
    }
}

void bellman_ford(Graph g , int start){
        size_t start_i = static_cast<size_t>(start);

    vector<int> dist(g.matrix.size(), infinity);
    dist[start_i] = 0;
    for (size_t i = 0; i < g.matrix.size(); i++) {
        for (size_t u = 0; u < g.matrix.size(); u++) {
            for (size_t v = 0; v < g.matrix.size(); v++) {
                if (g.matrix[u][v] != 0 && dist[u] + g.matrix[u][v] < dist[v]) {
                    dist[v] = dist[u] + g.matrix[u][v];
                    
                }
            }
        }
    }
    for (size_t u = 0; u < g.matrix.size(); u++) {
        for (size_t v = 0; v < g.matrix.size(); v++) {
            if (g.matrix[u][v] != 0 && dist[u] + g.matrix[u][v] < dist[v]) {
                // Handle error: Negative cycle detected
                return;
            }
        }
    }
    for (size_t i = 0; i < dist.size(); i++) {
        //print the path
        cout << "The shortest path from " << start << " to " << i << " is: " << dist[i] << endl;
        cout << "The shortest path from " << start << " to " << i << " is: " << dist[i] << endl;
    }
}
