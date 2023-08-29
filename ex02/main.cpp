#include <iostream>
#include "Array.hpp"

#define MAX_VAL 5
int main()
{
	Array<int> arrayNum(MAX_VAL);
	int* mirror = new int[MAX_VAL];
	std::cout << BLUE << "[ Test Constructor ]" << RESET << std::endl;
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = i + 42;
		arrayNum[i] = value;
		mirror[i] = value;
		std::cout << GREEN << "Array: " << arrayNum[i] << "\t\tMirror: " << mirror[i] << RESET << std::endl;
	}
	std::cout << BLUE << "[ Test Copy ]" << RESET << std::endl;
	{
		Array<int> tmp = arrayNum;
		Array<int> test;
		test = tmp;
		for (int i = 0; i < MAX_VAL; i++)
		{
			std::cout << GREEN << "CopyConstructor: " << tmp[i] << "\tCopyAssignmentOperator: " << test[i] << RESET << std::endl;
		}
	}
	std::cout << BLUE << "[ Test Error ]" << RESET << std::endl;
	try
	{
		arrayNum[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED <<  e.what() << RESET << std::endl;
	}
	try
	{
		arrayNum[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		arrayNum[i] = rand();
	}
	delete [] mirror;
	return 0;
}

__attribute((destructor))
static void destructor() {
	system("leaks -q main");
}
