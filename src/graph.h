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
        node * getNode(int node_id);//returns a pointer to the node with the searched id
        void printGraph();
        virtual ~graph();

    protected:

    private:
        node * it;
        node * start_node;
};

#endif // GRAPH_H
