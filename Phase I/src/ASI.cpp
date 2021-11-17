#include "ASI.h" 
#include "DataMemory.h"
#include <iostream>
using namespace std;

//constructor
ASI::ASI(vector<Operand> inst): Instruction(inst)
{
	//validation on the number of parameters
	if (inst.size() != 2)
		throw invalid_argument("JP0 instruction takes 3 parameters!");
	//validation on the parameter types 
	if (inst[1].get_type())
		throw invalid_argument("Second paramater must be variable!");
}

//execution function
int ASI::calculate(int pc, DataMemory& data, bool& run)
{
    int in1 = operation[0].get_value(); 
    data.set_value(operation[1].get_value(), in1);
	cout << "Executing Instruction #" << pc << endl;
    return pc++;
}

//print function
void ASI::print() 
{
	cout << "ASI ";
	for (Operand iter : operation)
		cout << iter.get_value() << " ";
	cout << endl;
}

//destructor
ASI::~ASI()
{
}
