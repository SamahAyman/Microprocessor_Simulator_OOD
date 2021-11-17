#include "ADD.h"
#include "DataMemory.h"

//constructor
ADD::ADD(vector <Operand> inst): Instruction(inst) 
{
	//validation on the number of parameters
	if (inst.size() != 3)
		throw invalid_argument("ADD instruction takes 3 parameters!");
	//validation on the parameter types 
	if (inst[0].get_type() || inst[1].get_type() || inst[2].get_type())
		throw invalid_argument("All paramaters must be variables!");
}

//execution function
int ADD::calculate(int pc, DataMemory& data, bool& run, int thread)
{
	stringstream ss;

	int input1 = data.get_value(operation.at(0).get_value());
	int input2 = data.get_value(operation.at(1).get_value());
	int result = input1 + input2;
	data.set_value(operation.at(2).get_value(), result);

	ss << "Thread #" << thread << endl;
	ss << "Instruction #" << pc << " added the data at address " << operation.at(0).get_value()
		<< " value: " << input1 << " with the data at address " << operation.at(1).get_value()
		<< " value: " << input2 << " Result = " << input1 + input2 << " saved at " << result << endl;

	ss << "Done excuting instruction" << endl << endl;
	cout << ss.str();

	return pc + 1;
}

//print function
stringstream ADD::print()
{
	stringstream ss;
	ss << "ADD ";
	for (Operand iter : operation)
		ss << iter.get_value() << " ";

	ss << endl;
	return ss;
}

//destructor
ADD::~ADD() 
{
}
