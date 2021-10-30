#include "HLT.h" 
#include "DataMemory.h"
#include <iostream>
using namespace std;

HLT::HLT(vector<Operand> s)  : Instruction(s)
{}

//execution function
int HLT::calculate(int pc, DataMemory& data, bool& run)
{
    run = 0;
    cout << "SIM stopped at instuction #"<< pc <<endl;
    return pc++;
}

//print function
void HLT::print() 
{
	cout << "SIM stopped!" << endl;
}

//destructor
HLT::~HLT()
{
}