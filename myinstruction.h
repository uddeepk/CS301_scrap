// myinstruction.h
// Uddeep Karki
// Created: 2021-09-30
// Updated:
//
// For CS 301 project
// Header for class Myinstruction
// Myinstruction opcode, operand1, operand2

#ifndef FILE_MYINSTRUCTION_H_INCLUDED
#define FILE_MYINSTRUCTION_H_INCLUDED


#include <map>
using std::map;
#include <memory>
using std::shared_ptr;
#include <string>
using std::string;

using registers = map<char, shared_ptr<int>>;


class MyInstruction {
    
public:
    // Ctors
    // 2 param ctor
    explicit MyInstruction (string operation, int op1, registers &r)
        :_opcode(operation),
         _operand1(std::make_shared<int>(op1)),
         _operand2(0)
    {
        _regs = &r;
    }
    // 3 param ctor
    explicit MyInstruction (string operation, char op1, int op2,
		   registers &r)
	:_opcode(operation),
	 _operand1(r[op1]),
	 _operand2(std::make_shared<int>(op2))
	
    {
        _regs = &r;
    }

    explicit MyInstruction (string operation, char op1, char op2,
		   registers &r)
	:_opcode(operation),
	 _operand1(r[op1]),
	 _operand2(r[op2])
	
    {
        _regs = &r;
    }

public:
    void execute()
    {
	if (_opcode == "add")
	    add();
	else if (_opcode == "sub")
	    sub();
	else if (_opcode == "set")
	    set();
	else if (_opcode == "div")
	    div();
	else if(_opcode == "jump")
	    jump();
	else if(_opcode == "eq")
	    eq();
	else if(_opcode == "neq")
	    neq();
	else if(_opcode == "geq")
	    geq();
	else if(_opcode == "leq")
	    leq();
	else if(_opcode == "less")
	    less();
	else if(_opcode == "grtr")
	    grtr();
	else if(_opcode == "bsl")
	    bsl();
	else if(_opcode == "bsr")
	    bsr();
	else if(_opcode == "band")
	    band();
	else if(_opcode == "bor")
	    bor();
	else if(_opcode == "bxor")
	    bxor();
	else if(_opcode == "bnot")
	    bnot();
    }
	    
 
				     
    
//***** MyInstruction: Data members *****
private:
    string _opcode;
    //int * operand1;
    //int * operand2;
    shared_ptr<int> _operand1;
    shared_ptr<int> _operand2;
    registers * _regs = 0;
    void add () {
	*_operand1 += *_operand2;
    }
    void set() {
	*_operand1 = *_operand2;
    }
    void sub() {
	*_operand1 -= *_operand2;
    }
    void mul() {
	*_operand1 *= *_operand2;
    }
    void jump() {
        *((*_regs)['j'])=*_operand1-1;
    }
    void div() {
        *_operand1 /= *_operand2;
    }
    void eq() {
        if (*_operand1 != *_operand2)
            ++(*((*_regs)['j']));
    }
    void neq () {
        if (*_operand1 == *_operand2)
            ++(*((*_regs)['j']));
    }
    void geq () {
        if (!(*_operand1 >= *_operand2))
            ++(*((*_regs)['j']));
    }
    void leq () {
        if (!(*_operand1 <= *_operand2))
            ++(*((*_regs)['j']));
    }
    void less() {
       if (!(*_operand1 < *_operand2))
            ++(*((*_regs)['j']));
    }
    void grtr() {
       if (!(*_operand1 > *_operand2))
            ++(*((*_regs)['j']));
    }
    void bsl() {
        *_operand1 = *_operand1 << *_operand2;
    }
    void bsr() {
        *_operand1 = *_operand1 >> *_operand2;
    }
    void band() {
        *_operand1 = *_operand1 & *_operand2;
    }
    void bor() {
        *_operand1 = *_operand1 | *_operand2;
    }
    void bxor() {
        *_operand1 = *_operand1 ^ *_operand2;
    }
    void bnot() {
        *_operand1 = ~*_operand1;
    }
};


#endif // #ifndef FILE_MYINSTRUCTION_H_INCLUDED
