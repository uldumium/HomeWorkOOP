#pragma once
#include "MyFuncttion.h"

#define MAX_MARKS 3
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

	// ���� �������� �����, �� ������������� ������� ���������� ��������������
	void setMarks();
	void setMarks( int a , int b , int c );

#pragma endregion
#pragma region GETTERS

	// ��������� ���
	std::string getName();

	// ��������� �������
	std::string getSurName();

#pragma endregion

#pragma region internalFunctionality
	
	// ����� ��������
	void printStudent();

	// ����� ������ ��������
	void printStudentMarks();

#pragma region
private:
	// ��� ��������
	std::string name;

	// ������� ��������
	std::string surName;

	// ������� ������
	int marks[ MAX_MARKS ];

};

