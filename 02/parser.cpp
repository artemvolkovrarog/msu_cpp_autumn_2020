#include <iostream>
#include "parser.hpp"
#include <stack>
#include<fstream>

std::string start(const std::string& st){
	std :: cout << "Hello, let's parse!" << std::endl;
	if (st == "INPFILE"){
		std :: cout << "Please, enter the name of input - file" << std :: endl;
		std::string s;
		std :: cin >> s;
		return s;
	}
	else return st;
}

void finish(){
	std::cout << "Parsing is finished" << std::endl << std::endl;
}

void find(const std::string& s){
	std :: cout << "New token was found !" << std::endl << "The type if token - " << s << std::endl;
}

void stringhandler(std::string s){
	std :: cout << "String - token: " << s << std::endl;
}

void digithandler(std::string s){
	std :: cout << "Int - token: "<< stoi(s) << std::endl;
}

std::string start_alternative(const std::string& st){
	return("NOFILE");
}

void TokenParser::SetDigitCallback(DigitMaintan  dig){
	digprs = dig;
}

void TokenParser::SetStringCallback(StringMaintain st){
	strprs = st;
}

void TokenParser::SetStartCallback(StartCallback stcb){
	start = stcb;
}
void TokenParser::SetFindCallback(FindCallback fcb){
	find = fcb;
}
void TokenParser::SetFinishCallback(FinishCallback fscb){
	finish = fscb;
}


void TokenParser::Parser(const std::string & s) {
	bool inp_digit = false;
	bool token_inp = false;
	bool inp_str = false;
	if ((strprs == nullptr) || (start == nullptr) || (digprs == nullptr) || (find == nullptr) || (finish == nullptr)){
		throw "Error, one or several funcion(-s) was(-were)n't set";
	}
	std :: string fnm;
	fnm = start(s);
	char* fnmc = new char[fnm.length()+1];

	for (int i = 0; i< fnm.length(); i++){
		fnmc[i] = fnm[i];
	}
	fnmc[fnm.length()] = '\0';

	file.open(fnmc);

	if (!file.is_open()){
		throw ("Error while opening the file");
	}

	char c;
	while(1){
		c = file.get();
		if (file.eof()){
			if (token_inp){
				check_parse.push(token);
				if (inp_str){
					find("string");
					strprs(token);
					token.clear();
				}
				else if (inp_digit){
					find("digit");
					digprs(token);
					token.clear();
				}
			}
			break;
		}
		else if ((c >= '0') && (c <= '9')){
			if (!token_inp) token_inp = true;
			if (!inp_digit) inp_digit = true;
			token.push_back(c);

		}
		else if (isspace(c)){
			if(token_inp){
				check_parse.push(token);
				token_inp = false;
			}
			if (inp_str){
				find("string");
				strprs(token);
				token.clear();
				inp_str = false;
				inp_digit = false;
				token_inp = false;
			}
			else if (inp_digit){
				find("digit");
				digprs(token);
				token.clear();
				inp_str = false;
				inp_digit = false;
				token_inp = false;

			}
		}
		else{
			if (!token_inp) token_inp = true;
			if (!inp_str) inp_str = true;
			token.push_back(c);
		}
	}
	finish();
	file.close();
}