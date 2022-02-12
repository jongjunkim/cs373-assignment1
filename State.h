#ifndef STATE_H
#define STATE_H
#include <string>


class State{

    private:
        int stateNumber;
        std::string type;

    public:
        State();
        State(int n, std::string t);
        int getStateNumber();
        std::string getType();
      


};

#endif