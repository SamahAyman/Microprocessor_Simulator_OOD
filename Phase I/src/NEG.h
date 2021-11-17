#include "Instruction.h"
#include "DataMemory.h"
#include <iostream>
using namespace std;

#ifndef NEG_H 
#define NEG_H

class NEG : public Instruction
{
public:
	NEG(vector<Operand>);
	int calculate(int, DataMemory&, bool& run);
	void print();
	~NEG();
};
#endif

