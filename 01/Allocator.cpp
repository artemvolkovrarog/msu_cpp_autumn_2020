#include "Allocator.hpp"
#include <iostream>
void Allocator::makeallocator(std::size_t max_size){
	try{
		if (check_alloc == false){
			head = new char[max_size];
			check_alloc = true;
		}
		else{
			std::cout << "Warning, memory has already been allocated\n";
		}
	}
	catch(...){
		std::cout<< "Error while creating allocator\n"; 
		head = nullptr;
		return;
	}
	offset = 0;
	block_size = max_size;
	return;
}

char* Allocator::alloc(std::size_t size){
	try{
		if (size == 0){
			throw("Error, size equals zero\n");
		}
		else if(check_alloc == false){
			throw("Warning, memory hasn't been allocated yet\n");
		}
		else if (size * sizeof(char)  > block_size - offset) {
			throw ("Error while allocating memory, size exceeds limits\n");
		}
	}
	catch(const char* s){
		std::cout << s;
		return nullptr;

	}
	char* ret_offset = head + offset * sizeof(char);
	offset = offset + sizeof(char) * size;
	return ret_offset; 
}

void Allocator:: reset(){
	if (check_alloc == false){
		std::cout << "Warning, memory hasn't been allocated yet\n";
	}
	offset = 0;
}