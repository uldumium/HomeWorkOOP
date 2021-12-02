#pragma once
#include "MyFuncttion.h"

#define MAX_MARKS 3
class Student
{	
public:
	// Конструктор по умолчанию 
	Student();
#pragma region SETTERS

	// Инициализируем Имя
	void setName( std::string name );

	// Инициализируем Фамилию
	void setSurName( std::string surName );

	// Если вызываем метод, то инициализация массива происходит псевдорандомом
	void setMarks();
	void setMarks( int a , int b , int c );

#pragma endregion
#pragma region GETTERS

	// Возращает имя
	std::string getName();

	// Возращает Фамилию
	std::string getSurName();

#pragma endregion

#pragma region internalFunctionality
	
	// Вывод студента
	void printStudent();

	// Вывод оценок студента
	void printStudentMarks();

#pragma region
private:
	// Имя студента
	std::string name;

	// Фамилия студента
	std::string surName;

	// Массивы оценок
	int marks[ MAX_MARKS ];

};

