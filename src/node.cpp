#include "node.h"

//constructor for node
node::node(int id_node, timestamp * start_restriction, timestamp * end_restriction)
{
    this->id = id_node;
    this->start_restriction_time = start_restriction;
    this->end_restriction_time = end_restriction;
}

void node::insertEdge(edge * e){

    if(this->start_edge != NULL){
        edge * aux = this->start_edge;

        while(aux->getNextEdge() != NULL){
            aux = aux->getNextEdge();
        }
        aux->setNextEdge(e);
    }else{
        this->setStartEdge(e);
    }
}

void node::print(){
    edge * e = this->getStartEdge();

    cout << this->getId() << " -> [ ";
    while( e != NULL ){
        cout << "(" << e->getIdDestinyNode() << ", " << e->getWeight() << ")";
        e = e->getNextEdge();
        if(e != NULL){
            cout << ", ";
        }
    }
    cout << " ] " << endl;
}

int node::getId(){
    return this->id;
}
timestamp * node::getStartRestrictionTime(){
    return this->start_restriction_time;
}
timestamp * node::getEndRestrictionTime(){
    return this->end_restriction_time;
}
int node::getIdPrevious(){
    return this->id_previous;
}
int node::getDistance(){
    return this->distance;
}
bool node::getEvaluated(){
    return this->evaluated;
}
node * node::getNextNode(){
    return this->next_node;
}
edge * node::getStartEdge(){
    return this->start_edge;
}

void node::setId(int id){
    this->id = id;
}

void node::setStartRestrictionTime(timestamp * time){
    this->start_restriction_time = time;
}
void node::setEndRestrictionTime(timestamp * time){
    this->end_restriction_time = time;
}
void node::setIdPrevious(int id){
    this->id_previous = id;
}
void node::setEvaluated(int evaluated){
    this->evaluated = evaluated;
}
void node::setNextNode(node * n){
    this->next_node = n;
}
void node::setStartEdge(edge * e){
    this->start_edge = e;
}

node::~node()
{
    edge * e = this->start_edge;

    while(e != NULL){
        edge * temp = e->getNextEdge();
        delete e;
        e = temp;
    }
}
