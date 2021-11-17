#include "Simulator.h"
#include <vector>

//constructor
Simulator::Simulator(vector <string>& files)
{
	this->size = files.size();
	this->instMem = new InstructionMemory[this->size];
	this->run = new bool[this->size];
	this->pc = new int[this->size];
	this->processes = new thread[this->size];
	this->files = files;
}

//function to run the simulator 
void Simulator::start()
{
	for (int i = 0; i < this->size; i++) {
			this->processes[i] = thread(&Simulator::process, this, i);
		}
		for (int i = 0; i < this->size ; i++) {
			this->processes[i].join();
		}
}

void Simulator::process(int counter)
{
	ifstream file;  //file that contains the instructions 
	string program_name = files[counter];
	file.open(program_name);
	this->run[counter] = 1;
	this->pc[counter] = 0;
	try {
		while (!file.eof())
			file >> instMem[counter];
	}
	catch (runtime_error& ex) {
		cerr << "Runtime Error!!!\n" << ex.what() << endl;
		exit(-1);
	}
	catch (invalid_argument& ex) {
		cerr << "Invalid Argument Error!!!\n" << ex.what() << endl;
		exit(-1);
	}
	catch (overflow_error& ex) {
		cerr << "Overflow Error!!!\n" << ex.what() << endl;
		exit(-1);
	}
	catch (...) {
		cerr << "Exception Error!!!\n" << endl;
		exit(-1);
	}

	file.close();
	Instruction *Inst = nullptr;
	while (this->run[counter]) //keep the program running while the value run is true (ie; no HLT instruction called)
	{ 
		Inst = this->instMem[counter].get_instruction(pc[counter]);  //get intruction to excute
		stringstream stream;
		try{
		Inst->lock_inst(this->dataMem);
		this->pc[counter] = Inst->calculate(this->pc[counter], this->dataMem, this->run[counter], counter);  //execute instruction and update pc
		Inst->unlock_inst(this->dataMem);
		}
		catch (runtime_error& ex) {
			cerr << "Runtime Error!!!\n" << ex.what() << endl;
			exit(-1);
		}
		catch (invalid_argument& ex) {
			cerr << "Invalid Argument Error!!!\n" << ex.what() << endl;
			exit(-1);
		}
		catch (overflow_error& ex) {
			cerr << "Overflow Error!!!\n" << ex.what() << endl;
			exit(-1);
		}
		catch (...) {
			cerr << "Exception Error!!!\n" << endl;
			exit(-1);
		}

	}

}

//function to print the entire Instruction Memory
void Simulator::print_instructions()
{
	for (int i = 0; i < this->size; i++) {
		cout << "Instruction memory for " << this->files[i] 
			<< " executed on thread #" << i << endl;
		this->instMem[i].print();

		cout << endl << endl;
	}
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
