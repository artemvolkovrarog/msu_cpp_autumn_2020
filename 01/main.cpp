#include <iostream>
#include "Allocator.hpp"
void test1(){//Тест 1: без ошибок, разными способами выделяем память, также используем reset, alloc работает корректно
	std::cout << "Test 1\n";
	Allocator a;
	a.makeallocator(1024);
	a.alloc(512);
	a.alloc(256);
	a.alloc(256);
	a.reset();
	a.alloc(728);
	a.alloc(296);
}

void test2(){
//Тест 2: два  предупреждения при вызове методов reset и  alloc неинициализированного аллокатора, ошибка при запросе выделений памяти,
// выходящих за пределы выделенного объема памяти
	std::cout << "Test 2\n";
	Allocator b;
	b.alloc(2048);
	b.reset();
	b.makeallocator(4096);
	for (int i = 0; i < 4; i++){
		b.alloc(1024);
	}
	b.alloc(1);
}

void test3(){//Тест 3: ошибка при создании аллокатора памяти по отрицательному размеру
	std::cout << "Test3\n";
	Allocator c;
	c.makeallocator(-2048);
}
void test4(){// Тест 4: ошибки при запросе выделения блока памяти размера 0, а так же при запросе на выделение блока
	//по отрицательному числу
	std::cout << "Test4\n";
	Allocator d;
	d.makeallocator(8192);
	d.alloc(0);
	d.alloc(-12);
	
}


int main(){
	test1();
	test2();
	test3();
	test4();
	return 0;
}