#include "dataReader.h"

dataReader::dataReader()
{
    //ctor
}

graph * dataReader::readGraph(const string file_path){
    ifstream file;
    file.open(file_path);

    if(file.is_open()){
        int num_nodes, num_edge, sorce_node, destiny_node, departure_time;
        int id_node, start_restriction_time, end_restriction_time;
        file >> num_nodes;
        file >> num_edge;
        file >> sorce_node;
        file >> destiny_node;
        file >> departure_time;

        for(int i = 0; i < num_nodes; i++){
            file >> id_node;
            file >> start_restriction_time;
            file >> start_restriction_time;

        }

    }else{
        cout << "ERROR (1): file doesn't exist" << endl;
        exit(1);
    }
}

dataReader::~dataReader()
{
    //dtor
}
