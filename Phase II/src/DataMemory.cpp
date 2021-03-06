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
}

//getter function
int DataMemory::get_value(int location)
{
	return (this->DataMem[location]);
}

//setter function
void DataMemory::set_value(int location, int value)
{
	this->DataMem[location] = value;   //assign value to memory location
	this->is_allocated[location] = 1;  //assign the memory location as allocated
}

//lock function 
void DataMemory::lock(int pc)
{
	this->mu_allocation[pc].lock();
} 

//unlock function 
void DataMemory::unlock(int pc)
{
	this->mu_allocation[pc].unlock();
} 

//print the data memory
void DataMemory::print()
{
	cout << "-----------------------------------------\n** Data Memory Values **\nVariable ==> Value\n";
	for (int i = 0; i < 1024; i++)
	{
		if (this->is_allocated[i] == 1)
		{
			cout << i << " ==>  ";
			cout << this->DataMem[i] << endl;
		}
	}
	cout << "-----------------------------------------" << endl;
}

DataMemory::~DataMemory() 
{
	delete[] this->DataMem;
}
