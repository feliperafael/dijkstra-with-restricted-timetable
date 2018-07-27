#include "graph.h"
//constructor for graph
graph::graph()
{
    this->it = NULL;
    this->start_node = NULL;
}

node * graph::getNode(int node_id){
    node * n = this->start_node;

    while(node_id != n->getId()) {
            n = n->getNextNode();
    }
    return n;
}

void graph::insertNode(node * n){
    if(this->start_node != NULL){
        node * aux = this->start_node;

        while(aux->getNextNode() != NULL){
            aux = aux->getNextNode();
        }
        aux->setNextNode(n);
    }else{
        this->start_node = n;
    }

}

void graph::printGraph(){
    node * n = this->start_node;

    if( n != NULL ){
        while( n->getNextNode() != NULL ){
            n->print();
            n = n->getNextNode();
        }
    }else{
        cout << "ERROR (2) : Empty graph" << endl;
    }

}

//destructor for graph
graph::~graph()
{
    node * n = this->start_node;

    while(n != NULL){
        node * temp = n->getNextNode();
        delete n;
        n = temp;
    }
}
