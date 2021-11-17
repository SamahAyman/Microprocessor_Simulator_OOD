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
int ASI::calculate(int pc, DataMemory& data, bool& run, int thread)
{
	stringstream ss;
	ss.clear();

	int in1 = operation[0].get_value();
	data.set_value(operation[1].get_value(), in1);

	ss << "Thread #" << thread << endl;
	ss << "Instruction #" << pc << " set the data at address " << operation[1].get_value()
		<< " with the data =  " << in1 << endl;

	cout << ss.str();
	ss.clear();
	return pc + 1;
}

//print function
stringstream ASI::print()
{
	stringstream ss;
	ss.clear();

	ss << "ASI ";
	for (Operand iter : operation)
		cout << iter.get_value() << " ";

	ss << endl;
	ss.clear();
	return ss;
}

//destructor
ASI::~ASI()
{
}
