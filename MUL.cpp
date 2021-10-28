#include "MUL.h"

MUL::MUL(vector <Operand> s): Instruction(s) 
{
	if(s.size() != 3)
        throw invalid_argument("Invalid inputs");
   
}



int MUL::excute(int inst, Data_mem &data, bool& on)
{

	int int1 = data.getVar(operation.at(0).getValue());
	int inst2 = data.getVar(operation.at(1).getValue());
	int result =int1*inst2 ; 
	data.setVar(operation.at(2).getValue(),result );

//detailed instruction execution proccess 
	    printf("The SIM just multiplied memory location %d with value %d & memory \
location %d with value %d and stored it in memory location %d now with value %d \n", 
        operation.at(0).getValue(), int1, operation.at(1).getValue(), int2, operation.at(2).getValue(), result);
	
	return inst++;
}


//function printing 
{
void MUL::print() 

	cout << "MUL ";
	for (Operand iter : op)
		cout << iter.getValue() << " ";
	cout << endl;
}
MUL::~MUL() {}