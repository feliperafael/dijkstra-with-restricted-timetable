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
        virtual ~timestamp();

    protected:

    private:
        int hours;
        int minutes;
};

#endif // TIMESTAMP_H
