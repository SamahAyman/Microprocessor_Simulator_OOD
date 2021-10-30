#pragma once
#ifndef OPERAND_H
#define OPERAND_H

class Operand
{
private:
	//0 => memory address, 1 => value
	bool type;
	int value;

public:
	Operand(bool, int);
	int get_value() const; 
	int get_type() const; 
	~Operand();
};
#endif 