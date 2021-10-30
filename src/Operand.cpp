#include "Operand.h"

//constructor
Operand::Operand(bool t, int v) : type(t), value(v)
{
}

//getter function for operand value
int Operand::get_value() const
{
	return value;
}

//getter function for operand type
int Operand::get_type() const 
{
	return type;
}

//destructor
Operand::~Operand()
{
}