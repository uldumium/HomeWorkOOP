#pragma once
#include <iostream>
#include "MyFunctions.h"


class StringEx
{
public:
#pragma region Constructor and Destructor

	// ���������� �� ���������
	StringEx();

	// ����������� � ����������
	StringEx( const char* other );

	// ����������� �����������
	StringEx( const StringEx& other );

	//���������� ��� �������� ���������� ������
	virtual ~StringEx();

#pragma endregion

#pragma region Operator overloading

	// ���������� ��������� " + " - ������������
	StringEx operator+( const StringEx& right );

	// ���������� ��������� "�����"
	StringEx& operator=( const StringEx& other );

	// ���������� ��������� "<< "
	friend std::ostream& operator<<( std::ostream& outPut , const StringEx& other );

#pragma endregion

#pragma region Methods

	// ����� �������� ������ �� �������, � ��������� �� ������� ������
	void clearObj();

	// ����� �������� ������ �������� �� �����������
	StringEx* split( const char delimiter , int& count );

	// ����� ����������� ��������� � ������ � ��������� ��������
	// ��� �� ����� ������� ������� �������� ��������, ������  ������ ���-�� ����������� � �������
	void insert( const char* subArray , const int index );

	// ����� ��������� true ���� ��������� ������ � ������, ����� false
	bool contains( const char* other ) const;

#pragma endregion

private:

	// ��������� �� ������ �����
	char* str;
};

