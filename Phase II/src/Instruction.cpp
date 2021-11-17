#include "Instruction.h"

//constructor
Instruction::Instruction(vector<Operand> op) : operation(op)
{
	for (Operand i : op)
	{
		if (!i.get_type())
			locks.insert(i.get_value());
	}
}

//locking function
void Instruction::lock_inst(DataMemory& data_memory)
{
	for (auto i : this->locks)
		data_memory.lock(i);
}

//unlocking function
void Instruction::unlock_inst(DataMemory& data_memory)
{
	for (auto i : this->locks) data_memory.unlock(i);
}

//destructor
Instruction::~Instruction()
{
}