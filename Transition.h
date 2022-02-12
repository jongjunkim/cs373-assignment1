#ifndef TRANSITION_H
#define TRANSITION_H

class Transition{

    private:
        int startState;
        char read;
        int endState;
        char write;
        char direction;
    
    public:
        Transition();
        Transition(int q, char a, int r, char b, char x);
        int getStartState();
        char getRead();
        int getEndstate();
        char getWrite();
        char getDirection();

};

#endif