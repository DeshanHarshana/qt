#include "libraray.h"

Libraray::Libraray()
{

}
int Libraray::getData(){
    int randomNumber = 1 + (rand() % 100);
    return randomNumber;
}

void Libraray::catchRandom(int number){
    if(number >50){
        emit emitLevel("High");
    }else{
        emit emitLevel("Low");
    }
}
