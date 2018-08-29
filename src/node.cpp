#include "node.h"

//constructor for node
node::node(int id_node, timestamp * start_restriction, timestamp * end_restriction)
{
    this->id = id_node;
    this->start_restriction_time = start_restriction;
    this->end_restriction_time = end_restriction;
    this->setIdPrevious(-1);// o precedente é -1
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

/***
    checks whether a timestamp is within the node restriction schedule
***/
bool node::check_range_restricion(timestamp * t){
    // analiso o minuto do dia
    int minuto_atual = t->in_minutes();
    int minuto_inicio_restricao = this->getStartRestrictionTime()->in_minutes();
    int minuto_final_restricao  = this->getEndRestrictionTime()->in_minutes();

   if( minuto_atual >= minuto_inicio_restricao && minuto_atual <= minuto_final_restricao){
        return true;
   }
   return false;

}
/**
    verifica se um minuto está na restrição
    se estiver retorna o numero de minutos esperando
*/
int node::check_range_restricion_minute(int m){
    int minuto_inicio_restricao = this->getStartRestrictionTime()->in_minutes();
    int minuto_final_restricao  = this->getEndRestrictionTime()->in_minutes();

   if( m >= minuto_inicio_restricao && m <= minuto_final_restricao){
        return minuto_final_restricao-m;
   }
   return 0;
}

int node::time_waiting(int m){
   int minuto_inicio_restricao = this->getStartRestrictionTime()->in_minutes();
   int minuto_final_restricao  = this->getEndRestrictionTime()->in_minutes();

   if( m >= minuto_inicio_restricao && m <= minuto_final_restricao){
        return minuto_final_restricao-m;
   }
   return 0;

}

void node::print(){
    edge * e = this->getStartEdge();
    cout << this->getId() << " { ";
    this->getStartRestrictionTime()->print();
    cout << " ";
    this->getEndRestrictionTime()->print();
    cout << " } -> [ ";
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
void node::setEvaluated(bool evaluated){
    this->evaluated = evaluated;
}
void node::setNextNode(node * n){
    this->next_node = n;
}
void node::setStartEdge(edge * e){
    this->start_edge = e;
}
void node::setDistance(int d){
    this->distance = d;
}
/**
    coloca o iterador das arestas no inicio
**/
void node::start(){
    this->it = start_edge;
}

void node::next(){
    this->it = this->it->getNextEdge();
}

edge * node::current(){
    return this->it;
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
