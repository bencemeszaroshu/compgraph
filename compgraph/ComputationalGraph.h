#pragma once
#include <unordered_map>
#include <vector>

struct IndependentNodes;
struct AdjacenctNodes;

class ComputationalGraph
{
public:
    ComputationalGraph(std::vector<AdjacenctNodes> adjacencyList);
    const std::vector<IndependentNodes>& getIndependentNodesByDepth() const;
private:
    std::vector<int> CalculateBottomNodes();
    std::vector<IndependentNodes> CalculateIndependentNodes();
    std::vector<int> CalculateTopNodes();
    std::vector<AdjacenctNodes> adjacencyList;
    std::vector<int> bottomNodes;
    std::vector<IndependentNodes> independentNodes;
    std::vector<int> topNodes;
};