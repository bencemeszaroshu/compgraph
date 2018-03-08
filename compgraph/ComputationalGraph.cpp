#include "stdafx.h"
#include "ComputationalGraph.h"


ComputationalGraph::ComputationalGraph(std::vector<AdjacenctNodes> nodes)
{
    adjacencyList = nodes;
    bottomNodes = CalculateBottomNodes();
    topNodes = CalculateTopNodes();
    independentNodes = CalculateIndependentNodes();
}

const std::vector<IndependentNodes>& ComputationalGraph::getIndependentNodesByDepth() const
{
    return independentNodes;
}

std::vector<int> ComputationalGraph::CalculateBottomNodes()
{
    return std::vector<int>();
}

std::vector<IndependentNodes> ComputationalGraph::CalculateIndependentNodes()
{
    return std::vector<IndependentNodes>();
}

std::vector<int> ComputationalGraph::CalculateTopNodes()
{
    return std::vector<int>();
}

struct IndependentNodes {
    IndependentNodes(int depthLevel, std::vector<int> nodes)
        : depthLevel(depthLevel), nodes(nodes) {};
    int depthLevel;
    std::vector<int> nodes;
};

struct AdjacenctNodes {
    AdjacenctNodes(int level, std::vector<int> nodes) : level(level), nodes(nodes) {};
    int level;
    std::vector<int> nodes;
};