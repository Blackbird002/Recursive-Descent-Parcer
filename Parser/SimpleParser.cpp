#include "SimpleParser.h"

SimpleParser::SimpleParser(){
    index = 0;
    token = ' ';
    line = "";
}

bool SimpleParser::isDigit(char inputToken){
    bool result = false;
    switch(inputToken){
        case '0' : result = true; break;
        case '1' : result = true; break;
        case '2' : result = true; break;
        case '3' : result = true; break;
        case '4' : result = true; break;
        case '5' : result = true; break;
        case '6' : result = true; break;
        case '7' : result = true; break;
        case '8' : result = true; break;
        case '9' : result = true; break;
    }
    return result;
}

SimpleParser::~SimpleParser(){};

void SimpleParser::getToken(){
    if(index < maxIndex){
        token = line[index];
        ++index;
    }
    else
        token = '-1';
    cout<<endl;
    cout<<"\t <getToken> " <<token <<" ";
}

void SimpleParser::parse(string& inputLine, ofstream& output){
    cout<<" <parse> " <<endl;
    line = inputLine;
    index = 0;
    maxIndex = inputLine.length();
    getToken();
    //Call <exp>
    exp(output);
}

void SimpleParser::exp(ofstream& output){
    //Call <term>
    cout<<" <exp> ";
    term(output);
    while(token == '+'){
        getToken();
        //Call <term>
        term(output);
    }
}

void SimpleParser::term(ofstream& output){
    //Call <factor>
    cout<<" <term> ";
    
    factor(output);
    while(token == '*'){
        getToken();
        //Call <factor>
        factor(output);
    }
}

void SimpleParser::factor(ofstream& output){
    cout<<" <factor> ";
    if(token == '('){
        getToken();
        //Call <exp>
        exp(output);
        if(token == ')')
            getToken();
        else{}
            //ERROR!!!
    }
    else
        //Call <number>
        number(output);
}

void SimpleParser::number(ofstream& output){
    cout<<" <number> ";
    //Call <digit>
    /*
    digit(output);
    while(isDigit(token))
        digit(output);
    */
}

void SimpleParser::digit(ofstream& output){
    cout<<" <digit> ";
    if(isDigit(token) && token != '-1')
        getToken();
    else{}
        //ERROR!!!
}



