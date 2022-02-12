#include "Transition.h"
#include <iostream>
using namespace std;


Transition::Transition(){
    startState = -1;
    endState = -1;
    read = 0;
    write = 0;
    direction = 0;

}

Transition::Transition(int q, char a, int r, char b, char x){
    startState = q;
    read = a;
    endState = r;
    write = b;
    direction = x;

}

int Transition::getStartState(){
    return startState;
}

char Transition::getRead(){
    return read;
}

int Transition::getEndstate(){
    return endState;
}

char Transition::getWrite(){
    return write;
}

char Transition::getDirection(){
    return direction;
}