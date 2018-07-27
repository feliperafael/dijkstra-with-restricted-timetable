#ifndef NODE_H
#define NODE_H
#include "timestamp.h"
#include "edge.h"

class node
{
    public:
        node(int id_node, timestamp * start_restriction, timestamp * end_restriction);

        int getId();
        timestamp * getStartRestrictionTime();
        timestamp * getEndRestrictionTime();
        int getIdPrevious();
        int getDistance();
        bool getEvaluated();
        node * getNextNode();
        edge * getStartEdge();

        void insertEdge(edge * e);
        void print();

        void setId(int id);
        void setStartRestrictionTime(timestamp * time);
        void setEndRestrictionTime(timestamp * time);
        void setIdPrevious(int id);
        void setEvaluated(int evaluated);
        void setNextNode(node * n);
        void setStartEdge(edge * e);

        virtual ~node();

    protected:

    private:
        int id;
        timestamp * start_restriction_time;
        timestamp * end_restriction_time;
        int id_previous;
        int distance;
        int evaluated; // 1 = true - 0 = false
        node * next_node;
        edge * start_edge;
};

#endif // NODE_H
