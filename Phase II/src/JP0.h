#include "Instruction.h"
#include "DataMemory.h"
using namespace std;

#ifndef JP0_H 
#define JP0_H

class JP0 : public Instruction
{
public:
    JP0(vector<Operand>);
    int calculate(int, DataMemory&, bool& run);
	void print();
    ~JP0();
};
#endif