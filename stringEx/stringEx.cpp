#include "stringEx.h"
#include "MyFunction.h"

stringEx::stringEx()
{
	stringEx::length = 1;

	stringEx::str = new char [stringEx::length];

	stringEx::str[ 0 ] = '\0';
}

stringEx::stringEx( const char* str )
{
	stringEx::length = LengthEx( str );

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
	stringEx::deleteInfo();

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

char stringEx::getStr( int index ) const
{
	return stringEx::str[ index ];
}

stringEx* stringEx::split( const char delimiter ) const //*
{
	// Счетчик слов в нашей строкеEx
	int counterDelimiter = 1;
	for(int i = 0; i < stringEx::length; i++)
	{
		if(delimiter == stringEx::str[ i ])
			++counterDelimiter;
	}
	stringEx* subArray = new stringEx[ counterDelimiter ];

	for(int i = 0, j = 0, k = 0; i < stringEx::length; i++)
	{
		if(delimiter != stringEx::str[ i ])
		{
			subArray[ j ].str[ k++ ] = stringEx::str[ i ];
		}
		else
		{
			subArray[ j++ ].str[ k ] = '\0';
			subArray->length = k;
			k = 0;
		}
	}

	return subArray;
}

void stringEx::deleteInfo()
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

//stringEx::~stringEx()
//{
//	stringEx::deleteInfo();
//}