#include <iostream>
#include <limits>

using namespace std;
#define INFINITY std::numeric_limits<double>::infinity()
#include  "dataReader.h"
#include "graph.h"
#include "timestamp.h"

float classic_dijkstra(graph * g, int id_source, int id_destiny, timestamp * departure_time, int num_nodes);
float dijkstra_timetable(graph * g, int id_source, int id_destiny, timestamp * departure_time, int num_nodes);
float dijkstra(graph * g, int id_source, int id_destiny, timestamp * departure_time, int num_nodes);

void print_minutos_2_hours(int minute){
    cout << (minute%1440)/60 << ":" << (minute%1440)%60;
}

void print_resp(node * n, graph * g, int dest_id){
    if(n->getIdPrevious() == -1){
        cout << n->getId() << " -> ";
    }else{
        print_resp(g->getNode(n->getIdPrevious()), g, dest_id);
        cout << n->getId();
        if(dest_id != n->getId())
            cout << " -> ";
    }

}

int main()
{
    dataReader * reader = new dataReader();
    graph * g = reader->readGraph("input/example_input_file.dat");
    g->printGraph();

    cout << "\nLeaving at ";
    reader->departure_time->print();
    cout << endl;

    dijkstra_timetable(g, reader->sorce_node, reader->destiny_node, reader->departure_time, reader->num_nodes);


    print_resp(g->getNode(reader->destiny_node),  g, reader->destiny_node);



    delete g;
    return 0;
}


float dijkstra_timetable(graph * g, int id_source, int id_destiny, timestamp * departure_time, int num_nodes){

    int cost[num_nodes]; // para chegar ao no de origem

    timestamp * hora_atual = new timestamp(departure_time->getHours(), departure_time->getMinutes());
    int minuto_saida = departure_time->in_minutes();
    int minuto_atual = hora_atual->in_minutes();
    int minuto_chegada = 0;
    int distancia = 0;

    //initializes the cost vector
    for(int i = 0; i < num_nodes; i++){
        if(i == id_source-1){
            g->getNode(i+1)->setDistance(departure_time->in_minutes());
        }else{
            g->getNode(i+1)->setDistance(INFINITY);
        }
    }

    g->start(); // coloca o grafo no inicio
    edge * e;


    g->current()->setDistance(departure_time->in_minutes() + g->current()->time_waiting(departure_time->in_minutes()));
    node * no;
    edge * aresta;

    while( g->visited() == false ){ // enquanto todo o grafo nao tiver sido visitado
        no = (g->current());

        no->start(); // pega o no atual do grafo e coloca o iterador de arestas no inicio

        while(no->current() != NULL){ // percorre as arestas

            //cout << "("<< g->current()->current()->getIdDestinyNode() << "," << g->current()->current()->getWeight()*60<< ")";
            distancia = no->current()->getWeight()*60;//custo aresta
            // custo  de esperar
            minuto_chegada = (no->getDistance() + no->current()->getWeight()*60) % 1440; // minuto relativo ao inicio do dia
            distancia += g->getNode(no->current()->getIdDestinyNode())->time_waiting( minuto_chegada ) ;
            //quanto já custava
            distancia += no->getDistance();
            if(g->getNode(no->current()->getIdDestinyNode())->getDistance() > distancia){
                g->getNode(no->current()->getIdDestinyNode())->setIdPrevious(g->current()->getId()); // pego o nó de destino é seto como predecessor dele o no atual
                g->getNode(no->current()->getIdDestinyNode())->setDistance(distancia);
            }


            no->next();
        }
        g->current()->setEvaluated(true);
        g->next();
        no = g->current();
    }

    cout << "HORA DA CHEGADA: ";
    print_minutos_2_hours(g->getNode(num_nodes)->getDistance());
    cout << endl;
    cout << "CUSTO TOTAL EM HORAS: " << (g->getNode(num_nodes)->getDistance() - departure_time->in_minutes())/60  << ":" <<  (g->getNode(num_nodes)->getDistance() - departure_time->in_minutes())%60;
    cout << endl;
}

float dijkstra(graph * g, int id_source, int id_destiny, timestamp * departure_time, int num_nodes){

    int cost[num_nodes]; // para chegar ao no de origem

    timestamp * hora_atual = new timestamp(departure_time->getHours(), departure_time->getMinutes());
    int minuto_saida = departure_time->in_minutes();
    int minuto_atual = hora_atual->in_minutes();
    int minuto_chegada = 0;
    int distancia = 0;

    //initializes the cost vector
    for(int i = 0; i < num_nodes; i++){
        if(i == id_source-1){
            cost[i] = departure_time->in_minutes();
        }else{
            cost[i] = INFINITY;
        }
    }

    g->start(); // coloca o grafo no inicio
    edge * e;


    cost[g->current()->getId()-1] = departure_time->in_minutes() + g->current()->time_waiting(departure_time->in_minutes());

    while( g->visited() == false ){ // enquanto todo o grafo nao tiver sido visitado

        (g->current())->start(); // pega o no atual do grafo e coloca o iterador de arestas no inicio

        while(g->current()->current() != NULL){ // percorre as arestas

            //cout << "("<< g->current()->current()->getIdDestinyNode() << "," << g->current()->current()->getWeight()*60<< ")";
            distancia = g->current()->current()->getWeight()*60;//custo aresta
            // custo  de esperar
            minuto_chegada = (cost[g->current()->getId() -1] + g->current()->current()->getWeight()*60) % 1440;
            distancia += g->getNode(g->current()->current()->getIdDestinyNode())->time_waiting( minuto_chegada ) ;
            //quanto já custava
            distancia += cost[g->current()->getId()-1];
            if(cost[g->current()->current()->getIdDestinyNode() -1] > distancia){
                g->getNode(g->current()->current()->getIdDestinyNode())->setIdPrevious(g->current()->getId()); // pego o nó de destino é seto como predecessor dele o no atual
                cost[g->current()->current()->getIdDestinyNode() -1] = distancia;
            }


            g->current()->next();
        }
        g->current()->setEvaluated(true);
        g->next();
    }

    cout << "HORA DA CHEGADA: ";
    print_minutos_2_hours(cost[num_nodes-1]);
    cout << endl;

    cout << "CUSTO TOTAL EM HORAS: ";
    print_minutos_2_hours(cost[num_nodes-1] - departure_time->in_minutes());
    cout << endl;
}

/**
    Classic Dijkstra
**/

float classic_dijkstra(graph * g, int id_source, int id_destiny, timestamp * departure_time, int num_nodes){

    float cost[num_nodes]; // para chegar ao no de origem

    //initializes the cost vector
    for(int i = 0; i < num_nodes; i++){
        if(i == id_source-1){
            cost[i] = 0;
        }else{
            cost[i] = INFINITY;
        }
    }

    g->start(); // coloca o grafo no inicio
    edge * e;
    while( g->visited() == false ){ // enquanto todo o grafo nao tiver sido visitado

        (g->current())->start(); // pega o no atual do grafo e coloca o iterador de arestas no inicio

        while(g->current()->current() != NULL){ // percorre as arestas

            cout << "("<< g->current()->current()->getIdDestinyNode() << "," << g->current()->current()->getWeight()<< ")";

            if(cost[g->current()->current()->getIdDestinyNode() -1] > cost[g->current()->getId()-1] + g->current()->current()->getWeight()){
                g->getNode(g->current()->current()->getIdDestinyNode())->setIdPrevious(g->current()->getId()); // pego o nó de destino é seto como predecessor dele o no atual
                cost[g->current()->current()->getIdDestinyNode() -1] = cost[g->current()->getId()-1] + g->current()->current()->getWeight();
            }

            g->current()->next();
        }
        g->current()->setEvaluated(true);
        g->next();
    }
    cout << "\n\n****** COST ******** \n";
    for(int i = 0; i < num_nodes; i++){
       cout << "( " << i+1 << " , cost = " <<  cost[i] << ", previous = " << g->getNode(i+1)->getIdPrevious() << " ) ";
    }
}

