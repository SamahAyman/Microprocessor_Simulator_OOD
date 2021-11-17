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
int JP0::calculate(int pc, DataMemory& data, bool& run, int thread)
{
	stringstream ss;

	int input1 = data.get_value(operation[0].get_value());
	int input2 = operation[1].get_value();
	string jump_condition;
	if (input1 == 0)
		jump_condition = "jump";
	else
		jump_condition = "not jump";

	ss << "Thread #" << thread << endl;
	ss << "Instruction #" << pc << " will " << jump_condition << " to position " << input2 << endl;
	cout << ss.str();

	if (input1 == 0)
		return input2;
	else
		return pc + 1;
}

//print function
stringstream JP0::print()
{
	stringstream ss;
	ss << "JP0 ";
	for (Operand iter : operation)
		ss << iter.get_value() << " ";

	ss << endl;
	return ss;
}

//destructor
JP0::~JP0()
{
}