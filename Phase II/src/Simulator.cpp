#include "Simulator.h"

//constructor
Simulator::Simulator(string name)
{
	this->program_name = name;
	this->file.open(program_name);
	this->run = 1;
	while (!this->file.eof())
		this->file >> instMem;
	this->file.close();
	this->pc = 0;
}

//function to run the simulator 
void Simulator::start()
{
	Instruction *Inst = nullptr;
	//if run is true ==> no hult signal is detected ==> keep the program running 
	while (this->run) 
	{
		//execute the instruction and update pc
		Inst = this->instMem.get_instruction(pc);
		this->pc = Inst->calculate(this->pc, this->dataMem, this->run);  
		cout << "Done excuting instruction" << pc << endl;
	}
}

//function to print the entire Instruction Memory
void Simulator::print_instructions()
{
	this->instMem.print();
}

//function to print the entire Data Memory 
void Simulator::print_data() 
{
	this->dataMem.print();
}

//destructor
Simulator::~Simulator()
{
}
