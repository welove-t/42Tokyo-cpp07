#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <class T>
class Array
{
	private:
		T*				_array;
		unsigned int	_size;

	public:
		Array() : _array(new T()), _size(0){
			std::cout << "(Array) Default Constructor called" << std::endl;
		};
		Array(unsigned int n) : _array(new T[n]), _size(n){
			std::cout << "(Array) Constructor called" << std::endl;
		};

		Array(const Array& rhs) : _array(new T[rhs._size]), _size(rhs._size){
			std::cout << "(Array) Copy Constructor called" << std::endl;
			for (unsigned int i = 0; i < rhs._size; i++)
				_array[i] = rhs._array[i];
		};

		~Array(){
			delete [] _array;
			std::cout << "(Array) Destructor called" << std::endl;
		};
		Array& operator=(const Array& rhs){
			std::cout << "(Array) Copy assignment operator called" << std::endl;
			if (this != &rhs)
			{
				delete []_array;
				_array = new T[rhs._size];
				for (unsigned int i = 0; i < rhs._size; i++)
					_array[i] = rhs._array[i];
			}
			return *this;
		};

		T& operator[](unsigned int i){
			if (i >= _size)
				throw std::runtime_error("Array out of bounds!");
			return _array[i];
		};
		unsigned int	size() const {return _size;};
};

#endif
