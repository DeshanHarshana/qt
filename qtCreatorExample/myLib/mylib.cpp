#include "mylib.h"

MyLib::MyLib()
{
}
int MyLib::getData(){
    int randomNumber = 1 + (rand() % 100);
    return randomNumber;
}

void MyLib::catchRandom(int number){
    if(number >50){
        emit emitLevel("High");
    }else{
        emit emitLevel("Low");
    }
}
