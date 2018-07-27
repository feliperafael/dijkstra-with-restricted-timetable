#include "timestamp.h"

timestamp::timestamp(int hours, int minutes)
{
    this->setHours(hours);
    this->setMinutes(minutes);
}

int timestamp::getHours(){
    return this->hours;
}

int timestamp::getMinutes(){
    return this->minutes;
}

void timestamp::setHours(int hours){
    this->hours = hours;
}

void timestamp::setMinutes(int minutes){
    this->minutes = minutes;
}

timestamp::~timestamp()
{
    //dtor
}
