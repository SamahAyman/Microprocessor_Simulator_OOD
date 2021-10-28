#ifndef MUL_H
#define MIL_H
#include "Instruction.h"
#include <iostream>
using namespace std;

//(MUL function) derived from instruction class
class MUL : public Instruction
{
public:
	//constructor
	MUL(vector <Operand>);
	int calculate(int, Data_mem&, bool& on);
	void print();
	//destructor
	~MUL();


};
#endif // !MUL_H
