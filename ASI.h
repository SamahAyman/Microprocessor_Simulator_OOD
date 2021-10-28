#ifndef ASI_H
#define ASI_H
#include "Instruction.h"
using namespace std;

//ASI function class derived from instrauction class 
class ASI : public Instruction
{

public:
    //constructor 
    ASI(vector<Operand>);
    
    //print the input operation line 
    void print();

    //Assigns a constant value to a variable
    int calculate(int, Data_mem& , bool& on);
    //destructor
    ~ASI();

};

#endif