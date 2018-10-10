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
    SimpleParser parser;

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
        outputFile<<e.what() <<endl;
    }

    string line = "";
    
    while(!inputFile.eof()){
       getline(inputFile, line);
       outputFile<<"=========================================================================\n";
       outputFile<<"Inserting : " <<line <<endl; 
       outputFile<<"=========================================================================\n";
       parser.parse(line,outputFile);
       outputFile<<endl;
    }

    inputFile.close();
    outputFile.close();

    return 0;
}
