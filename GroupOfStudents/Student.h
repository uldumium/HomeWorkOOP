#pragma once
#include "MyFuncttion.h"

#define MAX_MARKS 5
#define MAX_COUNT_ITEMS 7

class Student
{	
public:
	// ����������� �� ��������� 
	Student();
#pragma region SETTERS

	// �������������� ���
	void setName( std::string name );

	// �������������� �������
	void setSurName( std::string surName );

	// ������������� ������� ���������� �������������� � ������� ��������� �� 2 �� 5
	void setMarks();
	void setMarks(int a);

#pragma endregion
#pragma region GETTERS

	// ��������� ���
	std::string getName();

	// ��������� �������
	std::string getSurName();

	// ��������� ������������ ������ ��������
	// ��� [a] - ����� �������� [b] - ����� ��� ������ � �������
	int getGrade( int a , int b );

#pragma endregion

#pragma region internalFunctionality
	
	// ����� � ������� ��������
	void printStudent();

	// ����� � ������� ������ ��������
	void printStudentMarks(int a);

#pragma region
private:
	// ��� ��������
	std::string name;

	// ������� ��������
	std::string surName;

	// ������� ������
	int marks[ MAX_COUNT_ITEMS ][MAX_MARKS];

};

