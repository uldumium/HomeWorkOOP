#pragma once
#include "Item.h"
#include "MyFuncttion.h"
#include "Student.h"

// Размер группы
#define MAX_SIZE_GROUP_STUDENTS 7

// Количество предметов
#define MAX_SIZE_VALUE_ITEM 7


class Group
{
public:
	
	// Конструктор по умолчанию
	Group();

	// Средние оценки по предметам
	static void studentsGradesBySubject( Group p );

	// Выводи на экран средний балл студентов
	static void averageScoreOfStudents( Group p );

	// Статический метод который печатает таблицу студентов по предметах и их оценки
	static void averageGradesInSubjects( Group p );

	// Средний балл группы
	static void groupAverageScore( Group p );

	// Минимальные и максимальные оценки студентов с выводом ФИ и предмета
	static void minimumAndMaximumGrades( Group p );


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

#pragma region GETTERS

// Возращает имя студента
	std::string getNameStudentGroup( int a );

	// Возращает фамилию студента
	std::string getSurnameStudentGroup( int a );

#pragma endregion
};

