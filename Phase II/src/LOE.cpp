#include "LOE.h" 
#include "DataMemory.h"
#include <iostream>
using namespace std;

//constructor
LOE::LOE(vector <Operand> inst): Instruction(inst)
{
	//validation on the number of parameters
	if (inst.size() != 3)
		throw invalid_argument("LOE instruction takes 3 parameters!");
	//validation on the parameter types 
	if (inst[0].get_type() || inst[1].get_type() || inst[2].get_type())
		throw invalid_argument("All paramaters must be variables!");
}

//execution function
int LOE::calculate(int pc, DataMemory &data, bool& run)
{
	int input1 = data.get_value(operation.at(0).get_value());
	int input2 = data.get_value(operation.at(1).get_value());
	if (input1 <= input2)
    {
        data.set_value(operation.at(2).get_value(), 1);
		cout << "Executing Instruction #" << pc << endl;
    }
    else
    {
        data.set_value(operation.at(2).get_value(), 0);
		cout << "Executing Instruction #" << pc << endl;
    }
	return pc++;
}

//print funtion
void LOE::print()
{
	cout << "LOE ";
	for (Operand iter : operation)
		cout << iter.get_value() << " ";
	cout << endl;
}

//destructor
LOE::~LOE()
{
}
