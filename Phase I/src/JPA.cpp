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
void JPA::print() 
{
	cout << "JPA ";
	for (Operand iter : operation)
		cout << iter.get_value() << " ";
	cout << endl;
}

//execution function
int JPA::calculate(int pc, DataMemory& data, bool& run)
{
	int jpc;
	jpc = operation[0].get_value();
	cout << "Executing Instruction #" << pc << endl;
	return jpc;
}

//destructor
JPA::~JPA()
{
}
