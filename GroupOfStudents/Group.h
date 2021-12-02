#pragma once
#include "Item.h"
#include "MyFuncttion.h"
#include "Student.h"

// ������ ������
#define MAX_SIZE_GROUP_STUDENTS 16

// ���������� ���������
#define MAX_SIZE_VALUE_ITEM 16


class Group
{
public:
	
	// ����������� �� ���������
	Group();

	// ����������� ������ ���������
	void printGroupStudent();

	void printItems();

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
	Student* studentList[MAX_SIZE_GROUP_STUDENTS];

	// ������ ���������
	Item* itemList[MAX_SIZE_VALUE_ITEM];
};

