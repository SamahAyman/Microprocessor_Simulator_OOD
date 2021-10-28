#include "ASI.h"

ASI::ASI(vector<Operand> s) 
    : Instruction(s)
{}


int ASI::calculate(int inst, Data_mem& data, bool& on) 
{
    int in1 = op[0].getValue(); //get int1 address 
    data.setVar(op[1].getValue(), in1);//set out1 = int1 address 
    printf("The SIM just assigned the value of memory location %d to %d \n", op[1].getValue(), in1);
    return inst++;
}


void ASI::print() 
{

	cout << "ASI ";
	for (Operand iter : op)
		cout << iter.getValue() << " ";
	cout << endl;
}

ASI::~ASI(){}
