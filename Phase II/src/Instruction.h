#include "Operand.h"
#include "DataMemory.h"
#include <vector>
#include <sstream>
using namespace std;

#ifndef INSTRUCTION_H
#define INSTRUCTION_H

//abstract base class Instruction, from which all other instructions will inherit
class Instruction  
{
protected:
	vector <Operand> operation;

public:
	Instruction(vector <Operand >); 
	//virtual function for excuting the instruction with default value=0 since it will be changed in derived classes
	virtual int calculate(int, DataMemory&, bool& ) = 0;
	//virtual function for printing ,deafult value=0 since it depends on the operation  
	virtual stringstream print()=0; 
	~Instruction ();
};
#endif