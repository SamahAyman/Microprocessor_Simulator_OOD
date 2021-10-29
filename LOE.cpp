#include "LOE.h"

LOE::LOE(vector <Operand> s): 
		Instruction(s) 
{}



int LOE::excute(int inst, Data_mem &data, bool& on) 
{
	int in1 = data.getVar(op.at(0).getValue());
	int in2 = data.getVar(op.at(1).getValue());
	

  if (in1 <= in2)
    {
        data.setVar(operation.at(2).getValue(), 1);
        printf("The SIM just assigned the value of memory location %d to 1 \n", operation.at(2));
    }
    else
    {
        data.setVar(operation.at(2).getValue(), 0);
        printf("The SIM just assigned the value of memory location %d to 0 \n", operation.at(2));
    }

	return inst+1;
}


void LOE::print() //function to print the instruction
{

	cout << "LOE ";
	for (Operand iter : operation)
		cout << iter.getValue() << " ";
	cout << endl;
}
LOE::~LOE()
{
}