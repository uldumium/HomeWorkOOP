#pragma once
#include "MyFuncttion.h"

#define MAX_MARKS 5
#define MAX_COUNT_ITEMS 7

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

	// Инициализация массива происходит псевдорандомом в заданом диапазоне от 2 до 5
	void setMarks();
	void setMarks(int a);

#pragma endregion
#pragma region GETTERS

	// Возращает имя
	std::string getName();

	// Возращает Фамилию
	std::string getSurName();

	// Возращает определенную оценку студента
	// где [a] - номер студента [b] - номер его оценки в массиве
	int getGrade( int a , int b );

#pragma endregion

#pragma region internalFunctionality
	
	// Вывод в консоль студента
	void printStudent();

	// Вывод в консоль оценок студента
	void printStudentMarks(int a);

	static void printStudentMarks(Student a);

#pragma region
private:
	// Имя студента
	std::string name;

	// Фамилия студента
	std::string surName;

	// Массивы оценок
	int marks[ MAX_COUNT_ITEMS ][MAX_MARKS];

};

