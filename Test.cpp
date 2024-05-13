#include "doctest.h"
#include "Algorithms.hpp"
#include "Graph.hpp"


#include "Algorithms.hpp"
#include "Graph.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <queue>
#include <stack>
#include <algorithm>
#include <stdexcept>
using namespace doctest;
using namespace ariel;


using namespace std;

TEST_CASE("Test isConnected")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isConnected(g) == true);

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isConnected(g) == false);
}

TEST_CASE("Test shortestPath")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 2) == "0->1->2");

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 4) == "-1");
}
TEST_CASE("Test isContainsCycle")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isContainsCycle(g) == false);

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isContainsCycle(g) == true);
}
TEST_CASE("Test isBipartite")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 2}, B={1}");

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isBipartite(g) == "0");

    vector<vector<int>> graph3 = {
        {0, 1, 2, 0, 0},
        {1, 0, 3, 0, 0},
        {2, 3, 0, 4, 0},
        {0, 0, 4, 0, 5},
        {0, 0, 0, 5, 0}};
    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::isBipartite(g) == "0");
                                              
}
TEST_CASE("Test invalid graph")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 2, 0},
        {1, 0, 3, 0},
        {2, 3, 0, 4},
        {0, 0, 4, 0},
        {0, 0, 0, 5}};
    CHECK_THROWS(g.loadGraph(graph));
}


TEST_CASE("Test invalid graph")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 2, 0},
        {1, 0, 3, 0},
        {2, 3, 0, 4},
        {0, 0, 4, 0},
        {0, 0, 0, 5}};
    CHECK_THROWS(g.loadGraph(graph));
}

TEST_CASE("Test isContainsCycle")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isContainsCycle(g) == false);
    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isContainsCycle(g) == true);
}

TEST_CASE("Test isBipartite")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 2}, B={1}");

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isBipartite(g) == "0");
}



TEST_CASE("Test invalid graph")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 2, 0},
        {1, 0, 3, 0},
        {2, 3, 0, 4},
        {0, 0, 4, 0},
        {0, 0, 0, 5}};
    CHECK_THROWS(g.loadGraph(graph));

    // The graph does not have 0 on the diagonal
    vector<vector<int>> graph88 = {
        {0, 1, 0, 0, 0},
        {1, 1, 3, 0, 0},
        {0, 3, 6, 4, 0},
        {0, 0, 4, 4, 5},
        {0, 0, 0, 5, 0}};
    CHECK_THROWS(g.loadGraph(graph88));
}

TEST_CASE("Testing more unweighted undirected graph")
{
    ariel::Graph g;
    vector<vector<int>> graph8 = {
        {0, 1, 1, 1, 0},
        {1, 0, 1, 0, 1},
        {1, 1, 0, 1, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 1, 0, 0}};

    g.loadGraph(graph8);
    CHECK(ariel::Algorithms::isConnected(g) == true);
    CHECK(ariel::Algorithms::isContainsCycle(g) == true);
    CHECK(ariel::Algorithms::isBipartite(g) == "0");
}

/***************** Testing Directed graphs ********************/

TEST_CASE("Testing directed unweighted graphs")
{
    ariel::Graph g;

    vector<vector<int>> graph2 = {
        {0, 1, 0},
        {0, 0, 1},
        {0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isConnected(g) == true);
    CHECK(ariel::Algorithms::isContainsCycle(g) == false);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 2}, B={1}");
    CHECK(ariel::Algorithms::shortestPath(g, 0, 2) == "0->1->2");
    CHECK(ariel::Algorithms::shortestPath(g, 2, 0) == "-1");
    CHECK(ariel::Algorithms::shortestPath(g, 2, 1) == "-1");

    vector<vector<int>> graph22 = {
        {0, 0, 0},
        {1, 0, 0},
        {0, 1, 0}};
    g.loadGraph(graph22);
    CHECK(ariel::Algorithms::isConnected(g) == true);
    CHECK(ariel::Algorithms::isContainsCycle(g) == false);

    vector<vector<int>> graph4 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph4);
    CHECK(ariel::Algorithms::isConnected(g) == true);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 2}, B={1}");
}

TEST_CASE("Checking an empty graph")
{
    ariel::Graph g;
    vector<vector<int>> graph = {};
    

    CHECK_THROWS(g.loadGraph(graph));
}

TEST_CASE("Checking directed wighted graph")
{
    ariel::Graph g;
    vector<vector<int>> graph3 = {
        {0, 1, 0},
        {3, 0, 1},
        {0, 2, 0}};
    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::isConnected(g) == true);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 2}, B={1}");
    CHECK(ariel::Algorithms::shortestPath(g, 0, 2) == "0->1->2");
    CHECK(ariel::Algorithms::shortestPath(g, 2, 1) == "2->1");

    vector<vector<int>> graph5 = {
        {0, 1, 0, 0, 0},
        {1, 0, 2, 0, 0},
        {0, 2, 0, 3, 0},
        {0, 0, 3, 0, 4},
        {0, 0, 0, 4, 0}};
    g.loadGraph(graph5);
    CHECK(ariel::Algorithms::isConnected(g) == true);
    CHECK(ariel::Algorithms::isContainsCycle(g) == false);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 4) == "0->1->2->3->4");
    CHECK(ariel::Algorithms::shortestPath(g, 3, 1) == "3->2->1");
   CHECK(ariel::Algorithms::shortestPath(g, 3, -1) == "-1");
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 2, 4}, B={1, 3}");
}
TEST_CASE("More weighted graphs")
{
    ariel::Graph g;
    vector<vector<int>> graph55 = {
        {0, 1, 0, 0, 0},
        {0, 0, 2, 0, 0},
        {0, 0, 0, 3, 0},
        {0, 0, 0, 0, 4},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph55);
    CHECK(ariel::Algorithms::isConnected(g) == true);
    CHECK(ariel::Algorithms::isContainsCycle(g) == false);
    CHECK(ariel::Algorithms::shortestPath(g, 4, 0) == "-1");
    CHECK(ariel::Algorithms::shortestPath(g, 3, 2) == "-1");
    CHECK(ariel::Algorithms::shortestPath(g, 2, 4) == "2->3->4");
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 2, 4}, B={1, 3}");

    vector<vector<int>> graph56 = {
        {0, 1, 0, 8, 0},
        {0, 0, 2, 2, 0},
        {0, 0, 0, 3, 0},
        {0, 0, 0, 0, 4},
        {0, 2, 6, 0, 0}};
    g.loadGraph(graph56);
    CHECK(ariel::Algorithms::isConnected(g) == true);
    CHECK(ariel::Algorithms::isContainsCycle(g) == true);
    CHECK(ariel::Algorithms::isBipartite(g) == "0");
    CHECK(ariel::Algorithms::shortestPath(g, 0, 3) == "0->1->3");
   CHECK(ariel::Algorithms::shortestPath(g, 4, 3) == "4->1->3");
    CHECK(ariel::Algorithms::shortestPath(g, 4, 2) == "4->1->2");
}
TEST_CASE("Testing big directed graph")
{
    ariel::Graph g;
    vector<vector<int>> graph57 = {
        {0, 2, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 3, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 4, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 5, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 6, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 7},
        {0, 0, 0, 0, 0, 0, 0, 0, 0}};

    g.loadGraph(graph57);
    CHECK(ariel::Algorithms::isConnected(g) == false);
    CHECK(ariel::Algorithms::isContainsCycle(g) == false);
   CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 2, 3, 5, 6, 8}, B={1, 4, 7}");
    CHECK(ariel::Algorithms::shortestPath(g, 8, 1) == "-1");
    CHECK(ariel::Algorithms::shortestPath(g, 3, 6) == "-1");
    CHECK(ariel::Algorithms::shortestPath(g, 1, 7) == "-1");
    CHECK(ariel::Algorithms::shortestPath(g, 0, 1) == "0->1");
    CHECK(ariel::Algorithms::shortestPath(g, 3, 5) == "3 -> 4 -> 5");

    vector<vector<int>> graph58 = {
        {0, 2, 4, 0, 0},
        {9, 0, 3, 0, 0},
        {5, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}};

    g.loadGraph(graph58);
    CHECK(ariel::Algorithms::isConnected(g) == false);
    CHECK(ariel::Algorithms::isContainsCycle(g) == true); // 0 -> 1 -> 0
    CHECK(ariel::Algorithms::shortestPath(g, 4, 3) == "-1");
    CHECK(ariel::Algorithms::shortestPath(g, 3, 0) == "-1");
    //CHECK(ariel::Algorithms::shortestPath(g, 0, 2) == "0 -> 2");
    //CHECK(ariel::Algorithms::shortestPath(g, 1, 0) == "1 -> 2 -> 0");
    CHECK(ariel::Algorithms::isBipartite(g) == "0");
}

TEST_CASE("Checking a big graph with no edges")
{
    ariel::Graph g;
    vector<vector<int>> graph6 = {
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph6);
    CHECK(ariel::Algorithms::isConnected(g) == false);
    CHECK(ariel::Algorithms::isContainsCycle(g) == false);
    //CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 1, 2, 3, 4}, B={}");
}

TEST_CASE("Checking a bidger graph with one vertex not connected and no cycle")
{
    ariel::Graph g;
    vector<vector<int>> graph6 = {
        {0, 1, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {1, 0, 0, 0, 0, 0, 0}};
    g.loadGraph(graph6);
    CHECK(ariel::Algorithms::isConnected(g) == false);
    CHECK(ariel::Algorithms::isContainsCycle(g) == false);
    //CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 2, 4, 5}, B={1, 6, 3}");

    // The same but with cycle
    vector<vector<int>> graph7 = {
        {0, 1, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {1, 0, 0, 0, 0, 0, 0}};
    g.loadGraph(graph7);
    CHECK(ariel::Algorithms::isConnected(g) == false);
    CHECK(ariel::Algorithms::isContainsCycle(g) == true);
   // CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 2, 4, 5}, B={1, 6, 3}");
    CHECK(ariel::Algorithms::shortestPath(g, 6, 4) == "6 -> 0 -> 1 -> 2 -> 3 -> 4");
    CHECK(ariel::Algorithms::shortestPath(g, 1, 4) == "1->2->3->4");
}

/************************ Negative cycle check ********************************/
TEST_CASE("Checking negative cycle in directed graph")
{
    ariel::Graph g;
    vector<vector<int>> graph10 = {
        {0, 3, 2},
        {0, 0, -2},
        {0, 0, 0}};
    g.loadGraph(graph10);
    CHECK(ariel::Algorithms::isConnected(g) == true);
    CHECK(ariel::Algorithms::isContainsCycle(g) == false);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 2) == "0->1->2");
    CHECK(ariel::Algorithms::negativeCycle(g) == false);
    CHECK(ariel::Algorithms::isBipartite(g) == "0");

    vector<vector<int>> graph11 = {
        {0, -1, 2},
        {0, 0, -3},
        {0, 0, 0}};
    g.loadGraph(graph11);
    CHECK(ariel::Algorithms::isConnected(g) == true);
    CHECK(ariel::Algorithms::isContainsCycle(g) == false);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 2) == "0->1->2");
    CHECK(ariel::Algorithms::negativeCycle(g) == false);
    CHECK(ariel::Algorithms::isBipartite(g) == "0");
}
TEST_CASE("Checking more for negative cycle in directed graph")
{
    ariel::Graph g;
    vector<vector<int>> graph12 = {
        {0, -1, 2, 0, 0, 0},
        {0, 0, -3, 4, 0, 0},
        {0, 0, 0, 0, -2, 0},
        {0, 0, 0, 0, 0, 5},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0}};
    g.loadGraph(graph12);
    CHECK(ariel::Algorithms::isConnected(g) == true);
    CHECK(ariel::Algorithms::isContainsCycle(g) == false);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 4) == "0->1->2->4");
    CHECK(ariel::Algorithms::shortestPath(g, 4, 5) == "-1");
    CHECK(ariel::Algorithms::shortestPath(g, 3, 1) == "-1");
    CHECK(ariel::Algorithms::shortestPath(g, 0, 3) == "0->1->3");
    CHECK(ariel::Algorithms::isBipartite(g) == "0");
    CHECK(ariel::Algorithms::negativeCycle(g) == false);

    vector<vector<int>> graph13 = {
        {0, 1, 0, 0},
        {0, 0, -1, 0},
        {0, 0, 0, -2},
        {1, 0, 0, 0}};
    g.loadGraph(graph13);
    CHECK(ariel::Algorithms::isConnected(g) == true);
    CHECK(ariel::Algorithms::isContainsCycle(g) == true);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 3) == "-1");
    CHECK(ariel::Algorithms::negativeCycle(g) == true);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 2}, B={1, 3}");

    vector<vector<int>> graph14 = {
        {0, 0, 0, 1, 0},
        {0, 0, -1, 0, 0},
        {0, 0, 0, -1, 0},
        {0, 0, 0, 0, 1},
        {0, -1, 0, 0, 0}};
    g.loadGraph(graph14);
    CHECK(ariel::Algorithms::isConnected(g) == true);
    CHECK(ariel::Algorithms::isContainsCycle(g) == true);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 4) == "-1");
    CHECK(ariel::Algorithms::negativeCycle(g) == true);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 2, 4}, B={1, 3}");
}
TEST_CASE("Checking negative cycle in big directed graph")
{
    ariel::Graph g;
    vector<vector<int>> graph15 = {
        {0, 1, 0, 0, 0, 0, 0},
        {0, 0, -10, 0, 0, 0, 0},
        {0, 0, 0, -30, 0, 0, 0},
        {30, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 40, 0},
        {0, 0, 0, 0, 0, 0, -50},
        {0, 0, 0, 0, 0, 0, 0}};
    g.loadGraph(graph15);
    CHECK(ariel::Algorithms::isConnected(g) == false);
    CHECK(ariel::Algorithms::isContainsCycle(g) == true);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 6) == "-1");
    CHECK(ariel::Algorithms::negativeCycle(g) == true);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 2, 4, 6}, B={1, 3, 5}");
}

/***************** Testin their graphs ****************/
TEST_CASE("Testing connected")
{
    ariel::Graph g; // directed graph
    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isConnected(g) == false);
}

TEST_CASE("Test shortestPath")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 2) == "0->1->2");
}
// //directed graph
//     // 5x5 matrix that reprsents a connected weighted graph.
//     vector<vector<int>> graph7 = {
//         {0, 1, 0, 0, 0},
//         {0, 0, 1, 0, 0},
//         {0, 0, 0, 1, 0},
//         {0, 0, 0, 0, 1},
//         {1, 0, 0, 0, 0}};

//     g.loadGraph(graph7); // Load the graph to the object.

//     g.printGraph();                                    // Should print: "Graph with 5 vertices and 10 edges."
//     cout << Algorithms::isConnected(g) << endl;        // Should print: "1" (true).
//     cout << Algorithms::shortestPath(g, 0, 4) << endl; // Should print: 0->2->3->4.
//     cout << Algorithms::isContainsCycle(g) << endl;    // Should print: "0" (false).
//     cout << Algorithms::isBipartite(g) << endl;        // Should print: "The graph is bipartite: A={0, 2, 4}, B={1, 3}."


