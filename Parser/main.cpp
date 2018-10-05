/*
Riad Shash (Ray)
CSCI 330
HW#3
*/

#include <iostream>
#include "SimpleParser.h"
using namespace std;

int main()
{
    ofstream outputFile;
    ifstream inputFile;

    try{
        inputFile.open("Input.txt");
        if(!inputFile)
            throw std::ios::failure("Error opening Input.txt file!");
        outputFile.open("Output.txt");
        if(!outputFile)
            throw std::ios::failure("Error creating Output.txt file!");
    }
    catch(const std::exception& e){
        //Prints the specific error message
        cout<<e.what() <<endl;
    }



    /*
    while(!inputFile.eof()){


    }

    SimpleParser parser;
    string line = "(2+3)*4+5";
    parser.parse(line,outputFile);
    */
    return 0;
}
