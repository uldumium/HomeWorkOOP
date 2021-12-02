#pragma once
#include "Item.h"
#include "MyFuncttion.h"
#include "Student.h"

// Размер группы
#define MAX_SIZE_GROUP_STUDENTS 16

// Количество предметов
#define MAX_SIZE_VALUE_ITEM 16


class Group
{
public:
	
	// Конструктор по умолчанию
	Group();

	// Отображение группы студентов
	void printGroupStudent();

	void printItems();

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
	Student* studentList[MAX_SIZE_GROUP_STUDENTS];

	// Список предметов
	Item* itemList[MAX_SIZE_VALUE_ITEM];
};

