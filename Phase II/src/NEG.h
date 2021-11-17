#include "Instruction.h"
#include "DataMemory.h"
#include <iostream>
#include <sstream>
using namespace std;

#ifndef NEG_H 
#define NEG_H

class NEG : public Instruction
{
public:
	NEG(vector<Operand>);
	int calculate(int, DataMemory&, bool& run, int thread);
	stringstream print();
	~NEG();
};
#endif

