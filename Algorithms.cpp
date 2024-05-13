#include "Algorithms.hpp"
#include "Graph.hpp"
#include <queue>
#include <limits>
#include <algorithm>
#include <stack>
using namespace ariel;
using namespace std;

const int INF = std::numeric_limits<int>::max();

int is_Connected(Graph &g);

void bellman_ford(Graph &g, int start, int end, vector<int> &path);
bool BFS(Graph &g, int start, int end);

bool DFS(Graph g, int v, vector<bool> &visited, vector<int> &path, vector<bool> &recStack, int parent, int &end);
void printCyclePath(const vector<int> &path, int end);
bool isCyclic(Graph &g);

bool hasNegativeCycle(Graph &graph, int src);

bool isBipartiteUtil(vector<vector<int>> &matrix, int src, vector<int> &color);

int Algorithms::isConnected(Graph &g)
{
    if (is_Connected(g) == 1)
    {
        cout << "The graph is connected" << endl;
        return 1;
    }
    else if (is_Connected(g) == 0)
    {
        cout << "The graph is not connected" << endl;
        return 0;
    }

    return 0;
}

string Algorithms::shortestPath(Graph &g, int start, int end)
{
    if (negativeCycle(g) || start <0 || end <0)
    {
        //cout << "The graph contains negative cycle" << endl;
        return "-1";
    }

    if (!g.getHasNegativeEdge()){
        //dijsktra
    }

    if (g.getHasNegativeEdge()){
        //bellman_ford
    }

    if (g.getWithoutWhights()){
        //BFS
        if (BFS(g, start, end) == false)
        {
            //cout << "There is no path from " << start << " to " << end << endl;
            return "-1";
        }
    }
    vector<int> path;
    bellman_ford(g, start, end, path);
    string result;
    if (path.size() == 0)
    {
        // No path exists from start to end
        return "-1";
    }
    else{
    //cout << "The shortest path from " << start << " to " << end << " is: ";
    for (size_t i = 0; i < path.size() - 1; i++)
    {
        result += to_string(path[i]) + "->";
        //cout << path[i] << " -> ";
    }
    result += to_string(path[(size_t)end]);
    //cout << path[(size_t)end] << endl;
}
cout << result << endl;
    return result;
}

int Algorithms::isContainsCycle(Graph &g)
{
    if (isCyclic(g)){
        //printCyclePath(path, end);
        return 1;
    }
    else{
        //cout << "The graph does not contain a cycle" << endl;
        return 0;
    }

    return 0;
}

string Algorithms::isBipartite(Graph &g)
{
        std::vector<std::vector<int>> matrix = g.getMatrix();
        size_t n = matrix.size();
        vector<int> color(n, -1); // -1 represents uncolored
        string result = "The graph is bipartite: A={";
         
        for (size_t i = 0; i < n; ++i)
        {
            if (color[i] == -1)
            { // If vertex is uncolored, it means it is not visited yet

                if (isBipartiteUtil(matrix, i, color)==false)
                {
                    // If the graph is not bipartite, return false
                    return "0";
                }
            }
        }

        // If graph is bipartite, divide vertices into two sets based on color
        vector<int> setA, setB;
        for (size_t i = 0; i < n; ++i)
        {
            if (color[i] == 0)
                setA.push_back(i);
            else
                setB.push_back(i);
        }

        //result += "A={";
        for (size_t i = 0; i < setA.size(); ++i)
        {
            result += to_string(setA[i]);
            if (i != setA.size() - 1){
            result += ", ";
        }
        }
        result += "}, B={";

        for (size_t i = 0; i < setB.size(); ++i)
        {
            result += to_string(setB[i]);
            if (i != setB.size() - 1){
            result += ", ";
            }
        }
        result += "}";
        return result;
        cout << result << endl;
    }


bool Algorithms::negativeCycle(Graph &g)
{
    for (size_t i = 0; i < g.getMatrix().size(); i++)
    {
        for (size_t j = 0; j < g.getMatrix().size(); j++)
        {
            if (g.getMatrix()[i][j] < 0)
            {
                if (hasNegativeCycle(g, i))
                {
                    //cout << "The graph contains negative cycle" << endl;
                    return true;
                }
            }
        }
    }
    return false;
}

int is_Connected(Graph &g)
{

    if (g.getIsDirected() == true)
    {
        // If the graph is directed, check connectivity between all pairs of vertices
        // cout << "The graph is directed" << endl;
        for (int i = 0; i < g.getMatrix().size(); i++)
        {
            for (int j = 0; j < g.getMatrix().size(); j++)
            {
                if (BFS(g, i, j) == true)
                {
                    // cout << "The graph is connected" << endl;
                    return 1;
                }
            }
        }
        //  cout << "The graph is not connected" << endl;
        return 0;
    }
    else if (g.getIsDirected() == false)
    {
        // cout << "The graph is undirected" << endl;
        //  If the graph is undirected, check connectivity between two arbitrary vertices (0 and 1)
        if (BFS(g, 0, 1) == false)
        {
            // cout << "The graph is not connected" << endl;
            return 0;
        }
        else
        {
            // cout << "The graph is connected" << endl;
            return 1;
        }
        return 0;
    }
    return 0;
}

// Function to perform Bellman-Ford algorithm and find the shortest path to a specified end vertex
void bellman_ford(Graph &graph, int src, int end,vector<int> &path )
{
        const vector<vector<int>> &matrix = graph.getMatrix();
    size_t n = matrix.size(); // Number of vertices in the graph

    const int INF = std::numeric_limits<int>::max(); // Define infinity for distance

    vector<int> dist(n, INF);   // Array to store shortest distances from src to each vertex
    vector<int> parent(n, -1);  // Array to store parent vertices in the shortest path tree

    dist[(size_t)src] = 0; // Distance from src to itself is 0

    // Relax edges up to n - 1 times
    for (size_t count = 0; count < n - 1; count++)
    {
        for (size_t u = 0; u < n; u++)
        {
            for (size_t v = 0; v < n; v++)
            {
                if (matrix[u][v] != 0 && dist[u] != INF && dist[u] + matrix[u][v] < dist[v])
                {
                    dist[v] = dist[u] + matrix[u][v];
                    parent[v] = u;
                }
            }
        }
    }
////////////////////////////////////////
    // // Check for negative cycles
    // for (size_t u = 0; u < n; u++)
    // {
    //     for (size_t v = 0; v < n; v++)
    //     {
    //         if (matrix[u][v] != 0 && dist[u] != INF && dist[u] + matrix[u][v] < dist[v])
    //         {
    //             //cout << "The graph contains negative cycle" << endl;
    //             return;
    //         }
    //     }
    // }
    // ///////////////////////////////

    // Reconstruct the shortest path from end to src using the parent vector
    if (dist[(size_t)end] == INF)
    {
        // No path exists from src to end
        path.clear();
        return;
    }

    path.clear();
    int current = end;
    path.push_back(end);
    while (current != src)
    {
        path.push_back(current);
        current = parent[(size_t)current];
    }
    path.push_back(src);
    reverse(path.begin(), path.end());
        path.pop_back();


}

bool hasNegativeCycle(Graph &graph, int src)
{
    {
    const std::vector<std::vector<int>> &matrix = graph.getMatrix();
    size_t n = matrix.size(); // Number of vertices in the graph

    std::vector<int> dist(n, INF);  // Array to store shortest distances from src to each vertex
    std::vector<int> parent(n, -1); // Array to store parent vertices in the shortest path tree

    dist[(size_t)src] = 0; // Distance from src to itself is 0

    // Relax edges repeatedly to find shortest paths
    for (size_t count = 0; count < n - 1; count++)
    {
        for (size_t u = 0; u < n; u++)
        {
            for (size_t v = 0; v < n; v++)
            {
                if (matrix[u][v] != 0 && dist[u] != INF && dist[u] + matrix[u][v] < dist[v])
                {
                    dist[v] = dist[u] + matrix[u][v];
                    parent[v] = u;
                }
            }
        }
    }

    // Check for negative cycles using an additional iteration
    for (size_t u = 0; u < n; u++)
    {
        for (size_t v = 0; v < n; v++)
        {
            if (matrix[u][v] != 0 && dist[u] != INF && dist[u] + matrix[u][v] < dist[v])
            {
                // Negative cycle detected
                // Reconstruct the cycle if needed
                return true;
            }
        }
    }

    return false;
}
}

bool BFS(Graph &g, int start, int end)
{
    const std::vector<std::vector<int>> &matrix = g.getMatrix();
    size_t n = matrix.size(); // Number of vertices in the graph

    std::vector<bool> visited(n, false); // Array to store visited vertices
    std::queue<int> q;                   // Queue to store vertices to visit
    std::vector<int> parent(n, -1);      // Array to store parent vertices in the shortest path tree

    visited[(size_t)start] = true; // Mark the start vertex as visited
    q.push(start);                 // Add the start vertex to the queue

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (size_t v = 0; v < n; v++)
        {
            if (matrix[(size_t)u][v] != 0 && !visited[v])
            {
                visited[v] = true;
                parent[v] = u;
                q.push(v);
            }
        }
    }
    // check if all the vertices are visited
    for (size_t i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            return false;
        }
    }
    return true;
}

bool DFS(Graph g, int v, vector<bool> &visited, vector<int> &path, vector<bool> &recStack, int parent, int &end)
{
    visited[(size_t)v] = true;
    recStack[(size_t)v] = true;
    path.push_back(v);

    for (size_t i = 0; i < g.getMatrix().size(); ++i)
    {
        if (g.getMatrix()[(size_t)v][i] != 0)
        {
            if (!visited[i])
            {
                // Recursive DFS call
                if (DFS(g, i, visited, path, recStack, v, end))
                    return true;
            }
            else if (recStack[i] && i != parent)
            {
                end =i;
                // Cycle detected, print the cycle path
                //printCyclePath(path, i);
                return true;
            }
        }
    }

    // Backtrack: Remove the vertex from the path and recursion stack
    path.pop_back();
    recStack[(size_t)v] = false;
    return false;
}

void printCyclePath( vector<int> &path, int end)
{
    //cout << "Cycle detected: ";
    bool found = false;
    for (int v : path)
    {
        if (v == end)
        {
            found = true;
        }
        if (found)
        {
            //cout << v << " -> ";
        }
    }
    //cout << end << endl;
}

bool isCyclic(Graph &g)
{
    size_t n = g.getMatrix().size();
    vector<bool> visited(n, false);
    vector<bool> recStack(n, false);
    vector<int> path;
     int end = -1;
     bool cycle = false;

    for (size_t i = 0; i < n; ++i)
    {
        if (!visited[i])
        {
           
            if (DFS(g, i, visited, path, recStack, -1 , end))
            {
                cycle = true; // Cycle detected
            }
        }
    } 
    if (cycle)
    {
        printCyclePath(path, end);
   
    }

    return cycle ; // No cycle found in the entire graph
}

// this function is used to check if the graph is bipartite or not
// using BFS traversal
// The algorithm colors the vertices with two colors in such a way that
// no two adjacent vertices have the same color
// If the graph is bipartite, the function returns true
// Otherwise, it returns false
bool isBipartiteUtil(vector<vector<int>> &matrix, int src, vector<int> &color)
{
    queue<int> q;
    q.push(src);
    color[(size_t)src] = 0; // Color the source vertex with 0 (set A)

    // Perform BFS traversal
    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (size_t v = 0; v < matrix[(size_t)u].size(); ++v)
        {
            if (matrix[(size_t)u][v] != 0)
            {
                if (color[v] == -1)
                {
                    // Color the adjacent vertex with a different color 
                   color[v] = 1 - color[(size_t)u]; // if color[u] is 0, color[v] is 1, if color[u] is 1, color[v] is 0
                    q.push(v);
                }
                // If adjacent vertices have the same color, graph is not bipartite
                else if (color[v] == color[(size_t)u])
                {
                    return false;
                }
            }
        }
    }

    return true;
}
