#include "HLT.h"

HLT::HLT(vector<Operand> s)  : Instruction(s)
{}


int HLT::excute(int inst, Data_mem& data, bool& on) 
{
    on = 0;
    cout << "SIM stopped at instuction #"<< inst <<endl;
    return inst+1;
}

void HLT::print() //function to print the instruction
{
printf("The SIM just stopped \n");
}
HLT::~HLT()
{}