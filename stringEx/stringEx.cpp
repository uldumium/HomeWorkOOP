#include "stringEx.h"

stringEx::stringEx()
{
	stringEx::length = 1;

	stringEx::str = new char [stringEx::length];

	stringEx::str[ 0 ] = '\0';
}

stringEx::stringEx( const char* str )
{
	stringEx::length = stringEx::lengthEx( str );

	stringEx::str = new char[ stringEx::length + 1 ];

	for(int i = 0; i < stringEx::length; i++)
	{
		stringEx::str[ i ] = str[ i ];
	}

	stringEx::str[ stringEx::length] = '\0';
}

stringEx::stringEx( const stringEx& str ) //**
{
	*this = str;
}

stringEx& stringEx::operator=( const stringEx& str ) //**
{
	stringEx::clear();

	stringEx::length = str.length;

	stringEx::str = new char[ stringEx::length ];

	for(int i = 0; i < stringEx::length; i++)
	{
		stringEx::str[ i ] = str.str[ i ];
	}

	stringEx::str[ stringEx::length ] = '\0';

	return *this;
}

char& stringEx::operator[]( const int& index ) const
{
	return stringEx::str[ index ];
}

int stringEx::lengthEx( const char* str ) const
{
    int length = 0;

	for(int i = 0; '\0' != str[i]; i++)
	{
		length++;
	}

	return length;
}

void stringEx::clear()
{
	if(nullptr != stringEx::str)
	{
		delete[] stringEx::str;

		stringEx::length = 0;

		stringEx::str = nullptr;
	}
}

int stringEx::getLengthEx() const
{
	return stringEx::length;
}

std::ostream& operator<<( std::ostream& outputStream , const stringEx& str )
{
	for(int i = 0; i < str.getLengthEx(); i++)
	{
		outputStream << str[ i ];
	}
	
	return outputStream;
}

stringEx::~stringEx()
{
	stringEx::clear();
}