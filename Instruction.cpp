#include "Instruction.h"

//it includes only class constructor and destructor , other functions will be defined in derived classes
Instruction::Instruction (vector <Operand> op)
    : operation(op)
{}


Instruction::~Instruction(){}