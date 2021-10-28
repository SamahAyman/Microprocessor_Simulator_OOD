#pragma once
#ifndef INSTRUCTION_H
#define INSTRUCTION_H
#include "Operand.h"
#include "Data_mem.h"
#include <vector>
using namespace std;

//base class to pass it to all other derived classes 
class Instruction  
{

protected:
	vector <Operand> operation;

public:
	// class constructor
	Instruction(vector <Operand >); 

	//virtual function for excuting the instruction with default value=0 since it will be changed in derived classes
	virtual int calculate(int, Data_mem&, bool& )=0; 

	//virtual function for printing ,deafult value=0 since it depends on the operation  
	virtual void print()=0; 

	//class destrcutor
	~Instruction ();
	


};
#endif // !INSTRUCTION_H