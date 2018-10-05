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
        cout<<e.what() <<endl;
    }

    string line = "";
    
    while(!inputFile.eof()){
       getline(inputFile, line);
       cout<<"Inserting : " <<line <<endl; 
       cout<<"=========================================================================\n";
       parser.parse(line,outputFile);
       cout<<endl;
    }

    
    return 0;
}
