#ifndef HLT_H
#define HLT_H
#include "Instruction.h"
using namespace std;

//derived functionn from instruction class for HLT 
class HLT : public Instruction
{

public:
    HLT(vector<Operand>); 
    int calculate(int, DataMem& , bool&);
	void print();
    ~HLT();

};

#endif //Stop SIM