#include <iostream>
#include <string>
using std::string;
#include <fstream>
using std::ifstream;
#include <sstream>
#include <cctype>

#include <memory>
using std::shared_ptr;
#include <map>
using std::map;

#include <vector>
using std::vector;
#include <cstddef>
using std::size_t;

#include "myinstruction.h"
using registers = map<char, shared_ptr<int>>;

int main () {
    /*
    unique_ptr <int> test = std::make_shared<int> (1) ;
    int * a = test.get();
    std::cout << *a << std::endl;
    */

    
    map <char,shared_ptr<int>> testReg = {}; // registers
    
    for ( int i = 0 ; i < 26 ; ++i) {
	testReg['a' + i] = std::make_shared<int> (0) ;
    }
    /*
    std::cout << *testReg['a'].get() << std::endl;
    int *testc = testReg['c'].get();
    *testc = 2;
    std::cout << *testReg['c'].get() << std::endl;

    MyInstruction myinst ("add", 'c', 3, testReg);
    myinst.execute();
    std::cout << *testReg['c'].get() << std::endl;

    MyInstruction myinst2 ("add", 'a', 'c', testReg);
    myinst2.execute();
    std::cout << *testReg['a'].get() << std::endl;
    */
    
    ifstream myFile("test.txt");
    string myLine;//("jump 2");
    vector <MyInstruction> stack;
    
    while(std::getline(myFile, myLine)) {
        std::istringstream iss(myLine);
        string opcode;
        iss >> opcode;
        
        string inputBuffer;
        // CHecking if first operand is int
        iss >> inputBuffer;
        if(std::isdigit(inputBuffer[0])) {
            stack.emplace_back(opcode, std::stoi(inputBuffer), testReg);
            continue;
        }
        
        char op1 = inputBuffer[0];
        
        // Check if 2nd operand is int
        iss >> inputBuffer;
        if(std::isdigit(inputBuffer[0])) {
            stack.emplace_back(opcode, op1, std::stoi(inputBuffer), testReg);
            continue;
        }
        
        char op2 = inputBuffer[0];
        stack.emplace_back(opcode, op1, op2, testReg);
        
        
    }
    
    for( int *i = testReg['j'].get() ; *i < stack.size() ; ++(*i)) {
        stack[*i].execute();
    }
    // stack[0].execute();
    std::cout << *testReg['c'].get() << std::endl;
}
