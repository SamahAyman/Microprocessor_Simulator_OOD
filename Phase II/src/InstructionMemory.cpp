#include "InstructionMemory.h" 
#include "Operand.h"
#include "Instruction.h"
#include <fstream>
#include <string>

//constructor
InstructionMemory::InstructionMemory ()
{
	cout << "Initializing the Instruction Memory" << endl;
	this->inst = new Instruction*[1024];     //allocating an instruction memory of size 1024
	this->inst_count = 0;                    //memory is initially empty --> intstruction count = 0
}

//function to get the instruction from the memory using the program counter PC
Instruction* InstructionMemory::get_instruction (int pc)
{
	if (pc < this->inst_count) 
		return inst[pc];

	//if PC value is out of the instruction memory range, throw exception
	else throw runtime_error("Invalid PC value!");     
}

//inserting new functions into the instruction memory
void InstructionMemory::insert (Instruction& new_inst)  
{
	if (this->inst_count == 1024)
		throw overflow_error("Memory is full. Unable to insert new instructions!");
	else
	{
		//if memroy size is not yet reached, inser the new instruction into the instruction memory
		this->inst[this->inst_count] = &new_inst;
		this->inst_count++;
	}
}

//
enum for_switch
{ add = 68, neG = 71, asI = 73, jp0 = 48, jpA = 65, loE = 69, muL = 76, hlT = 84 };

//function to read and parse the instructions from a file
ifstream& operator>>(ifstream& file, InstructionMemory& instMem)
{
	string line;
	getline(file, line);
	int length = 0;
	int cursor;
	vector<string> vec;
	Instruction *InstPtr = nullptr;

	while (length < line.length() && line[length] == ' ' || line[length] == '\t') length++;
	cursor = length;
	while (length < line.length()) {
		while (cursor < line.length() && line[cursor] != ' ' && line[cursor] != '\t' && line[cursor] != ',') cursor++;
		vec.push_back(line.substr(length, cursor - length));
		while (cursor < line.length() && line[cursor] == ' ' || line[cursor] == '\t' || line[cursor] == ',') cursor++;
		length = cursor;
		if (vec.size() > 4)
			throw invalid_argument("Invalid number of parameters!");
	}
	vector<Operand> OP;
	for (int i = 1; i < vec.size(); i++) {
		if (vec[i - 1] == "ASI") {
			Operand O(1, atoi(vec[i].c_str()));
			OP.push_back(O);
		}
		else {
			Operand O(0, atoi(vec[i].c_str()));
			OP.push_back(O);
		}
	}
	switch (int(string(vec[0]).back()))
	{
		case add:
		{
			InstPtr = new ADD(OP);
			break;
		}
		case neG: 
		{
			InstPtr = new NEG(OP);
			break;
		}
		case muL: 
		{
			InstPtr = new MUL(OP);
			break;
		}
		case hlT: 
		{
			InstPtr = new HLT(OP);
			break;
		}
		case jp0: 
		{
			InstPtr = new JP0(OP);
			break;
		}
		case jpA: 
		{
			InstPtr = new JPA(OP);
			break;
		}
		case asI: 
		{
			InstPtr = new ASI(OP);
			break;
		}
		case loE: 
		{
			InstPtr = new LOE(OP);
			break;
		}
		default:
			cout << "invalid instruction" << endl;
		break;
	}
	instMem.insert(*InstPtr);
	return file;
}

//functio to print all existing instructions in the memory
void InstructionMemory::print()
{
	cout << "-----------------------------------------\n";
	cout << "** Instructions in Instruction Memory ** \nPC ==> Instruction\n";
	for (int i = 0; i < this->inst_count; i++)
	{
		cout << i << "  ==>  ";
		cout << inst[i]->print().str();
	}
	cout << "-----------------------------------------" << endl;
}

//destructor 
InstructionMemory::~InstructionMemory() {
	cout << "Deleting the instruction memory" << endl;
	for (int i = 0; i < this->inst_count; i++) {
		delete this->inst[i];
	}
	delete[] this->inst;
}
