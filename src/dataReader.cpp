#include "dataReader.h"

dataReader::dataReader()
{
    //ctor
}

graph * dataReader::readGraph(const string file_path){
    graph * g = NULL;
    ifstream file;
    file.open(file_path);

    if(file.is_open()){
        g = new graph();
        int id_node;
        string start_restriction_time, end_restriction_time;
        string departureTime;

        file >> this->num_nodes;
        file >> this->num_edges;
        file >> this->sorce_node;
        file >> this->destiny_node;
        file >> departureTime;

        this->departure_time = new timestamp(stoi(departureTime.substr(0, 2)), stoi(departureTime.substr(2, 4)));

        timestamp *start_restriction, *end_restriction;

        //for nodes
        for(int i = 0; i < this->num_nodes; i++){
            file >> id_node;
            file >> start_restriction_time;
            file >> end_restriction_time;

            start_restriction = new timestamp(stoi(start_restriction_time.substr(0, 2)), stoi(start_restriction_time.substr(2, 4)));
            end_restriction = new timestamp(stoi(end_restriction_time.substr(0, 2)), stoi(end_restriction_time.substr(2, 4)));

            g->insertNode(new node(id_node, start_restriction, end_restriction));
        }

        //for edges
        int origin_id, destiny_id, weight;
        node * n;
        for(int i = 0; i < this->num_edges; i++){
            file >> origin_id;
            file >> destiny_id;
            file >> weight;

            n = g->getNode(origin_id);
            n->insertEdge( new edge(destiny_id, weight) );
        }

    }else{
        cout << "ERROR (1): file doesn't exist" << endl;
        exit(1);
    }

    return g;
}

dataReader::~dataReader()
{
    //dtor
}
