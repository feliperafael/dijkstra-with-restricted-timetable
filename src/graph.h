#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include "node.h"

using namespace std;

class graph
{
    public:
        graph();
        void insertNode(node * n);
        bool visited(); //returns true if all nodes are marked as visited
        node * getNode(int node_id);//returns a pointer to the node with the searched id
        void printGraph();
        void start();
        void next();
        node * current();
        virtual ~graph();

    protected:

    private:
        node * it;
        node * start_node;
};

#endif // GRAPH_H
