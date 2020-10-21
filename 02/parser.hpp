#include <iostream>
#include <stack>
#include<fstream>
#pragma once

std::string start(const std::string& );
std::string start_alternative(const std::string& );
void finish();
void find(const std::string& s);
void stringhandler(std::string s);
void digithandler(std::string s);

typedef void (*DigitMaintan)(std::string);
typedef void (*StringMaintain)(std::string);
typedef std::string (*StartCallback)(const std::string&);
typedef void (*FindCallback)(const std::string&);
typedef void (*FinishCallback)();


class TokenParser{
	DigitMaintan digprs;
	StringMaintain strprs;
	StartCallback start;
	FindCallback find;
	FinishCallback finish;
	std::ifstream file;
	std::string token;

	public:
		std::stack <std::string> check_parse; 
		TokenParser(){
			digprs= nullptr;
			strprs = nullptr;
			start = nullptr;
			find = nullptr;
			finish = nullptr;		
		}
		void SetDigitCallback(DigitMaintan);
		void SetStringCallback(StringMaintain);
		void SetStartCallback(StartCallback);
		void SetFindCallback(FindCallback);
		void SetFinishCallback(FinishCallback);
		void Parser(const std::string & s = "INPFILE");

};