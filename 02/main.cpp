#include <iostream>
#include "parser.hpp"
#include <stack>
#include<cassert>

void correct_or_callback(std::stack<std::string> check_stack, const std::string& s){
	bool check = true;
	std::stack<std::string> class_stack;
	TokenParser T;
	T.SetDigitCallback(digithandler);
	T.SetStringCallback(stringhandler);
	T.SetStartCallback(start);
	T.SetFindCallback(find);
	T.SetFinishCallback(finish);
	T.Parser("inp.txt");
	if (s == "correct") class_stack = T.check_parse;
	else if (s == "callback") class_stack = T.check_callbacks;
	while(!class_stack.empty() && !check_stack.empty() && check){
		if (class_stack.top() != check_stack.top()) check = false;
		class_stack.pop();
		check_stack.pop();
	}
	assert(check == true);
}


void no_set_test(){
	std::string st = "";
	try{
		TokenParser T;
		T.SetDigitCallback(digithandler);
		T.SetStringCallback(stringhandler);
		T.Parser();
	}
	catch (const char* s){
		st = s;
	}
	assert(st != "");

}


void change_start_test(){
	std::string st = "";
	try{
		TokenParser T;
		T.SetDigitCallback(digithandler);
		T.SetStringCallback(stringhandler);
		T.SetStartCallback(start);
		T.SetFindCallback(find);
		T.SetFinishCallback(finish);
		T.SetStartCallback(start_alternative);
		T.Parser("inp.txt");
	}
	catch (const char* s){
		st = s;
	}
	assert(st!="");
}

void check_similar_parsing(std::stack<std::string> check_stack){
	bool check = true;
	TokenParser T;
	T.SetDigitCallback(digithandler);
	T.SetStringCallback(stringhandler);
	T.SetStartCallback(start);
	T.SetFindCallback(find);
	T.SetFinishCallback(finish);
	T.Parser("inp.txt");
	TokenParser T1;
	T1.SetDigitCallback(digithandler);
	T1.SetStringCallback(stringhandler);
	T1.SetStartCallback(start);
	T1.SetFindCallback(find);
	T1.SetFinishCallback(finish);
	T1.Parser("inp1.txt");
	while(!T.check_parse.empty() && !check_stack.empty() && !T1.check_parse.empty() && check){
		if ( (T.check_parse.top() != check_stack.top()) || (T1.check_parse.top() != check_stack.top()) ) check = false;
		T.check_parse.pop();
		T1.check_parse.pop();
		check_stack.pop();
	}
	assert(check == true);
}


int main(){
	std::stack<std::string> check_stack;
	std::stack<std::string> check_cor_calback;
	check_stack.push("my");
	check_stack.push("new11file22");
	check_stack.push("is");
	check_stack.push("here");
	check_stack.push("21");
	check_stack.push("34input");
	check_stack.push("...");
	check_stack.push("for");
	check_cor_calback.push("str");
	check_cor_calback.push("str");
	check_cor_calback.push("str");
	check_cor_calback.push("str");
	check_cor_calback.push("dig");
	check_cor_calback.push("str");
	check_cor_calback.push("str");
	check_cor_calback.push("str");
	try{
		correct_or_callback(check_stack,"correct");
		no_set_test();
		change_start_test();
		check_similar_parsing(check_stack);
		correct_or_callback(check_cor_calback,"callback");//Проверка на вызов корректного коллбэка под токен.
	}
	catch(const char* s){
		std :: cout<<s<< std::endl;
		return 0;
	}
	std::cout<<"Successfully passed all tests!" << std::endl;
	return 0;
}