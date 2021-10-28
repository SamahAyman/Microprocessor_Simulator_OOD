#ifndef JPA_H
#define JPA_H
#include "Instruction.h"
#include <vector>
#include <iostream>
using namespace std;
//JPA function 
class JPA : public Instruction
{
public:
	JPA(vector <Operand>);
	int excute(int, Data_mem &, bool& on);
	void print();
	~JPA();
};
#endif // !JPA_H

