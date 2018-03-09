#include "stdafx.h"
#include "ComputationalGraph.h"

ComputationalGraph::ComputationalGraph(std::vector<AdjacentNodes> nodes)
{
    adjacencyList = nodes;
    numberOfNodes = adjacencyList.size();
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
    if (adjacencyList.size() == 0)
    {
        return std::vector<IndependentNodes>();
    }
    if (adjacencyList.size() == 1)
    {
        return std::vector<IndependentNodes>
        { IndependentNodes(0, std::vector<int>{0}) };
    }
    std::vector<IndependentNodes> result;
    int depth = 0;
    result.push_back(IndependentNodes(depth, topNodes));
    ++depth;
    int numberOfNodesLeft = numberOfNodes - topNodes.size() - bottomNodes.size();
    if (numberOfNodesLeft < 0)
    {
        return result;
    }
    while(numberOfNodesLeft > 0)
    {
        IndependentNodes independentNodes(depth);
        int previousDepth = depth - 1;
        for (unsigned int i = 0; i < result[previousDepth].nodes.size(); ++i)
        {
            int currentNode = result[previousDepth].nodes[i];
            std::vector<int>& adjacentNodes = adjacencyList[currentNode].adjacentNodes;
            for (unsigned int j = 0; j < adjacentNodes.size(); ++j)
            {
                int node = adjacentNodes[j];
                auto it1 = std::find(bottomNodes.begin(), bottomNodes.end(), node);
                auto it2 = std::find(independentNodes.nodes.begin(), independentNodes.nodes.end(), node);
                if (it1 == bottomNodes.end() && it2 == independentNodes.nodes.end())
                {
                    independentNodes.nodes.push_back(node);
                }
            }
            --numberOfNodesLeft;
        }
        result.push_back(independentNodes);
        ++depth;
    }
    result.push_back(IndependentNodes(depth, bottomNodes));
    return result;
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
