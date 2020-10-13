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
			throw(1);
		}
	}
	catch(std::bad_alloc ba){
		head = nullptr;
		std::cout << "Error while allocating memory\n";
		throw(1);
	}
	offset = 0;
	block_size = max_size;
	return;
}

char* Allocator::alloc(std::size_t size){
	if (size == 0){
		std::cout << "Error, size equals zero\n";
		return nullptr;
	}
	else if(check_alloc == false){
		std::cout << "Error, memory hasn't been allocated yet\n";
		return nullptr;
	}
	else if (size * sizeof(char)  > block_size - offset) {
		std::cout << "Error while allocating memory, size exceeds limits\n";
		return nullptr;
	}
	char* ret_offset = head + offset * sizeof(char);
	offset = offset + sizeof(char) * size;
	return ret_offset; 
}

void Allocator:: reset(){
	offset = 0;
}