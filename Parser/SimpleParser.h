/*
Riad Shash (Ray)
CSCI 330
HW#3
*/

#ifndef SIMPLEPARSER_H_INCLUDED
#define SIMPLEPARSER_H_INCLUDED

#include <string>
#include <iostream>
#include <fstream>

using std::cout;
using std::endl;
using std::string;
using std::ofstream;

class SimpleParser{
public:
    //Constructors
    SimpleParser();

    //Destructor (not used)
    ~SimpleParser();

    //Parses the entire string deriving the production
    void parse(string& inputLine, ofstream& output);

private:
     //<exp>
    void exp(ofstream& output);

    //<term>
    void term(ofstream& output);

    //<factor>
    void factor(ofstream& output);

    //<number>
    void number(ofstream& output);

    //<digit>
    void digit(ofstream& output);

    //Gets the next token from expression
    void getToken( ofstream& output);

    //Determines if token is a digit
    bool isDigit(char inputToken);

    string line;
    char token;
    int index;
    int maxIndex;
    bool end;
    bool error;

};
#endif // SIMPLEPARSER_H_INCLUDED