#pragma once
#ifndef DATAMEMORY_H
#define DATAMEMORY_H
#include <string>
#include <sstream>
#include<iostream>
#include "windows.h"
#include <mutex>          // std::mutex
using namespace std;


class DataMemory
{
private:
	int* DataMem;                //dynamic array for the elements of the data memory
	bool is_allocated[1024];     //boolean array 0=>empty location, 1=>allocated

	mutex mu_allocation[1024];

public:
	DataMemory();          
	int get_value(int);          //getter function to get a value from a memory location
	void set_value(int, int);    //setter function to set a value for a memory location
	void lock(int);
	void unlock(int);
	void print();                //function to print the data memory 
	~DataMemory();
};
#endif // !DATAMEM_H