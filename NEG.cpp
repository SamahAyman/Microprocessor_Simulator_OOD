#include "NEG.h"

NEG::NEG(vector<Operand> s): Instruction(s) 
{}


int NEG::calculate(int inst, Data_mem &data, bool& on) 
{
	int int1 = data.getVar(operation.at(0).getValue());
	int result =  -1*int1; 
	data.setVar(operation.at(1).getValue(), result);

    printf("The SIM just negated memory location %d with value %d \
and stored it in memory location %d now with value %d \n", operation.at(0).getValue(), int1,
        operation.at(1).getValue(), result);

	return inst+1;
}


void NEG::print() //function to print the instruction
{

	cout << "NEG ";
	for (Operand iter : operation)
		cout << iter.getValue() << " ";
	cout << endl;
}

NEG::~NEG() {}
