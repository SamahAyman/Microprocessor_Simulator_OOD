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
int MUL::calculate(int pc, DataMemory& data, bool& run)
{
	int input1 = data.get_value(operation.at(0).get_value());
	int input2 = data.get_value(operation.at(1).get_value());
	int result =input1 * input2; 
	data.set_value(operation.at(2).get_value(), result);
	cout << "Executing Instruction #" << pc << " ==> multiplying memory location " << operation.at(0).get_value() << " with value " << input1
		<< " and memory location " << operation.at(1).get_value() << " with value " << input2
		<< " and storing the result in memory location " << operation.at(2).get_value() << " with value " << result << endl;
	return pc++;
}


//function printing 
void MUL::print() 
{
	cout << "MUL ";
	for (Operand iter : operation)
		cout << iter.get_value() << " ";
	cout << endl;
}

//destructor
MUL::~MUL() 
{
}
