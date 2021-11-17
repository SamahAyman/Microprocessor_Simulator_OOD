#include "HLT.h" 
#include "DataMemory.h"
#include <iostream>
using namespace std;

HLT::HLT(vector<Operand> s)  : Instruction(s)
{}

//execution function
int HLT::calculate(int pc, DataMemory& data, bool& run, int thread)
{
	stringstream ss;
	run = 0;
	ss << "Thread #" << thread << endl;
	ss << "Excution stopped at instuction #" << pc << endl;
	cout << ss.str();
	return pc;
}

//print function
stringstream HLT::print()
{
	stringstream ss;
	ss << "HLT ";
	ss << endl;
	return ss;
}

//destructor
HLT::~HLT()
{
}