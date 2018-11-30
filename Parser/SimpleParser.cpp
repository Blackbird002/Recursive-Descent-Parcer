/*
Riad Shash (Ray)
CSCI 330
HW#3
*/

#include "SimpleParser.h"

//Default Constructor
SimpleParser::SimpleParser(){
    index = 0;
    token = ' ';
    line = "";
    end = false;
    error = false;
}

//Determines if a character is a digit
const bool SimpleParser::isDigit(char& inputToken) const{
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

//Destructor
SimpleParser::~SimpleParser(){};

void SimpleParser::getToken(ofstream& output){
    if(index < maxIndex){
        token = line[index];

        output<<endl;

        //Checks if first token is illegal in expression
        if(index == 0 && !isDigit(token) && token != '(')
            error = true;
          
        output<<"  → <getToken> " <<token <<" ";
        ++index;
    }
    else{
        //Flag to end parsing - end of expression
        end = true;

        if(token == '+' || token == '*'){
            output<<endl;
            output<<"  → <getToken> ";
        }
    }
}

void SimpleParser::parse(string& inputLine, ofstream& output){
    output<<" <parse> ";

    //Reset variables for another parse
    end = false;
    error = false;
    line = inputLine;
    index = 0;
    maxIndex = inputLine.length();

    getToken(output);

    //Call <exp>
    exp(output);

    if(end){
        output<<endl;
        if(!error)
            output<<"This expression parsed with NO errors! \n";
    }

}

void SimpleParser::exp(ofstream& output){
    if(!error){
        //Call <term>
        output<<" <exp> ";
        term(output);
        while(token == '+' && end != true){
            getToken(output);
            if(!isDigit(token) && token != '('){
                error = true;
                output<<"\nERROR! Expected a digit or '(' token!\n";
                return;
            }
            //Call <term>
            term(output);
        }
    }
    else{
        //This runs if the starting token is illegal
        end = true;
		error = true;
        output<<"\nERROR! Expected a digit or '(' token!\n";
    }
}

void SimpleParser::term(ofstream& output){
    //Call <factor>
    output<<" <term> ";

    factor(output);
    while(token == '*' && end != true){
        getToken(output);

        if(!isDigit(token) && token != '('){
            error = true;
            output<<"\nERROR! Expected a digit or '(' token!\n";
            return;
        }
        //Call <factor>
        factor(output);
    }
}

void SimpleParser::factor(ofstream& output){
    output<<" <factor> ";
    if(token == '('){
        getToken(output);
        //Call <exp>
        exp(output);
        if(token == ')')
            getToken(output);
        else{
            //ERROR
            error = true;
            end = true;
            output<<"ERROR! \n";
            output<<"Error! Expected ')' token!\n";
        }
    }
    else
        //Call <number>
        number(output);
}

void SimpleParser::number(ofstream& output){
    output<<" <number> ";
    //Call <digit>
    digit(output);
    while(isDigit(token) && end != true)
        digit(output);
}

void SimpleParser::digit(ofstream& output){
    output<<" <digit> ";
    if(isDigit(token) && end != true)
        getToken(output);
    else{
		//ERROR
        end = true;
        error = true;
        output<<"ERROR! \n";
        output<<"ERROR! Expected a digit token!\n";
    }
}