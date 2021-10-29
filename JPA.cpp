#include "JPA.h"


JPA::JPA(vector <Operand> s): Instruction(s) //construction and parameter validation
{

}

void JPA::print()
{

	cout << "JPA ";
	for (Operand iter : operation)
		cout << iter.getValue() << " ";
	cout << endl;
}

int JPA::calculate(int inst, Data_mem &data, bool& on)
{
	int a1=operation[0].getValue();

  if (a1 < 0 || a1 > 1023)//to validate it is a valid address
    {
        cout << "Instruction memory index is out of range!" << endl;
    }
    else {
        cout << "Instruction #"<<inst << " will jump to position " <<a1<<endl;
    }

	return a1;
}


JPA::~JPA()
{
}
