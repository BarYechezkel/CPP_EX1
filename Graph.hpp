#ifndef GRAPH_HPP
#define GRAPH_HPP
#include <vector>
#include <iostream>
#include <string>
namespace ariel{

class Graph
{
private:
    //std::vector<std::vector<int>> matrix;
    bool isDirected;
    int numOfEdges;
public:
    // constructor
    Graph();

    void loadGraph(const std::vector<std::vector<int>> &adjacency_matrix);
    void printGraph();
    std::vector<std::vector<int>> matrix;
};
}
#endif


// #ifndef GRAPH_HPP
// #define GRAPH_HPP
// #include <iostream>
// #include <vector>
// #include <string>
// using namespace std;
// namespace ariel{
// class Graph

// {
// private:
//     vector<vector<int>> matrix; // adjacency list
//     size_t v;                    // number of vertixs
//     bool isDirected;

// public:
//     Graph( vector<vector<int>> matrix, size_t v, bool isDirected);
//     void loadGraph(vector<vector<int>> graph,bool isdirected);
//     void printGraph();
//     size_t getSize();

// };
// }
// #endif
