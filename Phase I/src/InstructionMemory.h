#pragma once
#include "Instruction.h"
#include "Operand.h"
#include"ADD.h"
#include "ASI.h"
#include "HLT.h"
#include "JP0.h"
#include "JPA.h"
#include "LOE.h"
#include "MUL.h"
#include "NEG.h"
#include <fstream>
#include <iostream>
using namespace std;

#ifndef INSTRUCTIONMEMORY_H
#define INSTRUCTIONMEMORY_H

class InstructionMemory
{
private:
	Instruction** inst;
	int inst_count;                                               //numper of instructions inserted into the memory

public:
	InstructionMemory();
	Instruction *get_instruction(int);                            //function to get the instruction from the memory
	void insert(Instruction&);                                    //function to insert a new instruction into the memory 
	friend ifstream& operator>>(ifstream &, InstructionMemory&);  //function to read and parse the instructions from a file
	void print();                                                 //functio to print the instruction memory
	~InstructionMemory();
};
#endif

