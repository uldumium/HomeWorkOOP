﻿#pragma once
#include <iostream>

class stringEx
{
public:

#pragma region Constructors

	// Конструктор по умолчанию
	stringEx();

	// Конструктор с параметром
	stringEx( const char* str );


	// Конструктор копирования
	stringEx( const stringEx& str );

#pragma endregion

#pragma region Operator overloading
	
	// Перегрузка оператора равно
	stringEx& operator= ( const stringEx& str );

	// Перегрузка оператора []
	char& operator[] ( const int& index ) const;

	// Перегрузка оператора <<
	friend std::ostream& operator<< ( std::ostream& outputStream , const stringEx& str );

#pragma endregion

#pragma region GETTERS

	char getStr( int index )const;

#pragma endregion

#pragma region Methods

	stringEx* split( const char delimiter ) const;

#pragma endregion

	void deleteInfo();

	int getLengthEx() const;

	// Деструктор класса
	//~stringEx();

private:

	// Динамический массив чаров
	char* str;

	// Длина массива
	int length;

};

