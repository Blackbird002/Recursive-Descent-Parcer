#include "SimpleParser.h"

SimpleParser::SimpleParser(){
    index = 0;
    token = ' ';
    line = "";
}

SimpleParser::~SimpleParser(){};

void SimpleParser::exp(ofstream& output, string& line){
    //Call <term>
    term(output, line);
    while(token == '+'){
        getToken(line);
        //Call <term>
        term(output, line);
    }
}

void SimpleParser::term(ofstream& output, string& line){
    //Call <factor>
    factor(output, line);
    while(token == '*'){
        getToken(line);
        //Call <factor>
        factor(output, line);
    }
}

void SimpleParser::factor(ofstream& output, string& line){
    if(token == '('){
        getToken(line);
        //Call <exp>
        exp(output, line);
        if(token == ')')
            getToken(line);
        else{}
            //ERROR!!!
    }
    else
        //Call <number>
        number(output,line);

}
