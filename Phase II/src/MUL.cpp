#include "MUL.h" 
#include "DataMemory.h"
using namespace std;

//constructor
MUL::MUL(vector <Operand> inst): Instruction(inst)
{
	//validation on the number of parameters
	if (inst.size() != 3)
		throw invalid_argument("MUL instruction takes 3 parameters!");
	//validation on the parameter types 
	if (inst[0].get_type() || inst[1].get_type() || inst[2].get_type())
		throw invalid_argument("All paramaters in MUL must be variables!");
}

//execution function
int MUL::calculate(int pc, DataMemory& data, bool& run, int thread)
{
	stringstream ss;
	int input1 = data.get_value(operation.at(0).get_value());
	int input2 = data.get_value(operation.at(1).get_value());
	int result = input1 * input2;
	data.set_value(operation.at(2).get_value(), result);

	ss << endl;
	ss << "Thread #" << thread << endl;
	ss << "Instruction #" << pc << " multiplied the data at address " << operation.at(0).get_value() 
	   << " value: " << input1 << " with the data at address " << operation.at(1).get_value() 
	   << " value: " << input2 << " Result = " << result << " saved at " << operation.at(2).get_value() << endl;
	cout << ss.str();
	return pc + 1;
}


//function printing 
stringstream MUL::print()
{
	stringstream ss;
	ss << "MUL ";
	for (Operand iter : operation)
		ss << iter.get_value() << " ";

	ss << endl;
	return ss;
}

//destructor
MUL::~MUL() 
{
}
