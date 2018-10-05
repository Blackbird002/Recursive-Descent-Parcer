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

void SimpleParser::getToken(){
    if(index < maxIndex){
        token = line[index];
        ++index;
        cout<<endl;
        cout<<"\t <getToken> " <<token <<" ";
    }
    else
        //Flag to end parcing
        end = true;

}

void SimpleParser::parse(string& inputLine, ofstream& output){
    cout<<" <parse> ";

    //Reset the data for another parse
    end = false;
    error = false;
    line = inputLine;
    index = 0;
    maxIndex = inputLine.length();

    getToken();
    //Call <exp>
    exp(output);

    if(end){
        cout<<endl;
        if(error)
            cout<<"Error! \n";
        else
            cout<<"This expression parsed with NO errors! \n";
    }

}

void SimpleParser::exp(ofstream& output){
    //Call <term>
    cout<<" <exp> ";
    term(output);
    while(token == '+' && end != true){
        getToken();
        //Call <term>
        term(output);
    }
}

void SimpleParser::term(ofstream& output){
    //Call <factor>
    cout<<" <term> ";

    factor(output);
    while(token == '*' && end != true){
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
        else{
            //ERROR!!!
            error = true;
            end = true;
            cout<<"ERROR! \n";
        }
    }
    else
        //Call <number>
        number(output);
}

void SimpleParser::number(ofstream& output){
    cout<<" <number> ";
    //Call <digit>
    digit(output);
    while(isDigit(token) && end != true)
        digit(output);
}

void SimpleParser::digit(ofstream& output){
    cout<<" <digit> ";
    if(isDigit(token) && end != true)
        getToken();
    else{
        end = true;
        error = true;
        cout<<"Error!\n";
    }
}
