#ifndef ADD_H
#define ADD_H
#include "Instruction.h"
#include <iostream>
using namespace std;

//(ADD operation)derived functionn from instruction class
class ADD : public Instruction
{
public:
	//class constructor
	ADD(vector <Operand>); 

	//calcutation function 
	int calculate(int, Data_mem&, bool& on);

	//printing function
	void print();
	//class destructor 
	~ADD();

};

#endif // !ADD_H
