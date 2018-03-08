#pragma once
#include <algorithm>
#include <iterator>
#include <unordered_map>
#include <unordered_set>
#include <vector>

struct IndependentNodes;
struct AdjacentNodes;

class ComputationalGraph
{
public:
    ComputationalGraph(std::vector<AdjacentNodes> adjacencyList);
    const std::vector<IndependentNodes>& getIndependentNodesByDepth() const;
private:
    std::vector<int> CalculateBottomNodes();
    std::vector<IndependentNodes> CalculateIndependentNodes();
    std::vector<int> CalculateTopNodes();
    std::vector<AdjacentNodes> adjacencyList;
    std::vector<int> bottomNodes;
    std::vector<IndependentNodes> independentNodes;
    unsigned int numberOfNodes;
    std::vector<int> topNodes;
};

struct AdjacentNodes {
    AdjacentNodes(int node) : node(node) {};
    AdjacentNodes(int node, std::vector<int> adjacentNodes) : node(node),
        adjacentNodes(adjacentNodes) {};
    int node;
    std::vector<int> adjacentNodes;
};

struct IndependentNodes {
    IndependentNodes(int depth) : depth(depth) {};
    IndependentNodes(int depth, std::vector<int> nodes)
        : depth(depth), nodes(nodes) {};
    int depth;
    std::vector<int> nodes;
};