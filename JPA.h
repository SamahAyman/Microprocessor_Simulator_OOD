#include "Instruction.h"
#include <vector>
#include "Operand.h"

#ifndef JPA_H 
#define JPA_H

class JPA : public Instruction
{
public:
	JPA(vector<Operand>);
	int calculate(int, Data_mem &, bool& on);
	void print();
	~JPA();
};
#endif

