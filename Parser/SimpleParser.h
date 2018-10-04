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
    void exp(ofstream& output, string& line);

    //<term>
    void term(ofstream& output, string& line);

    //<factor>
    void factor(ofstream& output, string& line);

    //<number>
    void number(ofstream& output, string& line);

    //<digit>
    void digit(ofstream& output,string& line);

    char getToken(string& line);

    string line;
    char token;
    int index;

};
#endif // SIMPLEPARSER_H_INCLUDED
