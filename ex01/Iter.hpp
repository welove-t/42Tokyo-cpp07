#include <iostream>

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
