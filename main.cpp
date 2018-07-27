#include <iostream>

using namespace std;
#include  "dataReader.h"
#include "graph.h"
int main()
{
    dataReader * reader = new dataReader();
    graph * g = reader->readGraph("input/example_input_file.dat");
    g->printGraph();
    delete g;
    return 0;
}
