#pragma once
#include "Item.h"
#include "MyFuncttion.h"
#include "Student.h"

// ������ ������
#define MAX_SIZE_GROUP_STUDENTS 8

// ���������� ���������
#define MAX_SIZE_VALUE_ITEM 7


class Group
{
public:
	
	// ����������� �� ���������
	Group();

	// ����������� ����� ������� �������� ������� ��������� �� ��������� � �� ������
	static void studentsGradesBySubject( Group p );


#pragma region SETTERS

	// ������������� ����� ������
	void setNameGroup(std::string name);

	// ������������� ��������� ������ (���, �������, ������)
	void fillStudentList();

#pragma endregion


private:
	// ��������(���) ������
	std::string nameGroup;

	// ������ ���������
	Student studentList[MAX_SIZE_GROUP_STUDENTS];

	// ������ ���������
	Item itemList[MAX_SIZE_VALUE_ITEM];

	// ��������� �������
	std::string printItems( int a );

	// ����� � ������� ������ ��������
	void printMarksStudentsGroup( int a );

#pragma region GETTERS

// ��������� ��� ��������
	std::string getNameStudentGroup( int a );

	// ��������� ������� ��������
	std::string getSurnameStudentGroup( int a );

#pragma endregion
};

