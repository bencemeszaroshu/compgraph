// compgraph.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "ComputationalGraph.h"
#include <iostream>
#include <sstream>
#include <string>

std::vector<AdjacentNodes> ProcessInput(std::istream& input);
void PrintIndependentNodes(std::ostream& output, std::vector<IndependentNodes> independentNodes);

int main()
{
    return 0;
}

std::vector<AdjacentNodes> ProcessInput(std::istream& input)
{
    int numberOfNodes;
    input >> numberOfNodes;
    input.ignore(1, '\n');
    std::vector<AdjacentNodes> adjacencyList;
    for (unsigned int i = 0; i < numberOfNodes; ++i)
    {
        std::string temp;
        std::getline(input, temp);
        bool emptyLine = temp.length() == 0;
        AdjacentNodes node(i);
        if (!emptyLine)
        {
            std::istringstream line(temp);
            while (!line.eof())
            {
                int adjacentNode;
                line >> adjacentNode;
                node.adjacentNodes.push_back(adjacentNode);
            }
        }
        adjacencyList.push_back(node);
    }
    return adjacencyList;
}

void PrintIndependentNodes(std::ostream & output, std::vector<IndependentNodes> independentNodes)
{
    for (const auto& level : independentNodes)
    {
        output << level.depthLevel << ": ";
        for (const auto& node : level.nodes)
        {
            output << node << " ";
        }
        output << "\n";
    }
}

