#include "Instruction.h"
#include <vector>
#include "Operand.h"
#include "DataMemory.h"

#ifndef JPA_H 
#define JPA_H

class JPA : public Instruction
{
public:
	JPA(vector<Operand>);
	int calculate(int, DataMemory&, bool& run);
	void print();
	~JPA();
};
#endif

