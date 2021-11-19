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
int LOE::calculate(int pc, DataMemory &data, bool& run, int thread)
{
	stringstream ss;
	int input1 = data.get_value(operation.at(0).get_value());
	int input2 = data.get_value(operation.at(1).get_value());
	if (input1 <= input2)
		data.set_value(operation.at(2).get_value(), 1);
	else
		data.set_value(operation.at(2).get_value(), 0);
	
	ss << endl;
	ss << "Thread #" << thread << endl;
	ss << "Instruction #" << pc << " set the data at address " << operation.at(2).get_value()
		<< " with 1 if the data at address " << operation.at(0).get_value()
		<< " value: " << input1 << " is less than the data at address " << operation.at(1).get_value()
		<< " value: " << input2 << endl;

	cout << ss.str();
	return pc + 1;
}

//print funtion
stringstream LOE::print()
{
	stringstream ss;
	ss << "LOE ";
	for (Operand iter : operation)
		ss << iter.get_value() << " ";
	ss << endl;
	return ss;
}

//destructor
LOE::~LOE()
{
}
