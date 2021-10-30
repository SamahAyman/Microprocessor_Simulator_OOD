#include <iostream>
#include <fstream>
#include<string>
#include "InstructionMemory.h"
#include "DataMemory.h"
using namespace std;

#ifndef SIMULATOR_H
#define SIMULATOR_H

class Simulator 
{
private:
	ifstream file;                  //file containing the instructions 
	string program_name;
	InstructionMemory instMem;      //intruction memory object
	DataMemory dataMem;             //data memory object 
	int pc;                         //program counter 

public:
	bool run;                       //bool variable to hult the simulator
	Simulator(string);    
	void start();                     
	void print_instructions();
	void print_data();
	~Simulator();
};
#endif 
