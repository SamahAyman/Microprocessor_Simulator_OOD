#include "Instruction.h"
#include "DataMemory.h"
using namespace std;

#ifndef ASI_H 
#define ASI_H

class ASI : public Instruction
{
public:
    ASI(vector<Operand>);
    void print();
    int calculate(int, DataMemory&, bool& run);
    ~ASI();
};
#endif
