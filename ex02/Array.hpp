#ifndef ARRAY_HPP
#define ARRAY_HPP

#include "iostream"

template <class T>
class Array
{
	private:
		T*				_array;
		unsigned int	_size;

	public:
		Array() : _array(new T()), _size(0){};
		Array(unsigned int n) : _array(new T[n]), _size(n){};

		Array(const Array& rhs) : _array(new T[rhs._size]), _size(rhs._size){
			for (unsigned int i = 0; i < rhs._size; i++)
				_array[i] = rhs._array[i];
		};
		Array& operator=(const Array& rhs){
			if (this != rhs)
			{
				delete []_array;
				_array = new T[rhs._size];
				for (unsigned int i = 0; i < rhs._size; i++)
					_array[i] = rhs._array[i];
			}
			return *this;
		};

		T& operator[](unsigned int i){
			return _array[i];
		};
		unsigned int	size(){return _size;};
};

#endif
