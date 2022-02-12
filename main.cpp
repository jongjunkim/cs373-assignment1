#include <iostream>
#include <string>
#include "Machine.h"
using namespace std;



int main(int argc, char* argv[]){
   
  
   Machine m1 = *new Machine(argv[1], argv[2], atoi(argv[3]));
   m1.readFile();
   m1.showResult();
   
   

   


    
    
  



    return 0;
}