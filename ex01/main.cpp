#include "Iter.hpp"

int main(void)
{
	std::cout << BLUE << "[ Test Int ]" << RESET << std::endl;
	int i[] = {42, 43, 44, 45, 46};
	size_t size = sizeof(i) / sizeof(int);
	iter(i, size, printElement<int>);

	std::cout << BLUE << "[ Test Double ]" << RESET << std::endl;
	double d[] = {42.42, 43.42, 44.42, 45.42, 46.42};
	size = sizeof(d) / sizeof(double);
	iter(d, size, printElement<double>);

	std::cout << BLUE << "[ Test String ]" << RESET << std::endl;
	std::string s[] = {"I", "love", "42", "Tokyo", "!!"};
	size = sizeof(s) / sizeof(std::string);
	iter(s, size, printElement<std::string>);

	return 0;
}
