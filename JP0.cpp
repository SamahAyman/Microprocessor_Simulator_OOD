#include "JP0.h" 
JP0::JP0(vector<Operand> rs) //construction and parameter validation
    : Instruction(rs)
{}



int JP0::calculate(int inst, Data_mem& data, bool& on)//execution function for JP0
{
    int in1 = data.getVar(operation[0].getValue());
    int a1 = operation[1].getValue();

    if (a1 < 0 || a1 > 1023)
    {
        cout << "Instruction memory index is out of range!" << endl;
    }
    else
    {
        if (in1== 0)
        {
         
         cout << "Instruction #"<<inst << " will jump to position " <<a1<<endl;
         inst= a1; 

        }
        else
            {
                printf("The SIM just skipped jump instruction (JP0)";
                inst++; 
            }
    }


    
    return inst ;
}

void JP0::print() //function to print the instruction
{

	cout << "JP0 ";
    //print the line to be executed 
	for (Operand iter : operation)
		cout << iter.getValue() << " ";
	cout << endl;
}

JP0::~JP0(){
}