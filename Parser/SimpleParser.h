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

    //Destructor
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

    void getToken();

    bool isDigit(char inputToken);

    string line;
    char token;
    int index;
    int maxIndex;

};
#endif // SIMPLEPARSER_H_INCLUDED
