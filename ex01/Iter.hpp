#include <iostream>

#define RED		"\e[0;31m" // Red
#define GREEN	"\e[0;32m" // Green
#define YELLOW	"\e[0;33m" // Yellow
#define BLUE	"\e[0;34m" // Blue
#define RESET 	"\e[0m"    // Reset

template <typename A, typename F>
void	iter(A array, size_t size, F func)
{
	for (size_t i = 0; i < size; i++)
		func(array[i]);
}

template <typename T >
void	printElement(T element)
{
	std::cout << element << std::endl;
}
