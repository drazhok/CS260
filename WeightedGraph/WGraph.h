
//
//  Graph.hpp
//  Example Non-directed, non-weighted graph
//
//  Created by Jim Bailey on 11/25/17.
//  Licensed under a Creative Commons Attribution 4.0 International License.
//

#ifndef GRAPH_H
#define GRAPH_H

#include <string>

struct Edge
{
    int endIndex;
    int weight;
    Edge * next;
};

struct Node
{
    char name;
    bool visited;
    Edge * connects;
};

class WGraph
{
    public:
        WGraph();
        virtual ~WGraph();

        void addNode(char name);
        bool addWEdge(char startName, char endName, int weight);

        std::string minCostTree(char start);

        std::string listNodes();
        std::string displayWEdges();
        std::string displayMatrix();

        std::string breadthFirst(char name);
        std::string depthFirst(char name);

    private:
        static const int SIZE = 20;
        int numNodes;
        Node * nodeList[SIZE];
        int edgeMatrix[SIZE][SIZE];

        int findNode(char name);
        void resetVisited();
};

#endif
