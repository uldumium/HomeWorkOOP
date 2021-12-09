#pragma once
#include <iostream>
#include "MyFunctions.h"


class StringEx
{
public:
#pragma region Constructor and Destructor

	// Консруктор по умолчанию
	StringEx();

	// Конструктор с параметром
	StringEx( const char* other );

	// Конструктор копирования
	StringEx( const StringEx& other );

	//Деструктор для удаления диначеских данных
	virtual ~StringEx();

#pragma endregion

#pragma region Operator overloading

	// Перегрузка оператора " + " - Конкатинация
	StringEx operator+( const StringEx& right );

	// Перегрузка оператора "равно"
	StringEx& operator=( const StringEx& other );

	// Перегрузка оператора "<< "
	friend std::ostream& operator<<( std::ostream& outPut , const StringEx& other );

	// Перегрезука оператора "[]"
	char operator[]( const int index );

	// Перегрузка оператора "=="
	friend bool operator==( const StringEx& left, const StringEx& right );
	static void comparison( const StringEx& left , const StringEx& right );

	// Перегрузка оператора "+=", копирует объект в самого себя
	StringEx operator+=( const StringEx& right );

	// Перегрузка метода contains оператором "-"
	void operator-( const StringEx& right );

	// Перегрузка оператора "/", который разделит строку на подстроки (раздлителем) и сразу их выведет в консоль
	void operator/( const char delimiter);

#pragma endregion

#pragma region Methods

	// Метод удаления данных из объекта, с проверкой на наличие данных
	void clearObj();

	// Метод возращат массив объектов по разделителю
	StringEx* split( const char delimiter , int& count );

	// Метод вставляющий подстроку в строку в заданному элементу
	// так же нужно указать интовое значения счетчика, котрый  вернет кол-во подмассивов в массиве
	void insert( const char* subArray , const int index );

	// Метод возращает true если подстрока входит в строку, иначе false
	bool contains( const char* other ) const;

	// Возращает длину строки
	int size() const;

	// Возращает true если объект не пуст, иначе false
	bool isEmpty() const;

#pragma endregion

private:

	// Указатель на массив чаров
	char* str;
};

