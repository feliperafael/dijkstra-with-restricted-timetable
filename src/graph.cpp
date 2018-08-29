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

void graph::start(){
    this->it = this->start_node;
}
void graph::next(){
    this->it = it->getNextNode();
}

node * graph::current(){
    return this->it;
}

bool graph::visited(){
    node * s = this->start_node;

    while(s != NULL){
        if(s->getEvaluated() != true){
            return false;
        }
        s = s->getNextNode();
    }
    return true;
}

void graph::printGraph(){
    node * n = this->start_node;
    cout << "( id, weight )\n";
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
