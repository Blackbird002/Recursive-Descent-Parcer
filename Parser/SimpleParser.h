#ifndef SIMPLEPARSER_H_INCLUDED
#define SIMPLEPARSER_H_INCLUDED

#include <string>
#include <fstream>

using std::cout;
using std::endl;

class SimpleParser
{
public:
    //Constructors
    SimpleParser(ofstream outputFile);

    //Destructor
    ~SimpleParser();

    //Accessors
    String getLine();
    int getIndex();
    int getToken();

    //<exp>
    void exp();

    //<term>
    void term();

    //<factor>
    void factor();

    //<number>
    void number();

    //<digit>
    void digit();

    //Parses the entire string deriving the production
    void parse(String inputLine);

private:
    String line;
    char token;
    int index;
    ofstream outputFile;

};




#endif // SIMPLEPARSER_H_INCLUDED
