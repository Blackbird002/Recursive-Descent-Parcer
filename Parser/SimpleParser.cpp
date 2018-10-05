#include "SimpleParser.h"

SimpleParser::SimpleParser(){
    index = 0;
    token = ' ';
    line = "";
    end = false;
    error = false;
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

void SimpleParser::getToken(ofstream& output){
    if(index < maxIndex){
        token = line[index];
        ++index;
        output<<endl;
        output<<"  → <getToken> " <<token <<" ";
    }
    else
        //Flag to end parcing
        end = true;

}

void SimpleParser::parse(string& inputLine, ofstream& output){
    output<<" <parse> ";

    //Reset the data for another parse
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
        if(error)
            output<<"Error! \n";
        else
            output<<"This expression parsed with NO errors! \n";
    }

}

void SimpleParser::exp(ofstream& output){
    //Call <term>
    output<<" <exp> ";
    term(output);
    while(token == '+' && end != true){
        getToken(output);
        //Call <term>
        term(output);
    }
}

void SimpleParser::term(ofstream& output){
    //Call <factor>
    output<<" <term> ";

    factor(output);
    while(token == '*' && end != true){
        getToken(output);
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
            //ERROR!!!
            error = true;
            end = true;
            output<<"ERROR! \n";
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
        end = true;
        error = true;
        output<<"Error!\n";
    }
}
