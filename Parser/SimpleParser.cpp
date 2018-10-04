#include "SimpleParser.h"

SimpleParser::SimpleParser(){
    index = 0;
    token = ' ';
    line = "";
}

SimpleParser::~SimpleParser(){};

string SimpleParser::getLine(){return line;}
int SimpleParser::getIndex(){return index;}
char SimpleParser::getToken(){return token;}

void SimpleParser::exp(ofstream& output){
    //Call <term>
    term(output);
    
}
