#include "edge.h"

edge::edge(int destiny_id, int weight)
{
    this->setIdDestinyNode(destiny_id);
    this->setWeight(weight);
}

int edge::getIdDestinyNode(){
	return this->id_destiny_node;
}
int edge::getWeight(){
	return this->weight;
}
edge * edge::getNextEdge(){
	return this->next_edge;
}

void edge::setIdDestinyNode(int id){
	this->id_destiny_node = id;
}
void edge::setWeight(int weight){
	this->weight = weight;
}
void edge::setNextEdge(edge * e){
	this->next_edge = e;
}

edge::~edge()
{
    //dtor
}
