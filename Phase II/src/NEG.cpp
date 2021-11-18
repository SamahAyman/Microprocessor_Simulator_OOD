#include "NEG.h" 
#include "DataMemory.h"
#include <sstream>


//constructor
NEG::NEG(vector<Operand> inst): Instruction(inst) 
{
	//validation on number of parameters
	if (inst.size() != 2)
		throw invalid_argument("NEG instruction takes 2 parameters!");
	//validation on parameter types: must be addresses 
	if (inst[1].get_type() || inst[0].get_type())
		throw invalid_argument("Both paramaters must be variables!");
}

//execution function
int NEG::calculate(int pc, DataMemory& data, bool& run, int thread)
{
	stringstream ss;
	int input = data.get_value(operation.at(0).get_value());
	int result = -1 * input;
	data.set_value(operation.at(1).get_value(), result);

	ss << endl;
	ss << "Thread #" << thread << endl;
	ss << "Instruction #" << pc << " set the data at address " << operation.at(1).get_value()
		<< " value: " << input << " to the negation: " << -1 * input << endl;
	cout << ss.str();

	return pc + 1;
}

//print function
stringstream NEG::print()
{
	stringstream ss;
	ss << "NEG ";
	for (Operand iter : operation)
		ss << iter.get_value() << " ";
	ss << endl;
	return ss;
}

//destructor
NEG::~NEG() 
{
}
