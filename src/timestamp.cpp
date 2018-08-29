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

void timestamp::print(){
    cout << this->getHours() << ":" << this->getMinutes();
}

/**
    returns 1 if the parameter is greater than the timestamp of object 0 if it is equal and -1 if it is smaller
*/
int timestamp::compare(timestamp * t){

    if(t->getHours() > this->getHours()){
        return 1;
    }else if(t->getHours() < this->getHours()){
        return -1;
    }else{
        if(t->getMinutes() > this->getMinutes()){
            return 1;
        }else if( t->getMinutes() < this->getMinutes()){
            return -1;
        }else{
            return 0;
        }
    }
}
/**
    returns the difference in minutes between the timestamp of the object is the parameter
*/
int timestamp::diff(timestamp *t){
    int diff_hours = t->getHours() - this->getHours();
    int diff_minutes = t->getMinutes() - this->getMinutes();

    if(diff_hours < 0)
        diff_hours += 24;
    if(diff_minutes < 0)
        diff_minutes += 60;

    return (60*diff_hours + diff_minutes);
}

int timestamp::in_minutes(){
    return 60*this->getHours() + this->getMinutes();

}


/**
    receives a value in minutes and adds to timestamp
*/
void timestamp::add_minutes(int m){
    int horas =  this->getHours() + (int)m/60;
    int minutos = (this->getMinutes() + m%60) % 60;
    if((this->getMinutes() + m%60) >= 60)
        horas +=1;
    horas += (int)minutos/60;
    horas = horas %24;
    this->setHours(horas);
    this->setMinutes(minutos);
}
timestamp::~timestamp()
{
    //dtor
}
