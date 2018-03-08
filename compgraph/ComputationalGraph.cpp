#include "stdafx.h"
#include "ComputationalGraph.h"


ComputationalGraph::ComputationalGraph(std::vector<AdjacentNodes> nodes)
{
    adjacencyList = nodes;
    numberOfNodes = adjacencyList.size();
    bottomNodes = CalculateBottomNodes();
    //topNodes = CalculateTopNodes();
    //independentNodes = CalculateIndependentNodes();
}

const std::vector<IndependentNodes>& ComputationalGraph::getIndependentNodesByDepth() const
{
    return independentNodes;
}

std::vector<int> ComputationalGraph::CalculateBottomNodes()
{
    std::vector<int> bottomNodes;
    for (unsigned int node = 0; node < numberOfNodes; ++node)
    {
        if(adjacencyList[node].adjacentNodes.empty())
        {
            bottomNodes.push_back(node);
        }
    }
    return bottomNodes;
}

std::vector<IndependentNodes> ComputationalGraph::CalculateIndependentNodes()
{
    return std::vector<IndependentNodes>();
}

std::vector<int> ComputationalGraph::CalculateTopNodes()
{

    std::unordered_set<int> nodesWithParent;
    for (unsigned int i = 0; i < numberOfNodes; ++i)
    {
        for (int j = 0; j < adjacencyList[i].adjacentNodes.size(); ++j)
        {
            nodesWithParent.insert(adjacencyList[i].adjacentNodes[j]);
        }
    }
    std::vector<int> topNodes;
    for (unsigned int node = 0; node < numberOfNodes; ++node)
    {
        if (nodesWithParent.find(node) == nodesWithParent.end())
        {
            topNodes.push_back(node);
        }
    }
    return topNodes;
}
