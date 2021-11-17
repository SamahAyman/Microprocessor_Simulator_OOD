#include "JPA.h" 
#include "Operand.h"
#include "DataMemory.h"
#include <iostream>
using namespace std;

//constructor
JPA::JPA(vector <Operand> inst): Instruction(inst)
{
	//validation on the number of parameters
	if (inst.size() != 1)
		throw invalid_argument("JPA takes only 1 parameter!");
}

//print function
stringstream JPA::print()
{
	stringstream ss;
	ss << "JPA ";
	for (Operand iter : operation)
		ss << iter.get_value() << " ";
	ss << endl;
	return ss;
}

//execution function
int JPA::calculate(int pc, DataMemory& data, bool& run, int thread)
{
	stringstream ss;
	int jpc;
	jpc = operation[0].get_value();

	ss << "Thread #" << thread << endl;
	ss << "Instruction #" << pc << " will jump to position " << jpc << endl;

	cout << ss.str();
	return jpc;
}

//destructor
JPA::~JPA()
{
}
