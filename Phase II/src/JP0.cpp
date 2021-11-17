#include "JP0.h" 
#include "DataMemory.h"
#include <iostream>
using namespace std; 

//constructor
JP0::JP0(vector<Operand> inst): Instruction(inst)
{
	//validation on the number of parameters
	if (inst.size() != 2)
		throw invalid_argument("JP0 instruction takes 3 parameters!");
	//validation on the parameter types 
	if (inst[0].get_type() || inst[1].get_type())
		throw invalid_argument("All paramaters must be variables!");
}

//execution function
int JP0::calculate(int pc, DataMemory& data, bool& run)
{
    int input1 = data.get_value(operation[0].get_value());
    int input2 = operation[1].get_value();

    if (input2 < 0 || input2 > 1023)
        cout << "Instruction memory index is out of range!" << endl;
    else
    {
        if (input1 == 0)
        {
			cout << "Executing Instruction #" << pc << endl;
			pc= input2;
        }
        else
        {
			cout << "The SIM skipped jump instruction (JP0)" << endl;
			pc++; 
		}
    }
    return pc;
}

//print function
void JP0::print() 
{
	cout << "JP0 ";
	for (Operand iter : operation)
		cout << iter.get_value() << " ";
	cout << endl;
}

//destructor
JP0::~JP0()
{
}