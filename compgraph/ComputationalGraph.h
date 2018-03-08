#pragma once
#include <unordered_map>
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
    std::vector<int> topNodes;
};

struct IndependentNodes {
    IndependentNodes(int depthLevel) : depthLevel(depthLevel) {};
    IndependentNodes(int depthLevel, std::vector<int> nodes)
        : depthLevel(depthLevel), nodes(nodes) {};
    int depthLevel;
    std::vector<int> nodes;
};

struct AdjacentNodes {
    AdjacentNodes(int node) : node(node) {};
    AdjacentNodes(int node, std::vector<int> adjacentNodes) : node(node),
        adjacentNodes(adjacentNodes) {};
    int node;
    std::vector<int> adjacentNodes;
};