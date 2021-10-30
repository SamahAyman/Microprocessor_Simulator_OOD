#include "NEG.h" 
#include "DataMemory.h"

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
int NEG::calculate(int pc, DataMemory& data, bool& run)
{
	int input = data.get_value(operation.at(0).get_value());
	int result = -1 * input;
	data.set_value(operation.at(1).get_value(), result);
	cout << "Executing Instruction #" << pc << " ==> negating memory location " << operation.at(0).get_value() << " with value " << input << " and storing the result in memory location " << operation.at(1).get_value() << " with value " << result << endl;
	return pc++;
}

//print function
void NEG::print()
{
	cout << "NEG ";
	for (Operand iter : operation)
		cout << iter.get_value() << " ";
	cout << endl;
}

//destructor
NEG::~NEG() 
{
}
