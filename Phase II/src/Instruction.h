#include "Operand.h"
#include "DataMemory.h"
#include <vector>
#include <sstream>
#include <set>
#include <iterator>

using namespace std;

#ifndef INSTRUCTION_H
#define INSTRUCTION_H

//abstract base class Instruction, from which all other instructions will inherit
class Instruction
{
protected:
	vector <Operand> operation;
	set<int, greater<int>> locks;

public:
	Instruction(vector <Operand >);
	//virtual function for excuting the instruction with default value=0 since it will be changed in derived classes
	virtual int calculate(int, DataMemory&, bool&, int thread = 0) = 0;
	//virtual function for printing ,deafult value=0 since it depends on the operation  
	virtual stringstream print() = 0;
	void lock_inst(DataMemory&);
	void unlock_inst(DataMemory&);
	~Instruction();
};
#endif