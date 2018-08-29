#ifndef TIMESTAMP_H
#define TIMESTAMP_H
#include <iostream>

using namespace std;

class timestamp
{
    public:
        timestamp(int hours, int minutes);
        void setHours(int hours);
        void setMinutes(int minutes);
        int getHours();
        int getMinutes();
        void print();

        int compare(timestamp * t);
        int diff(timestamp * t);
        void add_minutes(int m);
        int in_minutes(); //retorna os minutos do dia


        virtual ~timestamp();

    protected:

    private:
        int hours;
        int minutes;
};

#endif // TIMESTAMP_H
