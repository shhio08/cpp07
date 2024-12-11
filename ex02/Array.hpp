#pragma once

template <typename T>
class Array
{
private:
	T* _data;
	unsigned int _size;

public:
	Array();
	Array(unsigned int n);
	Array(const Array<T>& other);
	~Array();
	Array& operator=(const Array<T>& other);
	T& operator[](unsigned int i);
	const T& operator[](unsigned int i) const;
	unsigned int size() const;
};

// classを宣言した後に定義をinclude
#include "Array.tpp"