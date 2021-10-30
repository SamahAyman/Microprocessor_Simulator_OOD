#include "Instruction.h"
#include "DataMemory.h"
#include <iostream>
using namespace std;

#ifndef MUL_H 
#define MIL_H

class MUL : public Instruction
{
public:
	MUL(vector <Operand>);
	int calculate(int, DataMemory&, bool& run);
	void print();
	~MUL();
};
#endif
