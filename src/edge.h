#ifndef EDGE_H
#define EDGE_H


class edge
{
    public:
        edge(int destiny_id, int weight);

        int getIdDestinyNode();
        int getWeight();
        edge * getNextEdge();

        void setIdDestinyNode(int id);
        void setWeight(int weight);
        void setNextEdge(edge * e);

        virtual ~edge();

    protected:

    private:
        int id_destiny_node;
        int weight;
        edge * next_edge;
};

#endif // EDGE_H
