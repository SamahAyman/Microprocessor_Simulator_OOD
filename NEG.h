#ifndef NEG_H 
#define NEG_H
#include "Instruction.h"
#include <iostream>
using namespace std;

//(NEG operation) derived from instruction class 
class NEG : public Instruction
{
public:
	//constructor 
	NEG(vector<Operand>);
	int calculate(int, Data_mem &, bool& on);
	void print();
	//destructor 
	~NEG();

};
#endif

