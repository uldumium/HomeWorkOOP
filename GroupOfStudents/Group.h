﻿#pragma once
#include "Item.h"
#include "MyFuncttion.h"
#include "Student.h"

// Размер группы
#define MAX_SIZE_GROUP_STUDENTS 8

// Количество предметов
#define MAX_SIZE_VALUE_ITEM 7


class Group
{
public:
	
	// Конструктор по умолчанию
	Group();

	// Статический метод который печатает таблицу студентов по предметах и их оценки
	static void studentsGradesBySubject( Group p );

	// Выводи на экран средний балл студентов
	static void averageScoreOfStudents( Group p );


#pragma region SETTERS

	// Инициализация имени группы
	void setNameGroup(std::string name);

	// Инициализация студентов группы (имя, фамилия, оценки)
	void fillStudentList();

#pragma endregion


private:
	// Название(имя) группы
	std::string nameGroup;

	// Список студентов
	Student studentList[MAX_SIZE_GROUP_STUDENTS];

	// Список предметов
	Item itemList[MAX_SIZE_VALUE_ITEM];

	// Возращает предмет
	std::string printItems( int a );

	// Вывод в консоль оценки студента
	void printMarksStudentsGroup( int a );

#pragma region GETTERS

// Возращает имя студента
	std::string getNameStudentGroup( int a );

	// Возращает фамилию студента
	std::string getSurnameStudentGroup( int a );

#pragma endregion
};

