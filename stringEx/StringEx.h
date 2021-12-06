﻿#pragma once
#include <iostream>
#include "MyFunctions.h"


class StringEx
{
public:
#pragma region Constructor and Destructor

	// Консруктор по умолчанию
	StringEx();

	// Конструктор с параметром
	StringEx(const char* other);

	// Конструктор копирования
	StringEx( const StringEx& other );

	//Деструктор для удаления диначеских данных
	~StringEx();

#pragma endregion

#pragma region Operator overloading

	// Перегрузка оператора " + " - Конкатинация
	StringEx operator+( const StringEx& right );

	// Перегрузка оператора "равно"
	StringEx& operator=( const StringEx& other );

	// Перегрузка оператора "!="
	bool operator!=( const char other );

	// Перегрузка оператора "<< "
	friend std::ostream& operator<<( std::ostream& outPut , const StringEx& other );

#pragma endregion

#pragma region Methods

	// Метод удаления данных из объекта, с проверкой на наличие данных
	void clearObj();

	// Метод возращат массив объектов по разделителю
	StringEx* split( const char delimiter);

	char* getStr() const;

#pragma endregion

private:

	// Указатель на массив чаров
	char *str;
};

