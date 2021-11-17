#include "Instruction.h"
#include "DataMemory.h"
using namespace std;

#ifndef HLT_H 
#define HLT_H

class HLT : public Instruction
{
public:
    HLT(vector<Operand>); 
	int calculate(int, DataMemory&, bool& run, int thread);
	stringstream print();
	~HLT();
};
#endif 