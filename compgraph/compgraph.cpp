// compgraph.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "ComputationalGraph.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

std::vector<AdjacentNodes> ProcessInput(std::istream& input);
void PrintIndependentNodes(std::ostream& output, std::vector<IndependentNodes> independentNodes);

int main(int argc, char* argv[])
{
    if (argc < 3)
    {
        std::cout << std::endl << "Usage: compgraph.exe <INPUTFILE> <OUTPUTFILE>" << std::endl;
        return 1;
    }
    std::ifstream inputFile(argv[1]);
    std::vector<AdjacentNodes> adjacencyList;
    if (inputFile.is_open())
    {
        adjacencyList = ProcessInput(inputFile);
    }
    else
    {
        std::cout << std::endl << "Couldn't open input file" << std::endl;
        return 1;
    }
    ComputationalGraph computationalGraph(adjacencyList);
    std::ofstream resultFile(argv[2]);
    if (resultFile.is_open())
    {
        PrintIndependentNodes(resultFile, computationalGraph.getIndependentNodesByDepth());
    }
    else
    {
        std::cout << std::endl << "Couldn't open output file" << std::endl;
        return 1;
    }
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
        output << level.depth << ": ";
        for (const auto& node : level.nodes)
        {
            output << node << " ";
        }
        output << "\n";
    }
}

