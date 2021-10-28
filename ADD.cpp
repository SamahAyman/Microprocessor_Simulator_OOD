
#include "ADD.h"

ADD::ADD(vector <Operand> s): Instruction(s) 
{
	if(s.size() != 3)
        throw invalid_argument("Invalid inputs");
}



int ADD::calculate(int inst, Data_mem &data, bool& on) //execution function for add
{
	int int1 = data.getVar(operation.at(0).getValue());//assign data memory location for int1
	int int2 = data.getVar(operation.at(1).getValue());//assign data memory location for int2
	int out1 = operation.at(2).getValue();//get data memory location for out1
	int result = int1 + int2; //calculate rsults 
	data.setVar(operation.at(2).getValue(), result);//set memory location for out1
    
	printf("The SIM just added memory location %d with value %d & memory location %d \
with value %d and stored it in memory location %d now with value %d \n", operation.at(0).getValue(), int1,
        operation.at(1).getValue(), int2, result, out1);
	
	return inst++;
}

void ADD::print()
{
	cout << "ADD ";
	for (Operand iter : operation)
		cout << iter.getValue() << " ";
	cout << endl;
}

ADD::~ADD() {}
