#include "Simulator.h"
#include "parser.h"

using namespace std;
Simulator::Simulator() //constructor
{
}
void Simulator::process(string filename)
{
	parser read_me(filename);		      // initialize reader object and pass filename to read text file
	inst_mem = read_me.instruction_mem(); // return data of instruction memory
	
	processor execute_me(inst_mem);		  // initialize executor object to start execution
	execute_me.execute();				  // execute instructions inside instruction memory
}