#include <iostream>
#include <fstream>
#include<string>
#include <vector>
#include "InstructionMemory.h"
#include <thread>
#include "DataMemory.h"
using namespace std;

#ifndef SIMULATOR_H
#define SIMULATOR_H

class Simulator 
{
private:
	//ifstream file;                  //file containing the instructions 
	string program_name;
	InstructionMemory* instMem;      //intruction memory object
	DataMemory dataMem;             //data memory object 
	int *pc;                         //program counter 
	thread* processes;				//thread pointer for all processes 
	int size; 						//size of programs inserted into simuation
	vector <string> files; 		//vector of files/programs names 

	

public:
	bool* run;                       //bool variable to hult the simulator
	Simulator(vector<string>&);    
	void start();
	void process(int);                    
	void print_instructions();
	void print_data();
	~Simulator();
};
#endif 
