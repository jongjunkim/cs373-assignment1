#ifndef MACHINE_H
#define MACHINE_H
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include "State.h"
#include "Transition.h"


class Machine{

    private:
        std::string fileName;   //name of file
        std::string input;      //user input
        int max;                //how many it should run
        std::vector<State> Slist;       //store every state
        std::vector<Transition> Tlist;  //store every transition
        int pointer = 0;                
        int currentState = 0;     //tracking of state
        std::vector<char> result;        //output
        std::vector<State> accept;
        std::vector<State> reject;
        std::vector<State> start;


    public:
        Machine(std::string name, std::string in, int loop);
        void readFile();
        std::string run();    
        void showResult();
        void getResult();


        void getaccept();
        void getreject();
        void getStart();
        void getTransition();

     
};

#endif