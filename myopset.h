// myopset.h
// Uddeep Karki
// Created: 2021-09-30
// Updated:
//
// For CS 301 project
// Header for class MyOpset
// MyOpset : contains map of function pointers

#ifndef FILE_MYOPSET_H_INCLUDED
#define FILE_MYOPSET_H_INCLUDED

#include <map> // For std::map
using std::map;
#include <memory>
using std::unique_ptr;
#include <string>
using std::string;

class MyOpset {

public:
    MyOpset() {
	opcodes.insert({"add", &add});
    }
    
private:
    map <string,void *> opcodes = {};

    void add(int* a, int b)
    {
	*a += b;
    }
};


#endif //#ifndef FILE_MYOPSET_H_INCLUDED
