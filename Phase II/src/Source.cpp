#include <iostream>
#include <iomanip>
#include <fstream>
#include<string>
#include <Windows.h>
#include <filesystem>
#include "Simulator.h"
using namespace std;
namespace fs = std::experimental::filesystem;

void get_directory(const string& name, vector <string>& paths)
{
	for (const auto& directory : fs::directory_iterator(name))
		paths.push_back(string(directory.path().u8string()));
}

int main() 
{
	char inst, data;
	//string program_name;
	//cout << "Enter test program name: " << endl;
	//cin >> program_name;

	vector <string> programs;
	string directory_name;
	cout << "Enter testing directory" << endl;
	cin >> directory_name;
	get_directory(directory_name, programs);

	cout << "To print the data memory enter 'y'" << endl;
	cin >> data;
	cout << "To print the instruction memory enter 'y'" << endl;
	cin >> inst;

	Simulator sim(programs);

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