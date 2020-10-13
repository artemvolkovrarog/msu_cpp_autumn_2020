#include <iostream>
#include "Allocator.hpp"
#include <cassert>


void allcorrect(){
	Allocator a;
	a.makeallocator(4096);
	char* ptr_test1 = a.alloc(2048);
	char* ptr_test2 = a.alloc(1024);
	char* ptr_test3 = a.alloc(999);
	char*ptr_test4 = a.alloc(25);
	a.reset();
	int offset = a.getofs();
	assert(ptr_test4 != nullptr && ptr_test3 != nullptr && ptr_test2 != nullptr && ptr_test1 != nullptr && offset == 0);
	std :: cout << "Test is passed\n";
}

void incorrectallocsize(){
	Allocator b;
	b.makeallocator(2048);
	char* ptr_test1 = b.alloc(2050);
	char* ptr_test2 = b.alloc(0);
	char* ptr_test3 = b.alloc(-1);
	assert(ptr_test1 == nullptr && ptr_test2 == nullptr && ptr_test3 == nullptr);
	std :: cout << "Test is passed\n";
}

void incorrectmakealloc(){
	Allocator c;
	int checkerr = 0;
	try{
		c.makeallocator(10000000000000000);
	}
	catch(int i){
		checkerr = i;
	}
	assert(checkerr != 0 && c.gethead() == nullptr);
	std :: cout << "Test is passed\n";
}

void doublemakealloc(){
	Allocator d;
	int checkerr = 0;
	int offset1;
	int offset2;
	try{
		d.makeallocator(2048);
		d.alloc(1024);
		offset1 = d.getofs();
		d.makeallocator(2046);
	}
	catch(int i){
		checkerr = i;
	}
	offset2 = d.getofs();
	assert(checkerr != 0 && (offset2 == offset1));
	std :: cout << "Test is passed\n"; 


}

int main(){
	allcorrect();
	incorrectallocsize();
	incorrectmakealloc();
	doublemakealloc();
	std::cout << "All tests were passed, congratulations!\n";
	return 0;
}