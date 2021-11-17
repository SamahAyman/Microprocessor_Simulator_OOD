#pragma once
#ifndef DATAMEMORY_H
#define DATAMEMORY_H


class DataMemory
{
private:
	int* DataMem;                //dynamic array for the elements of the data memory
	bool is_allocated[1024];     //boolean array 0=>empty location, 1=>allocated

public:
	DataMemory();          
	int get_value(int);          //getter function to get a value from a memory location
	void set_value(int, int);    //setter function to set a value for a memory location
	void print();                //function to print the data memory 
	~DataMemory();
};
#endif // !DATAMEM_H