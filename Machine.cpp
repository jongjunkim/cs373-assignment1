#include "Machine.h"
#include <iostream>
using namespace std;


Machine::Machine(std::string name, std::string in, int loop){
    fileName = name;
    input = in;
    max = loop;
    
    for(int i = 0; i<input.length(); i++){
        result.push_back(input[i]);
    }
}

void Machine::readFile(){

    ifstream fin(fileName); 

	string line;
    string state;
    int number;
    string type;

    int startState;
    char read;
    int endState;
    char write;
    char direction;

    while(getline(fin, line)){
         
        if(line[0] == 's'){ // state
            stringstream ss(line);
            ss>> state >> number >> type;

            if(type == "start"){
                start.push_back(*new State(number ,type)); //store start state
                //cout << "Start State: " << state << number <<type << endl; ///////////////////////// no
            }else if(type == "accept"){
                accept.push_back(*new State(number ,type));  //store accept state;
                //cout << "Accept State: " << state << number <<type << endl; /////////// no
            }else if(type == "reject"){
                reject.push_back(*new State(number ,type));  //store reject state;
                //cout << "Reject Sate: " << state << number <<type << endl;  /////////////////////////////////////nmo
            }else{
                type = "";
                Slist.push_back(*new State(number ,type));  //store stae;
                //cout << "State: " << state << number << type << endl;
            }
            type ="";
        }else{   //transition 
            string t;
            stringstream ss(line);
            ss >> t >> startState >> read >> endState >> write >> direction;
            //cout << "transition" << startState << read << endState << write << direction << endl;
            
            if(read == '_')
                read = ' ';
            if(write == '_')
                write = ' ';
            
            Tlist.push_back(*new Transition(startState, read, endState, write, direction ));
            

        }
    }
    fin.close();
}


string Machine::run(){

    currentState = start.at(0).getStateNumber();
    int run = 0;    

    while(run < max){

        for(int i = 0; i<Tlist.size(); i++){
            if(Tlist.at(i).getStartState() == currentState){
                if(Tlist.at(i).getRead() == result.at(pointer)){

                    currentState = Tlist.at(i).getEndstate();     //tracking currentState
                    result.at(pointer) = Tlist.at(i).getWrite();  //overwrite
                
                    
                    //move right or left
                    if(Tlist.at(i).getDirection() == 'R')     
                        pointer++;
                    else if(Tlist.at(i).getDirection() == 'L')
                        pointer--;

                    if(pointer >= result.size())  //if size is not enough 
                        result.push_back(' ');  
                      
                    
                    break; //if found 
                }
            }
        }

        for(int i = 0; i< accept.size(); i++){
            if(currentState == accept.at(i).getStateNumber())
                return "accept";
        }

        for(int i = 0; i<reject.size(); i++){
            if(currentState == reject.at(i).getStateNumber())
                return "reject";
        }

        for(int i = 0; i<result.size(); i++){
            if(result.at(i) == 2)
                return "reject2";
        }

        run++;  
    }  
    return "quit";  
}


void Machine::showResult(){
    
    string state = run();

    if(state == "reject2"){
        for(int i = pointer; i<result.size(); i++){
            cout<<result.at(i);
       }
        cout << " " << "reject" << endl;
    }else{
        for(int i = pointer; i<result.size(); i++){
            cout << result.at(i);
        }
        cout <<  " " << state << endl;
    }
}

void Machine::getResult(){

    for(int i = 0; i<result.size(); i++){
        cout << result.at(i);
    }


}

void Machine::getaccept(){
    for(int i = 0; i<accept.size(); i++){
        cout << accept.at(i).getStateNumber();   
    }

}
    



   
       


