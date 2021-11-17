#include "Instruction.h"
#include "DataMemory.h"
using namespace std;

#ifndef LOE_H 
#define LOE_H

class LOE : public Instruction
{
public:
    LOE(vector<Operand>);
	int calculate(int, DataMemory&, bool& run, int thread);
	stringstream print();
    ~LOE();
};
#endif 