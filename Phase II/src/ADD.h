#include "Instruction.h"
#include <iostream>
#include "Operand.h"
#include "DataMemory.h"
using namespace std;

#ifndef ADD_H 
#define ADD_H

class ADD : public Instruction
{
public:
	ADD(vector <Operand>); 
	int calculate(int, DataMemory&, bool& run, int thread);
	stringstream print();
	~ADD();
};
#endif
