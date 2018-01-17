#ifndef ARRAY_CLASS_TPP
# define ARRAY_CLASS_TPP

# include <string>
# include <iostream>

template<typename T>
class Array {

private:

	T* 			 _arr;
	unsigned int _size;

public:

	Array<T>():
	_arr(nullptr), _size(0) {}

	Array<T>(unsigned int size):
	_size(size) {

		_arr = new T[size];
	}

	Array<T>(Array const& rhs) {
		*this = rhs;
	}

	Array& operator=(Array const& rhs) {
		_size = rhs._size;
		_arr = new T[_size];

		for (int i = 0; i < _size; i++) {
			_arr[i] = rhs._arr[i];
		}
	}

	~Array<T>() {}

	unsigned int size() const {
		return _size;
	};

	T& operator[](unsigned int i) {
		if (i >= _size) {
			throw std::exception();
		}
		return _arr[i];
	}
};

#endif