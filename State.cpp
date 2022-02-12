#include "State.h"
#include <iostream>
using namespace std;


State::State(){
    stateNumber = -1;
    type = "";
}


State::State(int n, string t){
    stateNumber = n;
    type = t;
}

int State::getStateNumber(){

    return stateNumber;
}

string State::getType(){
    
    return type;
}