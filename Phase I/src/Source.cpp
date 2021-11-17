#include <iostream>
#include <iomanip>
#include <fstream>
#include<string>
#include "Simulator.h"
using namespace std;

int main() 
{
	char inst, data;
	string program_name;
	cout << "Enter test program name: " << endl;
	cin >> program_name;
	cout << "To print the data memory enter 'y'" << endl;
	cin >> data;
	cout << "To print the instruction memory enter 'y'" << endl;
	cin >> inst;

	Simulator sim(program_name);

	try 
	{
		sim.start();
	}
	catch (...) 
	{
		cerr << "Exception Error" << endl;
	}

	if (inst == 'y')
		sim.print_instructions();
	if (data == 'y')
		sim.print_data();

	system("pause");
	return 0;
}