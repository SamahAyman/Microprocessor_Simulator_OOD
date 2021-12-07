#pragma once
#include <string>	
#include "instruction.h"			// include class instruction to process each instruction separately
#include "parser.h"					// include class reader to read the instructions text file
#include "processor.h"				// include class executor to parse and execute instructions


using namespace std;
class Simulator 
{
private:
	vector<Instruction> inst_mem;	// instruction memory vector of type instruction (class object)
public:
	Simulator();					// constructor
	void process(string filename);	// function to read, parse, and execute text file.
};