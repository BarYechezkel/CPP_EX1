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

TEST_CASE("Test directed Graph")
{
        ariel::Graph g;

vector<vector<int>> graph5 = {
        {0, 1, 0, 3, 0},
        {1, 0, 3, 0, 0},
        {0, 3, 0, 4, 0},
        {0, 0, 4, 0, 5},
        {0, 0, 0, 5, 0}};

    g.loadGraph(graph5); // Load the graph to the object.

    CHECK(ariel::Algorithms::isConnected(g) == true);
    CHECK(ariel::Algorithms::isContainsCycle(g) == false);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 4) == "0->3->4");
    CHECK(ariel::Algorithms::shortestPath(g, 3, 1) == "3->2->1");
    CHECK(ariel::Algorithms::shortestPath(g, 3, -1) == "-1");
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 2, 4}, B={1, 3}");
}

TEST_CASE("Test graph is not connected")
{
        ariel::Graph g;

vector<vector<int>> graph5 = {
        {0, 9, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 7, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}};

    g.loadGraph(graph5); // Load the graph to the object.

    CHECK(ariel::Algorithms::isConnected(g) == false);
    CHECK(ariel::Algorithms::isContainsCycle(g) == false);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 3) == "0->1->2->3");
    CHECK(ariel::Algorithms::shortestPath(g, 3, 1) == "-1");
    CHECK(ariel::Algorithms::shortestPath(g, 3, 4) == "-1");
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 2, 4}, B={1, 3}");
}

TEST_CASE("Test graph is unwighted and not connected")
{
        ariel::Graph g;

vector<vector<int>> graph6 = {
        {0, 1, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 1, 0},
        {0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0}};

    g.loadGraph(graph6); // Load the graph to the object.

    CHECK(ariel::Algorithms::isConnected(g) == true);
    CHECK(ariel::Algorithms::isContainsCycle(g) == true);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 3) == "0->1->2->3");
    CHECK(ariel::Algorithms::shortestPath(g, 3, 1) == "3->4->0->1");
    CHECK(ariel::Algorithms::shortestPath(g, 3, 4) == "3->4");
    CHECK(ariel::Algorithms::isBipartite(g) == "0");
}

TEST_CASE("Test graph with negative edge")
{
        ariel::Graph g;

vector<vector<int>> graph = {
        {0, 1, 0},
        {0, 0, -1},
        {1, 0, 0}};

    g.loadGraph(graph); // Load the graph to the object.

    CHECK(ariel::Algorithms::isConnected(g) == true);
    CHECK(ariel::Algorithms::isContainsCycle(g) == true);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 2) == "0->1->2");
    CHECK(ariel::Algorithms::isBipartite(g) == "0");
    CHECK(ariel::Algorithms::negativeCycle(g) == false);
}

TEST_CASE("Test graph with negative cycle")
{
        ariel::Graph g;

vector<vector<int>> graph = {
        {0, -1, 0},
        {0, 0, -1},
        {-1, 0, 0}};

    g.loadGraph(graph); // Load the graph to the object.

    CHECK(ariel::Algorithms::isConnected(g) == true);
    CHECK(ariel::Algorithms::isContainsCycle(g) == true);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 2) == "-1");
    CHECK(ariel::Algorithms::isBipartite(g) == "0");
    CHECK(ariel::Algorithms::negativeCycle(g) == true);
}


TEST_CASE("Test directed graph with cycle, illegal start & end vertex")
{
        ariel::Graph g;

vector<vector<int>> graph = {
         {0, 1, 0},
        {0, 0, 1},
        {1, 0, 0}};

    g.loadGraph(graph); // Load the graph to the object.

    CHECK(ariel::Algorithms::isConnected(g) == true);
    CHECK(ariel::Algorithms::isContainsCycle(g) == true);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 2) == "0->1->2");
    CHECK(ariel::Algorithms::shortestPath(g, 0, 8) == "-1");
    CHECK(ariel::Algorithms::shortestPath(g, -1, 2) == "-1");
    CHECK(ariel::Algorithms::isBipartite(g) == "0");
    CHECK(ariel::Algorithms::negativeCycle(g) == false);
}

TEST_CASE("Test undireced & unweight graph with cycle, illegal start & end vertex")
{
        ariel::Graph g;

vector<vector<int>> graph = {
         {0, 1, 0, 1, 0},
        {1, 0, 1, 0, 1},
        {0, 1, 0, 1, 0},
        {1, 0, 1, 0, 1},
        {0, 1, 0, 1, 0}};

    g.loadGraph(graph); // Load the graph to the object.

    CHECK(ariel::Algorithms::isConnected(g) == true);
    CHECK(ariel::Algorithms::isContainsCycle(g) == true);
    CHECK(ariel::Algorithms::shortestPath(g, 1, 4) == "1->4");
    CHECK(ariel::Algorithms::shortestPath(g, 0, -5) == "-1");
    CHECK(ariel::Algorithms::shortestPath(g, 5, 2) == "-1");
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 2, 4}, B={1, 3}");
    CHECK(ariel::Algorithms::negativeCycle(g) == false);
}

TEST_CASE("Test direced graph with cycle")
{
        ariel::Graph g;

vector<vector<int>> graph = {
         {0, 1, 2, 0, 0},
        {1, 0, 3, 0, 0},
        {2, 3, 0, 4, 0},
        {0, 0, 4, 0, 5},
        {8, 0, 0, 5, 0}};

    g.loadGraph(graph); // Load the graph to the object.

    CHECK(ariel::Algorithms::isConnected(g) == true);
    CHECK(ariel::Algorithms::isContainsCycle(g) == true);
    CHECK(ariel::Algorithms::shortestPath(g, 1, 4) == "1->2->3->4");
    CHECK(ariel::Algorithms::isBipartite(g) == "0");
    CHECK(ariel::Algorithms::negativeCycle(g) == false);
}
TEST_CASE("Test empty matrix")
{
        ariel::Graph g;

vector<vector<int>> graph = {};

    CHECK_THROWS(g.loadGraph(graph));

}

TEST_CASE("Test invalid diagonal in the matrix")
{
        ariel::Graph g;

vector<vector<int>> graph = {
        {4, 1, 2, 0},
        {0, 5, 3, 0},
        {0, 3, 0, 4},
        {0, 0, 4, 0}};
        
    CHECK_THROWS(g.loadGraph(graph));

}

   
   
