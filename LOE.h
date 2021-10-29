#ifndef LOE_H
#define LOE_H
#include "Instruction.h"
using namespace std;

class LOE : public Instruction
{

public:

    LOE(vector<Operand>);
    int calculate(int, Data_mem&, bool&);
	void print();
    ~LOE();

};

#endif //LEO