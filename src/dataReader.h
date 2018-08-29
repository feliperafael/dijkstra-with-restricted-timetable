#ifndef DATAREADER_H
#define DATAREADER_H

#include <iostream>
#include <fstream>
#include <string>
#include "graph.h"
#include "timestamp.h"
/*
    Description: This class is responsible for reading data from the input file.
*/

using namespace std;

class dataReader
{
    public:
        dataReader();

        int num_nodes, num_edges, sorce_node, destiny_node;

        timestamp * departure_time;

        graph * readGraph(const string file_path);
        virtual ~dataReader();

    protected:

    private:
};

#endif // DATAREADER_H
