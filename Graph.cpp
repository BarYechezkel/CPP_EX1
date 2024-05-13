#include "Graph.hpp"
using namespace ariel;

// Constructor implementation
Graph::Graph()
{
    
}

// Method to load graph from adjacency matrix
void Graph::loadGraph( std::vector<std::vector<int>> &adjacency_matrix)
{
    this->isDirected = false;
    this->numOfEdges = 0;

    if (adjacency_matrix.size() == 0)
    {
        // If the matrix is empty, the graph is empty
        throw std::invalid_argument("The matrix is empty");
    }

    for (size_t i = 0; i < adjacency_matrix.size(); i++)
    {
        if (adjacency_matrix.size() != adjacency_matrix[i].size())
        {
            // If the matrix is not square, it is not a valid adjacency matrix
            throw std::invalid_argument("The matrix is not square");
        }

        for (size_t j = 0; j < adjacency_matrix[i].size(); j++)
        {
            if (adjacency_matrix[i][j] != adjacency_matrix[j][i])
            {
                // If the matrix is not symmetric, the graph is directed
                isDirected = true;
            }
            if (adjacency_matrix[j][j] != 0)
            {
                // If the diagonal is not zero, the matrix is not a valid adjacency matrix
                throw std::invalid_argument("The matrix is not a valid adjacency matrix");
            }
            if (adjacency_matrix[i][j] != 0)
            {
                // If the matrix has a non-zero element, it is an edge
                numOfEdges++;
            }
            if (adjacency_matrix[i][j] < 0){
                // If the matrix has a negative element, the graph has a negative edge
                hasNegativeEdge = true;
            }

            if (adjacency_matrix[i][j] > 1){
                // If the matrix has a non-zero element greater than 1, the graph has a weighted edge
                withoutWhights = false;
            }
        }
    }

    if (!isDirected)
    {
        numOfEdges = numOfEdges / 2;
    }

    this->matrix = adjacency_matrix;
}

// Method to print the graph
void Graph::printGraph()
{
    std::cout << "Graph with " << matrix.size() << " vertices and "<< numOfEdges <<" edges." << std::endl;
    for (size_t i = 0; i < matrix.size(); i++)
    {
        for (size_t j = 0; j < matrix[i].size(); j++)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
  
}

// Method to get the adjacency matrix
std::vector<std::vector<int>> Graph::getMatrix()
{
    return matrix;
}

// Method to get if the graph is directed
bool Graph::getIsDirected()
{
    return isDirected;
}

// Method to get the number of edges
int Graph::getNumOfEdges()
{
    return numOfEdges;
}

// Method to get if the graph has a negative edge
bool Graph::getHasNegativeEdge()
{
    return hasNegativeEdge;
}

// Method to get if the graph has a weighted edge
bool Graph::getWithoutWhights()
{
    return withoutWhights;
}





