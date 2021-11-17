#include "DataMemory.h"
#include <iostream>
using namespace std;

//constructor
DataMemory::DataMemory()  
{
	//allocating an instruction memory of size 1024, initializing locations to zeros
	this->DataMem = new int[1024];
	for (int i = 0; i < 1024; i++) 
		this->is_allocated[i] = 0;
	cout << "Initializing the Data Memory" << endl;
}

//getter function
int DataMemory::get_value(int location)
{
	cout << "Got value: " << this->DataMem[location] << "from location #" << location << endl;
	return (this->DataMem[location]);
	
}

//setter function
void DataMemory::set_value(int location, int value)
{
	this->DataMem[location] = value;   //assign value to memory location
	this->is_allocated[location] = 1;  //assign the memory location as allocated
	cout << "Location #" << location << " is set to " << value << endl;
}

//lock function 
void DataMemory::lock(int pc)
{
	this->mu_allocation[pc].lock();

} 

//unlock function 
void DataMemory::lock(int pc)
{
	this->mu_allocation[pc].unlock();

} 

//print the data memory
void DataMemory::print() 
{
	cout << "-----------------------------------------" << endl;
	cout << "Data Memory" << endl;
	cout << "-----------------------------------------" << endl;
	for (int i = 0; i < 1024; i++) 
	{
		if (this->is_allocated[i] == 1)
		{
			cout << i << " ==>  ";
			cout << this->DataMem[i] << endl;
		}
		else
			cout << "empty location"; 
		cout << endl;
	}
	cout << "-----------------------------------------" << endl;
}

DataMemory::~DataMemory() 
{
	cout << "Deleting the data memory" << endl;
	delete[] this->DataMem;
}
