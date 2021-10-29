#ifndef JP0_H
#define JP0_H
#include "Instruction.h"
using namespace std;

//JP0 function 
class JP0 : public Instruction
{

public:
    //constructor 
    JP0(vector<Operand>);
    int calculate(int , Data_mem& , bool&);
	void print();
    //destructor
    ~JP0();

};

#endif //JP0